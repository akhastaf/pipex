#include "../include/pipex.h"

void    setup(t_pipex *pipex)
{
    pipex->cmd[0].in = open(pipex->cmd[0].file, O_RDONLY, S_IRWXU);
    pipex->cmd[1].out = open(pipex->cmd[1].file,  O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
}

void    execute(t_pipex *pipex)
{
    setup (pipex);
    pipe(pipex->pipe);
    pipex->pid1 = fork();
    if (!pipex->pid1)
    {
        dup2(pipex->cmd[0].in, 0);
        dup2(pipex->pipe[1], 1);
        close(pipex->cmd[1].out);
        close(pipex->pipe[0]);
        close(pipex->pipe[1]);
        if (execve(pipex->cmd[0].bin, pipex->cmd[0].arg, pipex->env))
        {
            perror("fatal error");
            exit(0);
        }
    }
    pipex->pid2 = fork();
    if (!pipex->pid2)
    {
        dup2(pipex->cmd[1].out, 1);
        dup2(pipex->pipe[0], 0);
        close(pipex->cmd[0].in);
        close(pipex->pipe[0]);
        close(pipex->pipe[1]);
        if (execve(pipex->cmd[1].bin, pipex->cmd[1].arg, pipex->env))
        {
            perror("fatal error");
            exit(0);
        }
    }
    close(pipex->pipe[0]);
    close(pipex->pipe[1]);
    waitpid(pipex->pid1, &(pipex->stratus), 0);
    waitpid(pipex->pid2, &(pipex->stratus), 0);
}
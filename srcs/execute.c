#include "../include/pipex.h"

void    setup_in(t_pipex *pipex)
{
    pipex->in = open(pipex->filein, O_RDONLY, S_IRWXU);
    dup2(pipex->in, 0);
}

void    setup_out(t_pipex *pipex)
{
    pipex->out = open(pipex->fileout, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    dup2(pipex->out, 1);
}

void    open_pipe(t_list *cmd)
{
    t_list *tmp;
    int     l;

    tmp = cmd;
    l = ft_lstsize(tmp);
	while (tmp && l >= 2)
	{
		if (tmp->next)
			pipe(((t_cmd *)tmp->data)->pipe);
		tmp = tmp->next;
	}
}

void	close_pipe(t_list *cmd)
{
	t_list	*tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->next)
		{
			close(((t_cmd *)tmp->data)->pipe[0]);
			close(((t_cmd *)tmp->data)->pipe[1]);
		}
		tmp = tmp->next;
	}
}

void    setup_pipe(t_list *cmd)
{
    if (cmd->next)
	{
		dup2(((t_cmd *)cmd->data)->pipe[1], 1);
		close(((t_cmd *)cmd->data)->pipe[1]);
		close(((t_cmd *)cmd->data)->pipe[0]);
	}
	if (cmd->prev && cmd->next)
	{
		dup2(((t_cmd *)cmd->prev->data)->pipe[0], 0);
		close(((t_cmd *)cmd->prev->data)->pipe[0]);
		close(((t_cmd *)cmd->prev->data)->pipe[1]);
	}
	if (cmd->prev && !cmd->next)
	{
		dup2(((t_cmd *)cmd->prev->data)->pipe[0], 0);
		close(((t_cmd *)cmd->prev->data)->pipe[0]);
	}
}

void    execute(t_pipex *pipex)
{
   t_list   *tmp;

   open_pipe(pipex->cmd);
   tmp = pipex->cmd;
   while (tmp)
   {
       pipex->pid = fork();
       if (!pipex->pid)
       {
            if (!tmp->prev)
                setup_in(pipex);
            if (!tmp->next)
                setup_out(pipex);
            setup_pipe(tmp);
            if (execve(((t_cmd *)tmp->data)->bin,
               ((t_cmd *)tmp->data)->arg, pipex->env))
            {
                perror("fatal error");
                exit(0);
            }
       }
       close(((t_cmd*)tmp->data)->pipe[1]);
       if (tmp->prev)
            close(((t_cmd*)tmp->prev->data)->pipe[0]);
        tmp = tmp->next;
    }
    close_pipe(pipex->cmd);
    waitpid(pipex->pid, &pipex->status, 0);
    while (wait(NULL) > 0)
        ;
}
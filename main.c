#include "include/pipex.h"

int     main(int ac, char **av, char **env)
{
   t_pipex  *pipex;
   int  i;

    if (ac != 5)
        return 1;
    pipex = malloc(sizeof(t_pipex));
    if (!pipex)
        return 1;
    pipex->env = env;
    get_cmd(av, pipex);
    // printf("%s\n", pipex->cmd[0].bin);
    // printf("%s\n", pipex->cmd[1].bin);
    // i = 0;
    // while (pipex->cmd[0].arg[i])
    // {
    //     printf("%s\n", pipex->cmd[0].arg[i]);
    //     i++;
    // }
    // i = 0;
    // while (pipex->cmd[1].arg[i])
    // {
    //     printf("%s\n", pipex->cmd[1].arg[i]);
    //     i++;
    // }
    execute(pipex);
    return 0;
}
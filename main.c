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
    execute(pipex);
    return 0;
}
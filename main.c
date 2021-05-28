#include "include/pipex.h"

int     main(int ac, char **av, char **env)
{
   t_pipex  *pipex;
   t_list   *tmp;
   int  i;

    // if (ac != 5)
    //     return 1;
    pipex = malloc(sizeof(t_pipex));
    if (!pipex)
        return 1;
    pipex->env = env;
    get_cmds(av, ac, pipex);
    execute(pipex);
    // tmp = pipex->cmd;
    // while(tmp)
    // {
    //     printf("bin : %s\n", ((t_cmd*)tmp->data)->bin);
    //     i = 0;
    //     while (((t_cmd*)tmp->data)->arg[i])
    //     {
    //         printf("arg[%d] : %s\n", i, ((t_cmd*)tmp->data)->arg[i]);
    //         i++;
    //     }
    //     tmp = tmp->next;
    // }
    return 0;
}
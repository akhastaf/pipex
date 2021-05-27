#include "../include/pipex.h"

void    get_cmd(char **av, t_pipex *p)
{
    int i;

    i = 0;
    p->cmd = malloc(sizeof(t_cmd) * 2);
    if (!p->cmd)
        return ;
    p->cmd[0].file = ft_strdup(av[1]);
    p->cmd[0].arg = ft_split(av[2], ' ');
    p->cmd[0].bin = get_path(ft_strdup(p->cmd[0].arg[0]), p->env);
    p->cmd[0].in = -1;
    p->cmd[0].out = -1;
    p->cmd[1].file = ft_strdup(av[4]);
    p->cmd[1].arg = ft_split(av[3], ' ');
    p->cmd[1].bin = get_path(ft_strdup(p->cmd[1].arg[0]), p->env);
    p->cmd[1].in = -1;
    p->cmd[1].out = -1;
}
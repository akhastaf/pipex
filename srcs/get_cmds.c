#include "../include/pipex.h"

t_cmd   *get_cmd(char *s, char **env)
{
    t_cmd *cmd;

    cmd = malloc(sizeof(t_cmd));
    if (!cmd)
        return (NULL);
    cmd->arg = ft_split(s, ' ');
    cmd->bin = get_path(ft_strdup(cmd->arg[0]), env);
    cmd->pipe[0] = -1;
    cmd->pipe[1] = -1;
    return (cmd);
}

void    get_cmds(char **av, int ac, t_pipex *p)
{
    int i;
    t_cmd *cmd;

    p->cmd = NULL;
    p->filein = ft_strdup(av[1]);
    p->fileout = ft_strdup(av[ac - 1]);
    i = 1;
    while (av[++i] && (i < ac - 1))
    {
        cmd = get_cmd(av[i], p->env);
        ft_lstadd_back(&(p->cmd), ft_lstnew(cmd));
    }
}
#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct  s_cmd
{
    char    *bin;
    char    **arg;
    char    *file;
    int     in;
    int     out;
}   t_cmd;

typedef struct s_pipex
{
    t_cmd   *cmd;
    char    **env;
    pid_t   pid1;
    pid_t   pid2;
    int     pipe[2];
    int     stratus;
}   t_pipex;

void    get_cmd(char **av, t_pipex *p);
char    *get_path(char *bin, char **env);
void    execute(t_pipex *pipex);


char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strappend(char *str, char c);
void	ft_delete_arg(char **arg);
int     ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
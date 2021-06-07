/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:37:04 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/07 18:54:50 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
#include <errno.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
	struct s_list	*prev;

}					t_list;

typedef struct s_cmd
{
	char	*bin;
	char	**arg;
	int		pipe[2];
}			t_cmd;

typedef struct s_pipex
{
	t_list	*cmd;
	char	**env;
	pid_t	pid;
	char	*filein;
	char	*fileout;
	int		in;
	int		out;
	int		status;
}			t_pipex;

void	get_cmds(char **av, int ac, t_pipex *p);
t_cmd	*get_cmd(char *s, char **env);
char	*get_path(char *bin, char **env);
void	execute(t_pipex *pipex);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strappend(char *str, char c);
void	ft_delete_arg(char **arg);
int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *data);
void	ft_listprint(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_putendl_fd(char *s, int fd);
void	open_pipe(t_list *cmd);
void	close_pipe(t_list *cmd);
void	setup_pipe(t_list *cmd);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:36:08 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/11 16:44:03 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	*pipex;
	t_list	*tmp;
	int		i;

	if (ac != 5)
	{
		ft_putendl_fd("pipex error : Missing arguments", 2);
		exit(1);
	}
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
	{
		perror("Fatal error");
		return (1);
	}
	pipex->env = env;
	get_cmds(av, ac, pipex);
	open_pipe(pipex->cmd);
	execute(pipex);
	wait_execute(pipex);
	exit(pipex->status);
	return (pipex->status);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:36:08 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/07 19:00:13 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	*pipex;
	t_list	*tmp;
	int		i;

	if (ac <= 5)
	{
		ft_putendl_fd("Error : Missing arguments", 2);
		return (1);
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
	return (0);
}

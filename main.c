/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:36:08 by akhastaf          #+#    #+#             */
/*   Updated: 2021/05/29 17:05:54 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	*pipex;
	t_list	*tmp;
	int		i;

	if (ac < 5)
	{
		ft_putendl_fd("Error : Missing arguments\n", 2);
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
	execute(pipex);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:36:19 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/11 16:46:08 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	get_input(t_pipex *pipex)
{
	char	*line;

	line = NULL;
	pipe(pipex->pipein);
	dup2(pipex->pipein[1], 1);
	ft_putstr_fd("> ", 2);
	gnl(0, &line);
	while (ft_strcmp(line, pipex->stop))
	{
		ft_putstr_fd("> ", 2);
		ft_putendl_fd(line, 1);
		free(line);
		line = NULL;
		gnl(0, &line);
	}
	free(line);
}

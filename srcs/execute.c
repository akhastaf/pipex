/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:36:31 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/11 16:27:23 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	setup_in(t_pipex *pipex)
{
	pipex->in = open(pipex->filein, O_RDONLY, S_IRWXU);
	if (pipex->in < 0)
	{
		perror("Fatal error");
		exit(1);
	}
	dup2(pipex->in, 0);
}

void	setup_out(t_pipex *pipex)
{
	pipex->out = open(pipex->fileout, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (pipex->out < 0)
	{
		perror("Fatal error");
		exit(1);
	}
	dup2(pipex->out, 1);
}

void	execute(t_pipex *pipex)
{
	t_list	*tmp;

	tmp = pipex->cmd;
	while (tmp)
	{
		pipex->pid = fork();
		if (!pipex->pid)
		{
			if (!tmp->prev)
				setup_in(pipex);
			if (!tmp->next)
				setup_out(pipex);
			setup_pipe(tmp);
			if (execve(((t_cmd *)tmp->data)->bin,
					((t_cmd *)tmp->data)->arg, pipex->env))
			{
				perror("Fatal error");
				exit(127);
			}
		}
		close(((t_cmd *)tmp->data)->pipe[1]);
		if (tmp->prev)
			close(((t_cmd *)tmp->prev->data)->pipe[0]);
		tmp = tmp->next;
	}
}

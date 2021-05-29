/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:38:06 by akhastaf          #+#    #+#             */
/*   Updated: 2021/05/29 17:38:09 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	open_pipe(t_list *cmd)
{
	t_list	*tmp;
	int		l;

	tmp = cmd;
	l = ft_lstsize(tmp);
	while (tmp && l >= 2)
	{
		if (tmp->next)
			pipe(((t_cmd *)tmp->data)->pipe);
		tmp = tmp->next;
	}
}

void	close_pipe(t_list *cmd)
{
	t_list	*tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->next)
		{
			close(((t_cmd *)tmp->data)->pipe[0]);
			close(((t_cmd *)tmp->data)->pipe[1]);
		}
		tmp = tmp->next;
	}
}

void	setup_pipe(t_list *cmd)
{
	if (cmd->next)
	{
		dup2(((t_cmd *)cmd->data)->pipe[1], 1);
		close(((t_cmd *)cmd->data)->pipe[1]);
		close(((t_cmd *)cmd->data)->pipe[0]);
	}
	if (cmd->prev && cmd->next)
	{
		dup2(((t_cmd *)cmd->prev->data)->pipe[0], 0);
		close(((t_cmd *)cmd->prev->data)->pipe[0]);
		close(((t_cmd *)cmd->prev->data)->pipe[1]);
	}
	if (cmd->prev && !cmd->next)
	{
		dup2(((t_cmd *)cmd->prev->data)->pipe[0], 0);
		close(((t_cmd *)cmd->prev->data)->pipe[0]);
	}
}

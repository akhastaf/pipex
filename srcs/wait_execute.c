/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:58:51 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/11 16:43:52 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	wait_execute(t_pipex *pipex)
{
	close_pipe(pipex->cmd);
	waitpid(pipex->pid, &(pipex->status), 0);
	pipex->status = WEXITSTATUS(pipex->status);
	while (wait(NULL) > 0)
		;
}

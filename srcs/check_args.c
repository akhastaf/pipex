/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:43:23 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/11 15:43:36 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	check_args(int ac, char **arg)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (ft_is_empty(arg[i]))
		{
			ft_putendl_fd("pipex error : Missing arguments", 2);
			exit(1);
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:00:05 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/11 15:46:50 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*cs1;
	unsigned char	*cs2;
	int				i;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	i = 0;
	while (cs2[i] && cs1[i])
	{
		if (cs1[i] != cs2[i])
			return (cs1[i] - cs2[i]);
		i++;
	}
	return (cs1[i] - cs2[i]);
}

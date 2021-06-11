/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:49:35 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/11 15:47:42 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc((n * sizeof(char)) + 1);
	if (!str)
		return (NULL);
	while (s1[i] != '\0' && i < n)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

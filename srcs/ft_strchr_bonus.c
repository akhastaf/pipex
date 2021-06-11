/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:50:14 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/11 15:46:26 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	if (!s)
		return (NULL);
	if (!c)
		return (str + ft_strlen(s));
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:36:38 by akhastaf          #+#    #+#             */
/*   Updated: 2021/05/29 17:10:41 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*ft_strappend(char *str, char c)
{
	char	*s;
	int		l;
	int		i;

	if (!str)
	{
		s = malloc(sizeof(char) * 2);
		if (!s)
			return (NULL);
		s[0] = c;
		s[1] = 0;
		return (s);
	}
	l = ft_strlen(str);
	s = malloc(sizeof(char) * (l + 2));
	if (!s)
		return (NULL);
	i = -1;
	while (++i < l)
		s[i] = str[i];
	s[i++] = c;
	s[i] = 0;
	if (str)
		free(str);
	return (s);
}

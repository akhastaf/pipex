/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:46:19 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/11 15:53:52 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

char	*ft_checkerror(int fd, char **buff)
{
	if (!(BUFFER_SIZE >= 1) || (read(fd, *buff, 0) < 0))
		return (NULL);
	return (*buff);
}

int	ft_readline(int fd, char **str)
{
	char	*tmp;
	char	*buff;
	int		n;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (-1);
	 if (!ft_checkerror(fd, &buff))
	{
		free(buff);
		return (-1);
	}
	n = read(fd, buff, BUFFER_SIZE);
	while (n > 0)
	{
		buff[n] = '\0';
		tmp = *str;
		*str = ft_strjoin(*str, buff);
		free(tmp);
		if (ft_strchr(*str, '\n'))
			break ;
		n = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (n);
}

int	gnl(int fd, char **line)
{
	static char	*str;
	char		*tmp;
	char		*s;
	int			n;

	n = ft_readline(fd, &str);
	if (n < 0 || !line)
		return (-1);
	s = ft_strchr(str, '\n');
	if (s)
	{
		*line = ft_strndup(str, (int)(s - str));
		tmp = str;
		str = ft_strdup(s + 1);
		free(tmp);
		return (1);
	}
	if (!n && str)
	{
		*line = ft_strdup(str);
		free(str);
		str = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

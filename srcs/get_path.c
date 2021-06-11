/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:36:53 by akhastaf          #+#    #+#             */
/*   Updated: 2021/06/11 16:26:32 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	*get_envpath(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp("PATH=", env[i], 5))
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char	*get_path(char *bin, char **env)
{
	char	*path;
	char	*tmp;
	char	*binpath;
	char	**p;
	int		i;

	path = get_envpath(env);
	p = ft_split(path, ':');
	i = -1;
	while (p && p[++i])
	{
		p[i] = ft_strappend(p[i], '/');
		binpath = ft_strjoin(p[i], bin);
		if (open(binpath, O_RDONLY) > 0)
		{
			ft_delete_arg(p);
			free(bin);
			return (binpath);
		}
		free(binpath);
	}
	if (p)
		ft_delete_arg(p);
	return (bin);
}

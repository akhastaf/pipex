/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:36:53 by akhastaf          #+#    #+#             */
/*   Updated: 2021/05/28 18:18:12 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char    *get_path(char *bin, char **env)
{
    char *path;
    char *tmp;
    char *binpath;
    char **p;
    int i;

    i = 0;
    while (env[i])
    {
        if (!ft_strncmp("PATH=", env[i], 5))
        {
            path = env[i];
            break ;
        }    
        i++;
    }
    p = ft_split(path, ':');
    i = 0;
    while (p[i])
    {
        p[i] = ft_strappend(p[i], '/');
        binpath = ft_strjoin(p[i], bin);
        if (open(binpath, O_RDONLY) > 0)
        {
            ft_delete_arg(p);
            free(bin);
            return (binpath);
        }
        i++;
    }
    ft_delete_arg(p);
    return (bin);
}
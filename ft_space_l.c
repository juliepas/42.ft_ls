/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:29:49 by jpascal           #+#    #+#             */
/*   Updated: 2017/03/02 16:29:51 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*ft_putsize(char *str, t_files **allfile, t_files *tmp)
{
	t_files		*tamp;
	int			sizespaces;
	int			i;
	char		*str2;

	tamp = *allfile;
	sizespaces = ft_nbrlen(tamp->element.st_size);
	while (tamp != NULL)
	{
		if (ft_nbrlen(tamp->element.st_size) > sizespaces)
			sizespaces = ft_nbrlen(tamp->element.st_size);
		tamp = tamp->next;
	}
	i = ft_nbrlen(tmp->element.st_size);
	while (i < sizespaces)
	{
		str = ft_strjoinchar(str, ' ');
		i++;
	}
	str2 = ft_strjoin(str, ft_itoa(tmp->element.st_size));
	str2 = ft_strjoinchar(str2, ' ');
	return (str2);
}

char			*ft_putlink(char *str, t_files **allfile, t_files *tmp)
{
	t_files		*tamp;
	int			linkspaces;
	int			i;
	char		*str2;

	tamp = *allfile;
	linkspaces = ft_nbrlen(tamp->element.st_nlink);
	while (tamp != NULL)
	{
		if (ft_nbrlen(tamp->element.st_nlink) > linkspaces)
			linkspaces = ft_nbrlen(tamp->element.st_nlink);
		tamp = tamp->next;
	}
	i = ft_nbrlen(tmp->element.st_nlink);
	while (i < linkspaces)
	{
		str = ft_strjoinchar(str, ' ');
		i++;
	}
	str2 = ft_strjoin(str, ft_itoa(tmp->element.st_nlink));
	str2 = ft_strjoinchar(str2, ' ');
	return (str2);
}

char			*ft_put_name(char *str, t_files *tmp)
{
	char		*str2;
	char		buff[BUFF_SIZE];
	size_t		j;
	char		*way;
	char		*caca;

	caca = " -> ";
	str2 = ft_strjoin(str, tmp->file);
	if (S_ISLNK(tmp->element.st_mode) == 1)
	{
		if (ft_strcmp(tmp->path, tmp->file) != 0)
		{
			way = ft_strjoin(tmp->path, "/");
			way = ft_strjoinfree(way, tmp->file);
		}
		else
			way = ft_strdup(tmp->path);
		j = readlink(way, buff, BUFF_SIZE);
		buff[j] = '\0';
		str2 = ft_strjoinfree(str2, caca);
		str2 = ft_strjoinfree(str2, buff);
	}
	return (str2);
}

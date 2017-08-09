/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:30:21 by jpascal           #+#    #+#             */
/*   Updated: 2017/03/02 12:30:23 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*ft_strdupfree(char *str2, const char *src)
{
	char	*str;
	int		i;
	char	*sizemalloc;

	sizemalloc = (char*)src;
	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * ft_strlen(sizemalloc) + 1)))
		return (0);
	else
	{
		while (src[i] != '\0')
		{
			str[i] = src[i];
			i++;
		}
		str[i] = '\0';
		ft_strdel(&str2);
		return (str);
	}
}

void			ft_remove_lst(t_files **tmp)
{
	t_files	*tamp;
	t_files *supp;

	tamp = *tmp;
	supp = *tmp;
	while (tamp != NULL)
	{
		supp = supp->next;
		ft_strdel(&tamp->path);
		ft_strdel(&tamp->file);
		free(tamp);
		tamp = supp;
	}
	tmp = NULL;
	tamp = NULL;
}

void			ft_sort_reverse(t_files ***allfile)
{
	t_files		*tamp;

	tamp = **allfile;
	while (tamp->next != NULL)
		tamp = tamp->next;
	**allfile = tamp;
}

void			ft_afficher_path(char *path)
{
	ft_putstr(path);
	ft_putendl(":");
}

void			ft_grand_r(t_flags *parse, t_files **allfile,
	char **path, int i)
{
	t_files		*tmp;

	if (*allfile != NULL)
		ft_affichage(parse, allfile);
	tmp = *allfile;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->file, ".") != 0 && ft_strcmp(tmp->file, "..") != 0
			&& S_ISDIR(tmp->element.st_mode) == 1)
		{
			ft_putchar('\n');
			*path = ft_strjoinfree(*path, "/");
			*path = ft_strjoinfree(*path, tmp->file);
			ft_read_directory(parse, *path, i, tmp->file);
		}
		if (ft_strcmp(*path, tmp->path) != 0)
			*path = ft_strdup(tmp->path);
		if ((parse->r == 0 && tmp->next == NULL) ||
			(parse->r == 1 && tmp->prev == NULL))
		{
			ft_remove_lst(allfile);
			break ;
		}
		tmp = (parse->r == 1) ? tmp->prev : tmp->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_g_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 14:19:02 by jpascal           #+#    #+#             */
/*   Updated: 2017/06/14 14:19:04 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*putusertoolong(char *str, t_files **allfile, t_files *tmp)
{
	t_files			*tamp;
	int				userspaces;
	char			*str2;
	struct passwd	*pawd;
	int				i;

	userspaces = 1;
	tamp = *allfile;
	while (tamp != NULL)
	{
		if (tamp->element.st_uid != 4389)
		{
			pawd = getpwuid(tamp->element.st_uid);
			i = ft_strlen(pawd->pw_name);
			if (i > userspaces)
				userspaces = ft_strlen(pawd->pw_name);
		}
		tamp = tamp->next;
	}
	pawd = getpwuid(tmp->element.st_uid);
	i = ft_strlen(pawd->pw_name);
	str2 = ft_strjoin(str, pawd->pw_name);
	while (i++ < userspaces + 2)
		str2 = ft_strjoinchar(str2, ' ');
	return (str2);
}

char			*ft_putuser(char *str, t_files **allfile, t_files *tmp)
{
	char			*str2;

	if (tmp->element.st_uid == 4389)
		str2 = ft_strjoin(str, "4389  ");
	else
		str2 = putusertoolong(str, allfile, tmp);
	return (str2);
}

char			*ft_putgrp(char *str, t_files **allfile, t_files *tmp)
{
	t_files			*tamp;
	struct group	*grp;
	int				grpspaces;
	int				i;
	char			*str2;

	tamp = *allfile;
	grpspaces = 0;
	while (tamp != NULL)
	{
		grp = getgrgid(tamp->element.st_gid);
		i = ft_strlen(grp->gr_name);
		if (i > grpspaces)
			grpspaces = ft_strlen(grp->gr_name);
		tamp = tamp->next;
	}
	grp = getgrgid(tmp->element.st_gid);
	i = ft_strlen(grp->gr_name);
	str2 = ft_strjoin(str, grp->gr_name);
	while (i < grpspaces + 2)
	{
		str2 = ft_strjoinchar(str2, ' ');
		i++;
	}
	return (str2);
}

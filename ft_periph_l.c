/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_periph_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:45:28 by jpascal           #+#    #+#             */
/*   Updated: 2017/03/02 13:45:58 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				*ft_putminor(char *str, t_files **allfile, t_files *tmp)
{
	t_files			*tamp;
	int				minor;
	int				minorspaces;
	int				i;
	char			*str2;

	tamp = *allfile;
	minorspaces = 0;
	while (tamp != NULL)
	{
		minor = minor(tamp->element.st_rdev);
		if (ft_nbrlen(minor) > minorspaces)
			minorspaces = ft_nbrlen(minor);
		tamp = tamp->next;
	}
	minor = minor(tmp->element.st_rdev);
	i = ft_nbrlen(minor);
	while (i < minorspaces)
	{
		str = ft_strjoinchar(str, ' ');
		i++;
	}
	str2 = ft_strjoin(str, ft_itoa(minor));
	str2 = ft_strjoinchar(str2, ' ');
	return (str2);
}

char				*ft_putmajor(char *str, t_files **allfile, t_files *tmp)
{
	t_files			*tamp;
	int				major;
	int				majorspaces;
	int				i;
	char			*str2;

	tamp = *allfile;
	majorspaces = 0;
	while (tamp != NULL)
	{
		major = major(tamp->element.st_rdev);
		if (ft_nbrlen(major) > majorspaces)
			majorspaces = ft_nbrlen(major);
		tamp = tamp->next;
	}
	major = major(tmp->element.st_rdev);
	i = ft_nbrlen(major);
	while (i++ < majorspaces + 1)
		str = ft_strjoinchar(str, ' ');
	str2 = ft_strjoin(str, ft_itoa(major));
	str2 = ft_strjoinchar(str2, ',');
	str2 = ft_strjoinchar(str2, ' ');
	return (str2);
}

int					ft_periphsize(t_files **allfile)
{
	int				majorminor;
	int				minorspaces;
	int				majorspaces;
	t_files			*tamp;

	tamp = *allfile;
	majorspaces = 0;
	minorspaces = 0;
	while (tamp != NULL)
	{
		majorminor = major(tamp->element.st_rdev);
		if (ft_nbrlen(majorminor) > majorspaces)
			majorspaces = ft_nbrlen(majorminor);
		tamp = tamp->next;
	}
	tamp = *allfile;
	while (tamp != NULL)
	{
		majorminor = minor(tamp->element.st_rdev);
		if (ft_nbrlen(majorminor) > minorspaces)
			minorspaces = ft_nbrlen(majorminor);
		tamp = tamp->next;
	}
	majorminor = minorspaces + majorspaces + 3;
	return (majorminor);
}

char				*ft_putperiphsize(char *str, t_files **allfile,
	t_files *tmp)
{
	int				i;
	char			*str2;
	int				spaces;

	spaces = ft_periphsize(allfile);
	i = ft_nbrlen(tmp->element.st_size);
	while (i < spaces)
	{
		str = ft_strjoinchar(str, ' ');
		i++;
	}
	str2 = ft_strjoin(str, ft_itoa(tmp->element.st_size));
	str2 = ft_strjoinchar(str2, ' ');
	return (str2);
}

char				*ft_verif_periph(char *str, t_files **allfile, t_files *tmp,
	mode_t st_mode)
{
	t_files			*tamp;
	int				i;

	i = 0;
	tamp = *allfile;
	while (tamp != NULL && i == 0)
	{
		if (S_ISBLK(tamp->element.st_mode) == 1 ||
			S_ISCHR(tamp->element.st_mode) == 1)
		{
			if (S_ISBLK(st_mode) == 1 || S_ISCHR(st_mode) == 1)
			{
				str = ft_putmajor(str, allfile, tmp);
				str = ft_putminor(str, allfile, tmp);
			}
			else
				str = ft_putperiphsize(str, allfile, tmp);
			i = 1;
		}
		else
			tamp = tamp->next;
	}
	if (i == 0)
		str = ft_putsize(str, allfile, tmp);
	return (str);
}

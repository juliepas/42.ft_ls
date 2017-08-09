/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:27:11 by jpascal           #+#    #+#             */
/*   Updated: 2017/03/02 12:27:17 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*ft_can_you(char *str, t_files *allfile)
{
	t_files		*tmp;
	int			mode;

	tmp = allfile;
	mode = tmp->element.st_mode;
	str = ft_type(str, mode);
	str = (mode & S_IRUSR) ? ft_strjoinchar(str, 'r')
	: ft_strjoinchar(str, '-');
	str = (mode & S_IWUSR) ? ft_strjoinchar(str, 'w')
	: ft_strjoinchar(str, '-');
	str = ft_owner_exec(str, mode);
	str = (mode & S_IRGRP) ? ft_strjoinchar(str, 'r')
	: ft_strjoinchar(str, '-');
	str = (mode & S_IWGRP) ? ft_strjoinchar(str, 'w')
	: ft_strjoinchar(str, '-');
	str = ft_group_exec(str, mode);
	str = (mode & S_IROTH) ? ft_strjoinchar(str, 'r')
	: ft_strjoinchar(str, '-');
	str = (mode & S_IWOTH) ? ft_strjoinchar(str, 'w')
	: ft_strjoinchar(str, '-');
	str = ft_others_exec(str, mode);
	str = ft_xattr(str, &allfile);
	return (str);
}

void			ft_l_option(t_flags *parse, t_files **allfile, t_files *tamp)
{
	t_files		*tmp;
	char		*str;

	tmp = tamp;
	str = (char*)malloc(sizeof(char) * 2);
	ft_bzero(str, 2);
	str = ft_can_you(str, tmp);
	str = ft_putlink(str, allfile, tmp);
	if (parse->g != 1)
		str = ft_putuser(str, allfile, tmp);
	if (parse->o != 1)
		str = ft_putgrp(str, allfile, tmp);
	if (parse->o == 1 && parse->g == 1)
		str = ft_strjoin(str, "  ");
	str = ft_verif_periph(str, allfile, tmp, tmp->element.st_mode);
	if (parse->u == 1)
		str = ft_puttime_u(str, tmp);
	else
		str = ft_puttime(str, tmp);
	str = ft_put_name(str, tmp);
	ft_putendl(str);
	ft_strdel(&str);
}

void			ft_put_total_link(t_files **allfile)
{
	t_files		*tmp;
	int			totallink;

	tmp = *allfile;
	totallink = 0;
	ft_putstr("total ");
	while (tmp)
	{
		totallink += tmp->element.st_blocks;
		tmp = tmp->next;
	}
	ft_putnbrendl(totallink);
}

int				ft_put_loption(t_flags *parse, t_files **allfile,
	t_files *tmp, int i)
{
	t_files		*tamp;

	tamp = *allfile;
	if (parse->r == 1)
		while (tamp->prev != NULL)
			tamp = tamp->prev;
	if (parse->l == 1 || parse->o == 1 || parse->g == 1)
	{
		if ((i == 0 && ft_strcmp(tmp->path, tmp->file) != 0) ||
			(i == 0 && tmp->file[0] == '.'))
		{
			ft_put_total_link(&tamp);
			i = 1;
		}
		ft_l_option(parse, &tamp, tmp);
	}
	else
		ft_putendl(tmp->file);
	return (i);
}

void			ft_affichage(t_flags *parse, t_files **allfile)
{
	t_files		*tmp;
	int			i;

	i = 0;
	if (parse->t == 1 && parse->u == 0 && parse->grands == 0)
		ft_option_t(&allfile);
	else if (parse->u == 1 && parse->t == 1 && parse->grands == 0)
		ft_option_u(&allfile);
	else if (parse->grands == 1)
		ft_grand_s(&allfile);
	else
		ft_sort_files(&allfile);
	if (parse->r == 1)
		ft_sort_reverse(&allfile);
	tmp = *allfile;
	while (tmp != NULL)
	{
		i = ft_put_loption(parse, allfile, tmp, i);
		if (parse->r == 1)
			tmp = tmp->prev;
		else
			tmp = tmp->next;
	}
}

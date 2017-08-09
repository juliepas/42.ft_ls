/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_date_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 12:03:50 by jpascal           #+#    #+#             */
/*   Updated: 2017/03/04 12:04:09 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_swap_maillon(t_files ***allfile, t_files **tmp, t_files **tamp)
{
	t_files	*swap;
	t_files *tmp1;
	t_files *tamp1;

	tmp1 = *tmp;
	tamp1 = *tamp;
	swap = tmp1->prev;
	tmp1->next = tamp1->next;
	tmp1->prev = tamp1;
	if (tamp1->next != NULL)
		tamp1->next->prev = tmp1;
	if (swap != NULL)
		swap->next = tamp1;
	else
		**allfile = tamp1;
	tamp1->next = tmp1;
	tamp1->prev = swap;
}

void		ft_option_t(t_files ***allfile)
{
	t_files	*tmp;
	t_files	*tamp;
	t_files	*swap;

	swap = NULL;
	tmp = **allfile;
	tamp = tmp->next;
	while (tmp != NULL && tamp != NULL)
	{
		if ((tamp->element.st_mtime > tmp->element.st_mtime) ||
			((tamp->element.st_mtime == tmp->element.st_mtime) &&
				(ft_strcmp(tmp->file, tamp->file) > 0)))
		{
			ft_swap_maillon(allfile, &tmp, &tamp);
			tmp = **allfile;
			tamp = tmp->next;
		}
		else
		{
			tmp = tmp->next;
			tamp = tamp->next;
		}
	}
}

void		ft_option_u(t_files ***allfile)
{
	t_files	*tmp;
	t_files	*tamp;

	tmp = **allfile;
	tamp = tmp->next;
	while (tmp != NULL && tamp != NULL)
	{
		if ((tamp->element.st_atime > tmp->element.st_atime) ||
			((tamp->element.st_atime == tmp->element.st_atime) &&
				(ft_strcmp(tmp->file, tamp->file) > 0)))
		{
			ft_swap_maillon(allfile, &tmp, &tamp);
			tmp = **allfile;
			tamp = tmp->next;
		}
		else
		{
			tmp = tmp->next;
			tamp = tamp->next;
		}
	}
}

char		*ft_puttime(char *str, t_files *tmp)
{
	char	*timing;
	int		i;
	time_t	t;

	i = 3;
	t = 0;
	t = time(&t);
	timing = ctime(&tmp->element.st_mtime);
	if ((tmp->element.st_mtime < (t - 15778800)) ||
		(tmp->element.st_mtime > (t + 3600)))
	{
		while (++i < 11)
			str = ft_strjoinchar(str, timing[i]);
		if (ft_strlen(timing) > 25)
			i = ft_strlen(timing) - 8;
		else
			i = ft_strlen(timing) - 7;
		while (timing[++i] != '\n')
			str = ft_strjoinchar(str, timing[i]);
	}
	else
		while (++i < 16)
			str = ft_strjoinchar(str, timing[i]);
	str = ft_strjoinchar(str, ' ');
	return (str);
}

char		*ft_puttime_u(char *str, t_files *tmp)
{
	char	*timing;
	int		i;
	time_t	t;

	i = 3;
	t = 0;
	t = time(&t);
	timing = ctime(&tmp->element.st_atime);
	if ((tmp->element.st_atime < (t - 15778800)) ||
		(tmp->element.st_atime > (t + 3600)))
	{
		while (++i < 11)
			str = ft_strjoinchar(str, timing[i]);
		if (ft_strlen(timing) > 25)
			i = ft_strlen(timing) - 8;
		else
			i = ft_strlen(timing) - 7;
		while (timing[++i] != '\n')
			str = ft_strjoinchar(str, timing[i]);
	}
	else
		while (++i < 16)
			str = ft_strjoinchar(str, timing[i]);
	str = ft_strjoinchar(str, ' ');
	return (str);
}

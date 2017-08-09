/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:08:24 by jpascal           #+#    #+#             */
/*   Updated: 2017/03/04 15:08:26 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_grand_s(t_files ***allfile)
{
	t_files	*tmp;
	t_files	*tamp;

	tmp = **allfile;
	tamp = tmp->next;
	while (tmp != NULL && tamp != NULL)
	{
		if ((tamp->element.st_size > tmp->element.st_size) ||
			((tamp->element.st_size == tmp->element.st_size) &&
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

void	ft_sort_params(int argc, char **argv)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < argc - 1)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			tmp = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	ft_sort_files(t_files ***allfile)
{
	t_files	*tmp;
	t_files	*tamp;

	tmp = **allfile;
	tamp = tmp->next;
	while (tmp != NULL && tamp != NULL)
	{
		if (ft_strcmp(tmp->file, tamp->file) > 0)
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

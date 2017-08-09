/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pick_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 21:52:20 by jpascal           #+#    #+#             */
/*   Updated: 2017/03/15 21:52:23 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**ft_remove_line(char **path, int i)
{
	int		j;
	char	**tableau;
	int		k;

	k = 0;
	j = 0;
	while (path[j][0] != '\0')
		j++;
	tableau = (char**)malloc(sizeof(char*) * j);
	j = 0;
	while (path[j][0] != '\0')
	{
		if (j != i)
		{
			tableau[j - k] = ft_strdup(path[j]);
			ft_strdel(&path[j]);
		}
		else
			k++;
		j++;
	}
	free(path);
	path = NULL;
	tableau[j - k] = "\0";
	return (tableau);
}

int		verif_sym_lnk(char *path)
{
	struct stat lkstat;

	if (lstat(path, &lkstat) == -1)
		return (0);
	if (S_ISLNK(lkstat.st_mode) == 1)
		return (1);
	else
		return (0);
}

void	ft_manage_file(t_files *file, DIR *rep, t_flags *parse, int i)
{
	if (file != NULL)
		ft_affichage(parse, &file);
	if (i != 0 && file != NULL)
		ft_putchar('\n');
	if (rep == NULL && file != NULL)
		ft_remove_lst(&file);
}

char	**ft_manage_errors(t_files **file, struct dirent *fichier,
	char **path, int *i)
{
	if (errno == ENOTDIR ||
		(errno == ENOENT && verif_sym_lnk(path[*i]) == 1))
	{
		ft_createfile(file, fichier, path[*i]);
		path = ft_remove_line(path, *i);
	}
	else if (errno == ENOENT)
	{
		ft_putstr_fd("ls: ", 2);
		perror(path[*i]);
		path = ft_remove_line(path, *i);
	}
	else
		*i = *i + 1;
	return (path);
}

char	**ft_pick_files(char **path, t_flags *parse)
{
	t_files			*file;
	int				i;
	DIR				*rep;
	struct dirent	*fichier;

	fichier = NULL;
	file = NULL;
	i = 0;
	while (path[i][0] != '\0')
	{
		if (verif_sym_lnk(path[i]) == 1 && parse->l == 1)
		{
			ft_createfile(&file, fichier, path[i]);
			path = ft_remove_line(path, i);
		}
		else if (!(rep = opendir(path[i])))
			path = ft_manage_errors(&file, fichier, path, &i);
		else
			i++;
		if (rep != NULL && file == NULL)
			closedir(rep);
	}
	ft_manage_file(file, rep, parse, i);
	return (path);
}

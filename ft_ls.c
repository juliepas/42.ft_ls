/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 11:59:56 by jpascal           #+#    #+#             */
/*   Updated: 2017/03/02 11:59:59 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				*ft_recreate_path(struct dirent *fichierlu, t_files *new)
{
	char	*str;

	if (fichierlu != NULL)
	{
		str = ft_strjoin(new->path, "/");
		str = ft_strjoinfree(str, new->file);
	}
	else
	{
		if (new->file[0] != '/')
		{
			str = ft_strdup("./");
			str = ft_strjoinfree(str, new->file);
		}
		else
			str = ft_strdup(new->file);
	}
	return (str);
}

void				ft_createfile(t_files **allfile, struct dirent *fichierlu,
	char *path)
{
	t_files			*tmp;
	t_files			*new;
	char			*str;

	tmp = *allfile;
	new = (t_files*)malloc(sizeof(t_files));
	new->path = ft_strdup(path);
	new->file = (fichierlu != NULL) ? ft_strdup(fichierlu->d_name)
	: ft_strdup(path);
	new->prev = NULL;
	new->next = NULL;
	str = ft_recreate_path(fichierlu, new);
	if (lstat(str, &new->element) != -1)
	{
		if (*allfile == NULL)
			*allfile = new;
		else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
			new->prev = tmp;
		}
	}
	ft_strdel(&str);
}

void				ft_create_lst(DIR *rep, t_flags *parse, t_files **allfile,
	char *path)
{
	struct dirent	*fichierlu;

	while (rep && (fichierlu = readdir(rep)) != NULL)
	{
		if (parse->a == 1)
			ft_createfile(allfile, fichierlu, path);
		else if (parse->a == 0 && fichierlu->d_name[0] != '.')
			ft_createfile(allfile, fichierlu, path);
	}
	closedir(rep);
}

void				ft_read_directory(t_flags *parse, char *path, int i,
	char *file)
{
	t_files			*allfile;
	DIR				*rep;

	allfile = NULL;
	if (i != 0)
		ft_afficher_path(path);
	i = 1;
	if (!(rep = opendir(path)))
	{
		ft_putstr_fd("ls: ", 2);
		(file != NULL) ? perror(file) : perror(path);
		i = 0;
	}
	else
		ft_create_lst(rep, parse, &allfile, path);
	if (parse->grandr == 1)
		ft_grand_r(parse, &allfile, &path, i);
	else if (rep && allfile != NULL)
	{
		ft_affichage(parse, &allfile);
		ft_remove_lst(&allfile);
	}
	ft_strdel(&path);
}

int					main(int argc, char **argv)
{
	t_flags			parse;
	char			**path;
	int				i;
	int				j;
	char			*way;

	i = -1;
	j = 1;
	way = NULL;
	ft_bzero(&parse, sizeof(parse));
	path = ft_parse(argc, argv, &parse);
	while (path[j][0] != '\0')
		j++;
	ft_sort_params(j, path);
	path = ft_pick_files(path, &parse);
	while (ft_strcmp(path[++i], "\0") != 0)
	{
		way = ft_strdup(path[i]);
		if (i == 0 && j != 1)
			ft_afficher_path(path[i]);
		ft_read_directory(&parse, way, i, NULL);
		if (ft_strcmp(path[i + 1], "\0") != 0)
			ft_putchar('\n');
	}
	return (0);
}

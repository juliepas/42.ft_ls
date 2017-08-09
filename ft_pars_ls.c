/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 05:29:14 by jpascal           #+#    #+#             */
/*   Updated: 2017/01/17 05:29:23 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_tina_ternaires(t_flags *parse, char argv)
{
	if (parse->grandr != 1)
		parse->grandr = (argv == 'R') ? 1 : 0;
	if (parse->l != 1)
		parse->l = (argv == 'l') ? 1 : 0;
	if (parse->a != 1)
		parse->a = (argv == 'a') ? 1 : 0;
	if (parse->r != 1)
		parse->r = (argv == 'r') ? 1 : 0;
	if (parse->t != 1)
		parse->t = (argv == 't') ? 1 : 0;
	if (parse->o != 1)
		parse->o = (argv == 'o') ? 1 : 0;
	if (parse->g != 1)
		parse->g = (argv == 'g') ? 1 : 0;
	if (parse->u != 1)
		parse->u = (argv == 'u') ? 1 : 0;
	if (parse->grands != 1)
		parse->grands = (argv == 'S') ? 1 : 0;
}

void		ft_verif_flags(char *argv, t_flags *parse)
{
	int i;

	i = 0;
	while (argv[++i] != '\0')
	{
		if (argv[i] == 'R' || argv[i] == 'l' ||
		argv[i] == 'a' || argv[i] == 'r' || argv[i] == 't' || argv[i] == 'o'
		|| argv[i] == 'g' || argv[i] == 'u' || argv[i] == 'S')
			ft_tina_ternaires(parse, argv[i]);
		else if (argv[i] == '1')
		{
			parse->g = 0;
			parse->o = 0;
			parse->l = 0;
		}
		else
		{
			ft_putstr_fd("ls: illegal option -- ", 2);
			ft_putchar_fd(argv[i], 2);
			ft_putchar_fd('\n', 2);
			ft_putstr_fd("usage: ls [-ABCFGHLOPRSTUWabcde", 2);
			ft_putendl_fd("fghiklmnopqrstuwx1] [file ...]", 2);
			exit(1);
		}
	}
}

char		**ft_verif_dirent(int argc, char **argv, char **path, int i)
{
	int		j;

	j = 0;
	if (argv[i] && ft_strcmp(argv[i], "--") == 0)
		i++;
	if (argv[i])
	{
		if (!(path = (char**)malloc(sizeof(char*) * (argc - i + 1))))
			return (0);
		while (argv[i + j])
		{
			if (argv[i + j][0] == '\0')
			{
				ft_putendl_fd("ls: fts_open: No such file or directory", 2);
				exit(-1);
			}
			path[j] = ft_strdup(argv[i + j]);
			j++;
		}
		path[j] = "\0";
	}
	return (path);
}

char		**ft_parse(int argc, char **argv, t_flags *parse)
{
	char	**path;
	int		i;

	i = 0;
	path = NULL;
	if (argc > 1)
	{
		while (argv[++i] && argv[i][0] == '-' && argv[i][1] != '\0' &&
			ft_strcmp(argv[i], "--") != 0)
			ft_verif_flags(argv[i], parse);
		if (argv[i])
			path = ft_verif_dirent(argc, argv, path, i);
	}
	if (path == NULL)
	{
		if (!(path = (char**)malloc(sizeof(char*) * 2)))
			return (0);
		path[0] = ".";
		path[1] = "\0";
	}
	return (path);
}

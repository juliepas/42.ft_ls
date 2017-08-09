/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 11:35:23 by jpascal           #+#    #+#             */
/*   Updated: 2017/03/02 11:35:28 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <dirent.h>
# include <errno.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <time.h>
# include <sys/time.h>
# include "libft/libft.h"

# define BUFF_SIZE 800

typedef struct		s_flags
{
	int		grandr;
	int		l;
	int		a;
	int		r;
	int		t;
	int		o;
	int		g;
	int		u;
	int		grands;
}					t_flags;

typedef struct		s_files
{
	char			*path;
	char			*file;
	struct stat		element;
	struct s_files	*next;
	struct s_files	*prev;
}					t_files;

char				**ft_parse(int argv, char **argc, t_flags *parse);
void				ft_read_directory(t_flags *parse, char *path,
	int i, char *file);
void				ft_grand_r(t_flags *parse, t_files **allfile,
	char **path, int i);
void				ft_affichage(t_flags *parse, t_files **allfile);
void				ft_sort_files(t_files ***allfile);
void				ft_sort_reverse(t_files ***allfile);
void				ft_sort_params(int argc, char **argv);
char				*ft_putlink(char *str, t_files **allfile, t_files *tmp);
char				*ft_putsize(char *str, t_files **allfile, t_files *tmp);
char				*ft_putuser(char *str, t_files **allfile, t_files *tmp);
char				*ft_putgrp(char *str, t_files **allfile, t_files *tmp);
char				*ft_putmajor(char *str, t_files **allfile, t_files *tmp);
char				*ft_putminor(char *str, t_files **allfile, t_files *tmp);
char				*ft_verif_periph(char *str, t_files **allfile,
	t_files *tmp, mode_t st_mode);
char				*ft_puttime(char *str, t_files *tmp);
char				*ft_put_name(char *str, t_files *tmp);
void				ft_option_t(t_files ***allfile);
char				**ft_pick_files(char **path, t_flags *parse);
void				ft_createfile(t_files **allfile, struct dirent *fichierlu,
	char *path);
char				*ft_can_you(char *str, t_files *allfile);
void				ft_option_u(t_files ***allfile);
char				*ft_puttime_u(char *str, t_files *tmp);
void				ft_grand_s(t_files ***allfile);
char				*ft_type(char *str, int mode);
char				*ft_xattr(char *str, t_files **allfile);
char				*ft_others_exec(char *str, int mode);
char				*ft_group_exec(char *str, int mode);
char				*ft_owner_exec(char *str, int mode);
void				ft_swap_maillon(t_files ***allfile, t_files **tmp,
	t_files **tamp);
void				ft_remove_lst(t_files **tmp);
void				ft_afficher_path(char *path);

#endif

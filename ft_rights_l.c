/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rights_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 14:27:33 by jpascal           #+#    #+#             */
/*   Updated: 2017/03/02 14:27:38 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_owner_exec(char *str, int mode)
{
	if (mode & S_IXUSR || mode & S_ISUID)
	{
		if (mode & S_IXUSR && mode & S_ISUID)
			str = ft_strjoinchar(str, 's');
		else if (mode & S_IXUSR && !(mode & S_ISUID))
			str = ft_strjoinchar(str, 'x');
		else if (mode & S_ISUID && !(mode & S_IXUSR))
			str = ft_strjoinchar(str, 'S');
	}
	else
		str = ft_strjoinchar(str, '-');
	return (str);
}

char	*ft_group_exec(char *str, int mode)
{
	if (mode & S_IXGRP || mode & S_ISGID)
	{
		if (mode & S_IXGRP && mode & S_ISGID)
			str = ft_strjoinchar(str, 's');
		else if (mode & S_IXGRP && !(mode & S_ISGID))
			str = ft_strjoinchar(str, 'x');
		else if (mode & S_ISGID && !(mode & S_IXGRP))
			str = ft_strjoinchar(str, 'S');
	}
	else
		str = ft_strjoinchar(str, '-');
	return (str);
}

char	*ft_others_exec(char *str, int mode)
{
	if (mode & S_IXOTH || mode & S_ISVTX)
	{
		if (mode & S_IXOTH && mode & S_ISVTX)
			str = ft_strjoinchar(str, 't');
		else if (mode & S_IXOTH && !(mode & S_ISVTX))
			str = ft_strjoinchar(str, 'x');
		else if (mode & S_ISVTX && !(mode & S_IXOTH))
			str = ft_strjoinchar(str, 'T');
	}
	else
		str = ft_strjoinchar(str, '-');
	return (str);
}

char	*ft_xattr(char *str, t_files **allfile)
{
	t_files		*tmp;
	char		*chemin;

	tmp = *allfile;
	if (ft_strcmp(tmp->file, tmp->path) != 0)
	{
		chemin = ft_strjoin(tmp->path, "/");
		chemin = ft_strjoinfree(chemin, tmp->file);
	}
	else
		chemin = tmp->file;
	if (listxattr(chemin, NULL, BUFF_SIZE, XATTR_NOFOLLOW) > 0)
		str = ft_strjoinfree(str, "@ ");
	else if (acl_get_file(chemin, ACL_TYPE_EXTENDED) != NULL)
		str = ft_strjoinfree(str, "+ ");
	else
		str = ft_strjoinfree(str, "  ");
	return (str);
}

char	*ft_type(char *str, int mode)
{
	str[0] = (S_ISSOCK(mode) == 1) ? 's' : str[0];
	str[0] = (S_ISBLK(mode) == 1) ? 'b' : str[0];
	str[0] = (S_ISCHR(mode) == 1) ? 'c' : str[0];
	str[0] = (S_ISFIFO(mode) == 1) ? 'p' : str[0];
	str[0] = (S_ISDIR(mode) == 1) ? 'd' : str[0];
	str[0] = (S_ISREG(mode) == 1) ? '-' : str[0];
	str[0] = (S_ISLNK(mode) == 1) ? 'l' : str[0];
	return (str);
}

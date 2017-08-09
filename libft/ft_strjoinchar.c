/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:34:30 by jpascal           #+#    #+#             */
/*   Updated: 2017/03/06 18:34:51 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoinchar(char *str, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	if (str == NULL)
	{
		if (!(tmp = (char*)malloc(sizeof(char) * 2)))
			return (0);
	}
	else
	{
		if (!(tmp = (char*)malloc(sizeof(char) * (ft_strlen(str) + 2))))
			return (0);
		while (str[i])
		{
			tmp[i] = str[i];
			i++;
		}
	}
	tmp[i] = c;
	tmp[i + 1] = '\0';
	ft_strdel(&str);
	return (tmp);
}

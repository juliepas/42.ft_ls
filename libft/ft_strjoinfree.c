/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 18:33:30 by jpascal           #+#    #+#             */
/*   Updated: 2017/03/06 18:34:13 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, const char *s2)
{
	size_t	lens1;
	size_t	lens2;
	size_t	i;
	char	*str;

	i = -1;
	if (!(s1 && s2))
		return (0);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * (lens1 + lens2 + 1))))
		return (0);
	while (++i < lens1)
		str[i] = s1[i];
	i = -1;
	while (++i < lens2)
		str[i + lens1] = s2[i];
	str[i + lens1] = '\0';
	ft_strdel(&s1);
	return (str);
}

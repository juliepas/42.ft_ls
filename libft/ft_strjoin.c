/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 22:13:24 by jpascal           #+#    #+#             */
/*   Updated: 2016/11/22 03:24:18 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	size_t	i;
	char	*str;

	i = 0;
	if (!(s1 && s2))
		return (0);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * (lens1 + lens2 + 1))))
		return (0);
	while (i < lens1)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < lens2)
	{
		str[i + lens1] = s2[i];
		i++;
	}
	str[i + lens1] = '\0';
	return (str);
}

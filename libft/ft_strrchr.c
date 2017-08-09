/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:19:01 by jpascal           #+#    #+#             */
/*   Updated: 2016/11/24 01:40:54 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*s;

	s = (char*)str;
	i = ft_strlen(str);
	while (i > 0 && s[i] != c)
		i--;
	if (s[i] == c)
		return (&s[i]);
	return (0);
}

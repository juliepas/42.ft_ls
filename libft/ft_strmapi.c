/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 01:13:56 by jpascal           #+#    #+#             */
/*   Updated: 2016/11/22 03:16:53 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	char			*s2;

	i = 0;
	s2 = (char*)s;
	if (!(s || (*f)))
		return (0);
	if (!(str = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (0);
	while (s[i] != '\0')
	{
		str[i] = (*f)(i, s2[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 01:13:56 by jpascal           #+#    #+#             */
/*   Updated: 2016/11/24 03:47:10 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;
	char	*s2;

	i = 0;
	s2 = (char*)s;
	if (!(s || (*f)))
		return (0);
	if (!(str = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (0);
	while (s[i] != '\0')
	{
		str[i] = (*f)(s2[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

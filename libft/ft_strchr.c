/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 02:19:01 by jpascal           #+#    #+#             */
/*   Updated: 2016/11/18 06:32:43 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	s;

	s = (char)c;
	i = 0;
	while (str[i] && str[i] != s)
		i++;
	if (str[i] == s)
		return ((char*)str + i);
	return (0);
}

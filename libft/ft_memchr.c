/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 05:55:51 by jpascal           #+#    #+#             */
/*   Updated: 2016/11/23 06:22:50 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*str;
	unsigned char		d;
	size_t				i;

	str = (unsigned char*)s;
	d = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == d)
			return (str + i);
		i++;
	}
	return (0);
}

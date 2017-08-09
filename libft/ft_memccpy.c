/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 01:52:48 by jpascal           #+#    #+#             */
/*   Updated: 2016/11/22 05:41:01 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	d;

	i = 0;
	s1 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	d = (unsigned char)c;
	while (i < n)
	{
		if (s2[i] == d)
		{
			s1[i] = s2[i];
			return (s1 + i + 1);
		}
		s1[i] = s2[i];
		i++;
	}
	return (0);
}

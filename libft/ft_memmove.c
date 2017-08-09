/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 01:52:48 by jpascal           #+#    #+#             */
/*   Updated: 2016/11/22 06:12:17 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*s11;
	unsigned char	*s22;
	size_t			i;

	s11 = (unsigned char*)dst;
	s22 = (unsigned char*)src;
	i = n;
	if (src < dst)
	{
		while (i)
		{
			s11[i - 1] = s22[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			s11[i] = s22[i];
			i++;
		}
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 21:47:13 by jpascal           #+#    #+#             */
/*   Updated: 2016/11/23 05:09:21 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t			i;
	unsigned int	index;

	index = 0;
	i = 0;
	while (dest[i] && i <= n - 1)
		i++;
	if (n < i)
		return (n + ft_strlen(src));
	index = i;
	while (src[i - index] && i < n - 1)
	{
		dest[i] = src[i - index];
		i++;
	}
	if (i <= n - 1)
		dest[i] = '\0';
	return (index + ft_strlen(src));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 21:47:13 by jpascal           #+#    #+#             */
/*   Updated: 2016/11/21 06:38:05 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int				i;
	unsigned int	index;

	i = ft_strlen(dest);
	index = 0;
	while (src[index] && index < n)
	{
		dest[i] = src[index];
		i++;
		index++;
	}
	dest[i] = '\0';
	return (dest);
}

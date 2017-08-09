/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 21:47:13 by jpascal           #+#    #+#             */
/*   Updated: 2016/11/24 01:40:41 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int index;

	i = 0;
	index = 0;
	while (dest[i] != '\0')
		i++;
	while (src[index] != '\0')
	{
		dest[i] = src[index];
		i++;
		index++;
	}
	dest[i] = '\0';
	return (dest);
}

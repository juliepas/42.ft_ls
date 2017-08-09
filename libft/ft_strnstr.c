/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 03:33:24 by jpascal           #+#    #+#             */
/*   Updated: 2016/11/23 05:27:43 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t index;

	i = 0;
	index = 0;
	if (!(little[i]))
		return ((char*)big);
	while (big[i] && i < len)
	{
		while (big[i + index] == little[index] && (i + index) < len)
		{
			index++;
			if (little[index] == '\0')
				return ((char*)big + i);
		}
		index = 0;
		i++;
	}
	return (NULL);
}

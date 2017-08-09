/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 03:33:24 by jpascal           #+#    #+#             */
/*   Updated: 2016/11/25 08:47:05 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int index;

	i = 0;
	index = 0;
	if (!(little[i]))
		return ((char*)big);
	while (big[i])
	{
		while (big[i + index] == little[index])
		{
			index++;
			if (little[index] == '\0')
				return ((char*)big + i);
		}
		index = 0;
		i++;
	}
	return (0);
}

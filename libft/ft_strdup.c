/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:13:46 by jpascal           #+#    #+#             */
/*   Updated: 2016/11/15 04:52:17 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		i;
	char	*sizemalloc;

	sizemalloc = (char*)src;
	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * ft_strlen(sizemalloc) + 1)))
		return (0);
	else
	{
		while (src[i] != '\0')
		{
			str[i] = src[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
}

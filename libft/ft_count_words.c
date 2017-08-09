/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 06:03:34 by jpascal           #+#    #+#             */
/*   Updated: 2016/11/23 06:16:49 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(const char *str, char c)
{
	size_t i;
	size_t nb;

	i = 0;
	nb = 0;
	while (str[i] == c)
		i++;
	while (str[i])
	{
		i++;
		if (str[i] == c || str[i] == '\0')
		{
			nb++;
			while (str[i] == c)
				i++;
		}
	}
	return (nb);
}

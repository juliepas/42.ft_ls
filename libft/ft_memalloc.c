/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 23:03:38 by jpascal           #+#    #+#             */
/*   Updated: 2016/11/17 03:19:57 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*viod;

	if (!(viod = (void*)malloc(size)))
		return (0);
	ft_bzero(viod, size);
	return (viod);
}

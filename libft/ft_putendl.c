/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 20:08:17 by jpascal           #+#    #+#             */
/*   Updated: 2016/11/15 03:46:49 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(const char *s)
{
	int index;

	index = ft_strlen(s);
	if (s == NULL)
		ft_putendl("(null)");
	write(1, s, index);
	ft_putchar('\n');
}

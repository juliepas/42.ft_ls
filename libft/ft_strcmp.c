/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:29:02 by jpascal           #+#    #+#             */
/*   Updated: 2016/11/22 01:21:17 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	int				nb;
	unsigned char	*s11;
	unsigned char	*s22;

	i = 0;
	nb = 0;
	s11 = (unsigned char*)s1;
	s22 = (unsigned char*)s2;
	if (s11[i] == 0 && s22[i] == 0)
		return (0);
	while (s11[i] == s22[i] && s11[i] != '\0' && s22[i] != '\0')
		i++;
	nb = s11[i] - s22[i];
	return (nb);
}

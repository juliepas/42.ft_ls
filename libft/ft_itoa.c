/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 07:21:53 by jpascal           #+#    #+#             */
/*   Updated: 2016/11/23 07:48:37 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int		ft_nbrlong(long int n)
{
	long int i;

	i = 0;
	if (n == 0)
		i = 1;
	else if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char				*ft_itoa(int n)
{
	char		*str;
	long int	i;
	long int	nb;

	nb = (long int)n;
	i = ft_nbrlong(nb);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	else if (nb < 0)
	{
		str[i - i] = '-';
		nb = -nb;
	}
	str[i] = '\0';
	i--;
	if (nb == 0 || nb == -0)
		str[i] = '0';
	while (nb > 0)
	{
		str[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	return (str);
}

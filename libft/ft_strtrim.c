/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 22:35:30 by jpascal           #+#    #+#             */
/*   Updated: 2016/11/22 03:29:25 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		len;
	char	*str;

	start = 0;
	if (!(s))
		return (0);
	len = ft_strlen(s);
	while ((s[start] == ' ' || s[start] == '\n' || s[start] == '\t') &&
			start != len)
		start++;
	while ((s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t') &&
			start != len)
		len--;
	str = ft_strsub(s, start, (len - start));
	return (str);
}

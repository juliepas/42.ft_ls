/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 17:44:44 by jpascal           #+#    #+#             */
/*   Updated: 2016/11/23 06:23:58 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbr_words(const char *str, char c)
{
	size_t	i;
	size_t	nb;

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

static int		ft_lenwords(char const *str, char c, int index)
{
	int	len;

	len = index;
	while (str[len] != c && str[len])
		len++;
	return (len - index);
}

static char		**ft_createtab(char const *s, char **tab, char c)
{
	int	index;
	int j;
	int i;

	index = 0;
	j = 0;
	i = 0;
	while (s[index])
	{
		while (s[index] == c && s[index])
			index++;
		if (!(tab[i] = (char*)malloc(sizeof(char) *
						ft_lenwords(s, c, index) + 1)))
			return (0);
		while (s[index] != c && s[index])
		{
			tab[i][j] = s[index];
			j++;
			index++;
		}
		tab[i][j] = '\0';
		i++;
		j = 0;
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nb_words;

	if (!(s))
		return (0);
	nb_words = nbr_words(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * nb_words + 1)))
		return (0);
	ft_createtab(s, tab, c);
	tab[nb_words] = NULL;
	return (tab);
}

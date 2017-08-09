/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 07:01:30 by jpascal           #+#    #+#             */
/*   Updated: 2016/11/23 05:25:55 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	tmp = *alst;
	while (tmp != NULL)
	{
		del(tmp->content, tmp->content_size);
		free(tmp);
		*alst = NULL;
		tmp = tmp->next;
	}
	tmp = NULL;
}

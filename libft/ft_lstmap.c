/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 07:03:00 by jpascal           #+#    #+#             */
/*   Updated: 2016/11/25 06:38:57 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *new;
	t_list *tmp2;

	if (lst == NULL || f == NULL)
		return (NULL);
	tmp2 = (*f)(lst);
	if (!(new = ft_lstnew(tmp2->content, tmp2->content_size)))
		return (NULL);
	lst = lst->next;
	tmp = new;
	while (lst != NULL)
	{
		tmp2 = (*f)(lst);
		if (!(new->next = ft_lstnew(tmp2->content, tmp2->content_size)))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (tmp);
}

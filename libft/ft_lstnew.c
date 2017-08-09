/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 06:35:41 by jpascal           #+#    #+#             */
/*   Updated: 2016/11/25 06:37:09 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	if (!(tmp = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (content == NULL)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	else
	{
		if (!(tmp->content = (void*)malloc(sizeof(content) * content_size)))
			return (0);
		ft_memmove((tmp->content), content, content_size);
		tmp->content_size = content_size;
	}
	tmp->next = 0;
	return (tmp);
}

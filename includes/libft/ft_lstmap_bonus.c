/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:22:36 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/29 19:22:36 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_items	*ft_lstmap(t_items *lst, void *(*f)(void *), void (*del)(void *))
{
	t_items	*head;
	t_items	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_node = NULL;
	head = new_node;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->y), f(lst->x));
		if (new_node == NULL)
		{
			ft_lstclear(&new_node, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new_node);
		lst = lst->next;
	}
	return (head);
}

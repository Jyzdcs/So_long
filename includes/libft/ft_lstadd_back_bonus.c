/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:36:33 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/29 18:36:33 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_node = *lst;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = new;
}
/*
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_list *node1 = ft_lstnew(argv[1]);
	t_list *node2 = ft_lstnew(argv[2]);
	t_list *node3 = ft_lstnew(argv[3]);
	t_list *node4 = ft_lstnew(argv[4]);
	t_list *node5 = ft_lstnew(argv[5]);
	t_list **head = node1;
	ft_lstadd_back(&node1, node3);
	ft_lstadd_back(&node1, node4);

	t_list	*last = ft_lstlast(*head);
	printf("Ancien dernier : %s\n", (char *)last->content);
	ft_lstadd_back(head, node5);
	last = ft_lstlast(*head);
	printf("nouveau dernier : %s\n", (char *)last->content);

}*/
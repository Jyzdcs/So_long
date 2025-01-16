/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:29:03 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/29 18:29:03 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL || lst->next == NULL)
		return (lst);
	return (ft_lstlast(lst->next));
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
	t_list	*tmp;
	ft_lstadd_front(&node1, node2);
	ft_lstadd_front(&node1, node3);
	ft_lstadd_front(&node1, node4);
	tmp = node1;
	while (tmp != NULL)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	t_list	*last = ft_lstlast(node1);
	printf("last : %s\n", (char *)last->content);
}
*/
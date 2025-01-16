/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:50:12 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/29 16:50:12 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	t_list	**head;
	t_list	*node1 = ft_lstnew("salut");
	t_list	*node2 = ft_lstnew("Bonjour");

	printf("%s\n", (char *)node1->content);
	ft_lstadd_front(&node1, node2);
	printf("%s\n", (char *)node1->content);
}*/
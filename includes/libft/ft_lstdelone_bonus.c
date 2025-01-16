/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:44:51 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/29 18:44:51 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
	{
		free(lst);
		return ;
	}
	if (!del)
		return ;
	del(lst->content);
	free(lst);
}
/*
t_list	*ft_create_elem(void *data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = data;
	node->next = NULL;
	return (node);
}

t_list	*list(char **tab, int size)
{
	t_list	*node;

	node = ft_create_elem(tab[size - 1]);
	if (size == 1)
		return (node);
	node->next = list(tab, size - 1);
	return (node);
}

int	main(int argc, char *argv[])
{
	t_list	*node = list(&argv[1], argc - 1);
	t_list	*tmp = node;

	while (tmp != NULL)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	ft_lstdelon(node, free);
	tmp = node;
	while (tmp != NULL)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
}*/
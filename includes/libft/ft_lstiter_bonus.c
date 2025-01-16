/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:12:31 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/29 19:12:31 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL)
		return ;
	f(lst->content);
	ft_lstiter(lst->next, f);
}
/*
void print_content(void *content)
{
	printf("%s\n", (char *)content);
}

int main()
{
	t_list *list = ft_lstnew("Element 1");
	list->next = ft_lstnew("Element 2");
	list->next->next = ft_lstnew("Element 3");

	ft_lstiter(list, print_content);

	// Libération de la mémoire (à implémenter si nécessaire)
	return 0;
}*/
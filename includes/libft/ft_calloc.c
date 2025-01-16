/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:18:19 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/24 17:18:19 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void			*tab;

	if (elementCount * elementSize > SIZE_MAX)
		return (NULL);
	tab = malloc(elementSize * elementCount);
	if (tab == NULL)
		return (NULL);
	ft_bzero(tab, elementCount * elementSize);
	return (tab);
}
/*
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int i = 9;
	int j = 0;
	int *tab = (int *)ft_calloc(i, 8);
	while (i)
	{
		printf("%d", tab[j]);
		j++;
		i--;
	}
	printf("\n%d", j);
	free(tab);
}*/
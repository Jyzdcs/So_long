/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:01:40 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/27 18:01:40 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	find_size(long number)
{
	long	size;

	size = 0;
	if (number == 0)
		return (1);
	if (number < 0)
	{
		size++;
		number = number * (-1);
	}
	while (number > 0)
	{
		number = number / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int nb)
{
	long		nbr;
	long		i;
	char		*tab;

	nbr = nb;
	tab = malloc(sizeof(char) * find_size(nbr) + 1);
	if (!tab)
		return (NULL);
	i = find_size(nbr) - 1;
	tab[i + 1] = '\0';
	if (nbr == 0)
		tab[0] = '0';
	if (nbr < 0)
	{
		tab[0] = '-';
		nbr = nbr * (-1);
	}
	while (nbr > 0)
	{
		tab[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i--;
	}
	return (tab);
}
/*
int	main(int ac, char **av)
{
	char *str = ft_itoa(atoi(av[1]));
	printf("%s\n", str);
	free(str);
}*/
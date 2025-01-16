/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:18:36 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/31 13:18:36 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*el_s1;
	const unsigned char	*el_s2;

	el_s1 = s1;
	el_s2 = s2;
	while (n)
	{
		if (*el_s1 != *el_s2)
			return (*el_s1 - *el_s2);
		n--;
		el_s1++;
		el_s2++;
	}
	return (0);
}
/*
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	char *s1 = av[1];
	char *s2 = av[2];
	printf("%d\n", ft_memcmp(s1, s2, 10));
}
*/
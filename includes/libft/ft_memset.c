/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 01:49:35 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/26 01:49:35 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*el;

	el = s;
	while (n)
	{
		*el = c;
		el++;
		n--;
	}
	return (s);
}
/*typedef struct t_list
{
	char *name;
	int age;
} t_list;

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	t_list s1;
	s1.age = 153;
	s1.name = "d";
	t_list s2;
	ft_memset(&s1, 0, 0);
	printf("%ld", sizeof(s1.name));
}*/
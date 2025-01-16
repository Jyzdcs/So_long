/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:51:33 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/25 23:51:33 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_b;
	unsigned char		*dest_b;

	if (!dest && !src)
		return (NULL);
	dest_b = dest;
	src_b = src;
	while (n)
	{
		*dest_b = *src_b;
		dest_b++;
		src_b++;
		n--;
	}
	return (dest);
}
/*
typedef struct t_list
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
	s1.age = 145;
	s1.name = "BILLY";
	t_list s2;
	ft_memcpy(&s2, &s1, sizeof(t_list));
	printf("%d, %s\n", s2.age, s2.name);
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:38:59 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/24 15:38:59 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*v = s;
	unsigned char		uc;

	uc = c;
	while (n)
	{
		if (*v == uc)
			return ((unsigned char *)v);
		n--;
		v++;
	}
	return (NULL);
}
/*
** #include <stdio.h>
** #include <string.h>
** 
** int main() {
** 	const char str[] = "Hello, world!";
** 
** 	printf("Le caractère 'w' a été trouvé à la position : %ld\n"
, (char*)ft_memchr(str, 'w', strlen(str)) - str);
** }
*/
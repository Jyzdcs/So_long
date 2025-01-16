/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:32:04 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/26 17:32:04 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("Test de ft_toupper :\n");
	printf("a -> %c\n", ft_toupper('a'));
	printf("z -> %c\n", ft_toupper('z'));
	printf("A -> %c\n", ft_toupper('A'));
	printf("Z -> %c\n", ft_toupper('Z'));
	printf("0 -> %c\n", ft_toupper('0'));
	printf("@ -> %c\n", ft_toupper('@'));
	return (0);
}
*/
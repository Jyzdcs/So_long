/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:26:31 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/26 17:26:31 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("Test de ft_tolower :\n");
	printf("A -> %c\n", ft_tolower('A'));
	printf("Z -> %c\n", ft_tolower('Z'));
	printf("a -> %c\n", ft_tolower('a'));
	printf("z -> %c\n", ft_tolower('z'));
	printf("0 -> %c\n", ft_tolower('0'));
	printf("@ -> %c\n", ft_tolower('@'));
	return (0);
}
*/
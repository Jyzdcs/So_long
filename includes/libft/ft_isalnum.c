/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:33:32 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/24 13:33:32 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	return ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z')
		|| (c >= '0' && '9' >= c));
}

/*
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int	main(__attribute__((unused))int ac, char **av)
{
	printf("%d", ft_isalnum(av[1][0]));
}*/

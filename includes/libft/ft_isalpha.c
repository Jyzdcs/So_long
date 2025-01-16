/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:25:29 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/24 13:25:29 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
/*
** #include <stdio.h>
** int	main(__attribute__((unused))int argc, char *argv[])
** {
** 	if (ft_isalpha(argv[1][0]))
** 		printf("1\n");
** 	else
** 		printf("2\n");
** }
*/
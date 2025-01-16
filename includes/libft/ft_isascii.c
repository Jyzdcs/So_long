/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:50:02 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/24 13:50:02 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
** #include <stdlib.h>
** #include <string.h>
** #include <stdio.h>
** int	main(__attribute__((unused))int argc, char *argv[])
** {
** 	if (ft_isascii(128))
** 		printf("1\n");
** 	else
** 		printf("2\n");
** }
*/
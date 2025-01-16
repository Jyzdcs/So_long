/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:04:45 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/24 14:04:45 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}
/*
** #include <stdlib.h>
** #include <string.h>
** #include <stdio.h>
** 
** int	main(int ac, char **av)
** {
** 	(void)ac;
** 	printf("%d", av[1][0]);
** }
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:26:13 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/25 23:26:13 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*el;

	el = s;
	while (n)
	{
		*el = 0;
		el++;
		n--;
	}
}
/*
** #include <stdio.h>
** 
** int	main(int ac, char **av)
** {
** 	(void)ac;
** 	char *ptr = malloc(sizeof(char) * 6);
** 	if (ptr == NULL)
** 		printf("000000000\n");
** 	printf("%s", ptr);
** 	printf("\n\n");
** 	bzero((void*)ptr, 5);
** 	printf("%s", ptr);
** }
*/
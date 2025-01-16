/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:10:13 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/29 13:10:13 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <fcntl.h>
int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int	nb_read;
	char buffer[100];

	int fd = open("test.txt", O_WRONLY | O_RDONLY);
	printf("fd : %d\n", fd);
	ft_putchar_fd('a', fd);
	close(fd);
	fd = open("test.txt", O_RDONLY);
	nb_read = read(fd, buffer, 1);
	if (nb_read == -1)
	{
		printf("ERROR\n");
		return 1;
	}
	printf("%s\n", buffer);
	close(fd);
}
*/
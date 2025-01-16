/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:10:07 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/29 15:10:07 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/*
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	(void)ac;
	int	fd;
	char	buffer[100];
	char	s[100] = "YOP TLMD cest BOUZy";

	fd = open("test.txt", O_WRONLY | O_RDONLY);
	ft_putendl_fd(s, fd);
	ft_putendl_fd(s, fd);
	close(fd);

	fd = open("test.txt", O_WRONLY | O_RDONLY);
	ft_putendl_fd("BONJOUR TLMD", fd);

	printf("%s", buffer);
}*/
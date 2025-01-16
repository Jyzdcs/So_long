/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:15:01 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/29 15:15:01 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}
/*
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	(void)ac;
	char	tab[100] = "salut tlmd ceci est un test";
	int	fd;
	char	buffer[100] = "";

	fd = open("test.txt", O_WRONLY);
	ft_putstr_fd(tab, fd);
	close(fd);

	fd = open("test.txt", O_RDONLY);
	read(fd, buffer, 20);
	printf("%s\n", buffer);
	close(fd);

}*/
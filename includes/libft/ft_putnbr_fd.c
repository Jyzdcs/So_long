/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:45:41 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/29 15:45:41 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr_fd("-2147483648", fd);
			return ;
		}
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
		return ;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
		return ;
	}
	ft_putchar_fd(n + '0', fd);
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
	char	s;

	fd = open("test.txt", O_WRONLY);
	ft_putnbr_fd(-1234235, fd);
	close(fd);
}
*/
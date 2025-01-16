/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:06:33 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/26 16:06:33 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *sub, size_t len)
{
	size_t	i;
	int		j;

	if ((!str || !sub) && len == 0)
		return (NULL);
	if (*sub == '\0')
		return ((char *)str);
	i = 0;
	while (i < len && str[i])
	{
		j = 0;
		while (i + j < len && sub[j] == str[i + j])
		{
			j++;
			if (sub[j] == '\0')
				return ((char *)(str + (i)));
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	const char *s1 = "Bardock est semblable";
	const char *s2 = "rdock es";
	const char *str;
	if (!(str = ft_strnstr(av[1], av[2], atoi(av[3]))))
		printf("NULL");
	else
		printf(("%s\n"), str);
}
*/
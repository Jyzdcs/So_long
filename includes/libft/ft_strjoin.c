/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:22:05 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/27 15:22:05 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		i;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	tab = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (tab == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		tab[i] = s1[i];
	k = -1;
	while (s2[++k])
		tab[i++] = s2[k];
	tab[i] = '\0';
	return (tab);
}
/*
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	const char *s1 = "Bonjour ";
	const char *s2 = "ca va ?";
	char *join = ft_strjoin(s1, s2);
	printf("%s\n", join);
}*/
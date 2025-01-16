/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:59:14 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/27 14:59:14 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Cette fonction extrait une sous-chaîne d'une chaîne donnée.
Elle prend en compte une position de départ et une longueur spécifiées.
Utile pour isoler une partie spécifique d'une chaîne de caractères.
Elle alloue de la mémoire pour la nouvelle sous-chaîne et la retourne.
Équivalent à une combinaison de malloc et strncpy de la bibliothèque standard C.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	tab = malloc(sizeof(char) * (len + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start])
		tab[i++] = s[start++];
	tab[len] = '\0';
	return (tab);
}
/*
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	char *sb = ft_substr(av[1], (unsigned int)atoi(av[2]), (size_t)atoi(av[3]));
	printf("%d\n", strcmp(sb, ""));
	printf("%s\n", sb);
}
*/
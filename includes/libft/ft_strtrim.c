/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:50:18 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/27 15:50:18 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Cette fonction supprime les caractères spécifiés
au début et à la fin d'une chaîne.
Elle est utile pour nettoyer une chaîne
des espaces ou caractères indésirables.
Elle alloue une nouvelle chaîne et la retourne.
C'est comme une version améliorée de trim
qui permet de spécifier les caractères à enlever.
*/

#include "libft.h"

static int	is_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	int		len;
	char	*tab;

	if (!s1)
		return (ft_strdup(""));
	len = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	while (is_set(s1[start], set))
		start++;
	while (is_set(s1[end], set) && end >= start)
		end--;
	len = end - start + 1;
	tab = malloc(sizeof(char) * (len + 1));
	if (tab == NULL)
		return (NULL);
	ft_memcpy(tab, &s1[start], len);
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
	char *filt = ft_strtrim(av[1], av[2]);
	printf("filt : %s\n", filt);
}
*/
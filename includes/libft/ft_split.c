/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:25:19 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/27 16:25:19 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char sep)
{
	int	i;
	int	counter;

	counter = 0;
	if (s[0] != sep)
		counter = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] != sep && s[i - 1] == sep)
			counter++;
		i++;
	}
	return (counter);
}

char	*alloc_word_memory(char const *s, char sep)
{
	int		i;
	int		len;
	char	*tab;

	len = 0;
	while (s[len] != sep && s[len])
		len++;
	tab = malloc(sizeof(char) * len + 1);
	if (tab == NULL)
		return (NULL);
	i = -1;
	while (s[++i] != sep && s[i])
		tab[i] = s[i];
	tab[i] = '\0';
	return (tab);
}

char	**free_all_ptr(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int			i;
	int			k;
	int const	nbr_of_words = count_words(s, c);
	char		**tab;

	tab = malloc(sizeof(char *) * nbr_of_words + 1);
	if (tab == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			tab[k] = alloc_word_memory(&s[i], c);
			if (tab[k++] == NULL)
				return (free_all_ptr(tab));
			while (s[i] != c && s[i])
				i++;
		}
	}
	tab[k] = NULL;
	return (tab);
}
/*
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	char **tab = ft_split("hello!", ' ');
	int i = 0;
	while (tab[i] != NULL)
	{
		printf("%s", tab[i]);
		i++;
	}
}*/
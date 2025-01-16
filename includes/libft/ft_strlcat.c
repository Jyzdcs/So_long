/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:38:12 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/24 14:38:12 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	len_src;
	unsigned int	len_dst;

	if (!dest && size == 0)
		return (0);
	i = 0;
	len_src = ft_strlen(src);
	len_dst = ft_strlen((const char *)dest);
	if (size <= len_dst)
		return (size + len_src);
	while (src[i] && (i < size - len_dst - 1))
	{
		dest[i + len_dst] = src[i];
		i++;
	}
	dest[i + len_dst] = '\0';
	return (len_dst + len_src);
}
/*
#include <stdio.h>
int     main(void)
{
        char dest[18] = "Lucas";
        char src[20] = " kylian goat";
        printf("%lu\n%s", ft_strlcat(dest, src, 0), dest);
}
*/
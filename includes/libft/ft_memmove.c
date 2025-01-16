/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:35:22 by kclaudan          #+#    #+#             */
/*   Updated: 2024/10/26 17:35:22 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_el;
	unsigned char		*dest_el;

	if (!dest && !src)
		return (NULL);
	if (dest < src)
	{
		src_el = src;
		dest_el = dest;
		while (n--)
			*dest_el++ = *src_el++;
	}
	else
	{
		src_el = src + n;
		dest_el = dest + n;
		while (n--)
			*--dest_el = *--src_el;
	}
	return (dest);
}
/*
#include <string.h>
int main() {
    char str[50] = "123456789bewyir";
    char buffer[50];
    
    printf("Résultat avant memmove: %s\n", str);
    // Copie avec chevauchement: source et destination se chevauchent
    memmove(str + 5, str, 9);

    printf("Résultat après memmove: %s\n", str);
    return 0;
}
*/
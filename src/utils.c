/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:00:25 by kclaudan          #+#    #+#             */
/*   Updated: 2025/02/10 18:45:19 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(const char *str)
{
	perror(str);
	return (FALSE);
}

int	x_pos(char target, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == target)
				return (j);
			j++;
		}
		i++;
	}
	return (-1);
}

int	y_pos(char target, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == target)
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int	custom_rand(void)
{
	static unsigned int	seed = 42;

	seed = (1103515245 * seed + 12345) % 2147483648;
	return (seed);
}

int	get_random_direction(void)
{
	int	directions[4];

	directions[0] = RIGHT;
	directions[1] = UP;
	directions[2] = LEFT;
	directions[3] = DOWN;
	return (directions[custom_rand() % 4]);
}

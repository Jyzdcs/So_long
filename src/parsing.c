/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:01:44 by kclaudan          #+#    #+#             */
/*   Updated: 2025/02/10 17:47:45 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_borders(char **map, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (i == 0 && map[i][j] != '1')
				return (TRUE);
			if (j == 0 && map[i][j] != '1')
				return (TRUE);
			if (j == width - 1 && map[i][j] != '1')
				return (TRUE);
			if (i == height - 1 && map[i][j] != '1')
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

int	is_rect(char **map)
{
	int	i;
	int	j;
	int	width;
	int	height;

	i = 0;
	width = 0;
	while (map[i][width])
		width++;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j != width)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	is_valid_char(char c)
{
	return (c == 'P' || c == 'C' || c == 'E'
		|| c == '0' || c == '1' || c == 'G');
}

static int	check_special_chars(char **map, int *exit, int *item, int *player)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				*exit = 1;
			if (map[i][j] == 'C')
				*item = 1;
			if (map[i][j] == 'P')
				*player = 1;
			if (!is_valid_char(map[i][j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	is_valid(char **map, t_game *game)
{
	int	exit;
	int	item;
	int	player;

	exit = 0;
	item = 0;
	player = 0;
	if (!check_special_chars(map, &exit, &item, &player))
		return (FALSE);
	if (!is_rect(map) || check_borders(map, game->map_height, game->map_width)
		|| !exit || !item || !player
		|| !is_map_feasible(map, x_pos('P', map), y_pos('P', map), game))
		return (FALSE);
	return (TRUE);
}

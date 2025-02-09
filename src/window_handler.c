/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:43:56 by kclaudan          #+#    #+#             */
/*   Updated: 2025/02/08 22:43:56 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	free_all_ptr((void **)game->map);
	if (game->index != 0)
		free_all_ptr((void **)game->enemies);
	exit(0);
	return (0);
}

int	get_extension(char *str)
{
	int		i;
	char	**path;
	char	**file_name;

	i = 0;
	path = ft_split(str, '/');
	if (!path)
		return (1);
	while (path[i + 1])
		i++;
	file_name = ft_split(path[i], '.');
	if (!file_name)
		return (1);
	i = 0;
	while (file_name[i + 1])
		i++;
	if (ft_strcmp(file_name[i], "ber") != 0)
	{
		free_all_ptr((void **)path);
		free_all_ptr((void **)file_name);
		return (1);
	}
	free_all_ptr((void **)path);
	free_all_ptr((void **)file_name);
	return (0);
}

int	nbr_of_ghost(char **map)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'G')
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
} 
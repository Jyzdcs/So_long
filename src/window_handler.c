/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/02/08 22:43:56 by kclaudan          #+#    #+#             */
/*   Updated: 2025/02/08 22:43:56 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	close_window(t_game *game)
{
	if (game->mlx && game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map)
		free_all_ptr((void **)game->map);
	if (game->enemies)
		free_all_ptr((void **)game->enemies);
	exit(0);
	return (0);
}

int	get_extension(char *file_path)
{
	size_t len;
	char *dot;

	if (!file_path)
		return (1);
	len = ft_strlen(file_path);
	if (len < 5)
		return (1);
	dot = ft_strrchr(file_path, '.');
	if (!dot || dot == file_path)
		return (1);
	if (ft_strcmp(dot, ".ber") != 0)
		return (1);
	return (0);
}

int	nbr_of_ghost(char **map)
{
	int i;
	int j;
	int counter;

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

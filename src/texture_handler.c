/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:43:56 by kclaudan          #+#    #+#             */
/*   Updated: 2025/02/08 22:43:56 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_texture(t_game *game, int y, int x, char *path)
{
	t_texture	texture;

	texture.img = mlx_xpm_file_to_image(game->mlx, path,
			&(game->player.width), &(game->player.height));
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		texture.img, x * 32, y * 32);
	mlx_destroy_image(game->mlx, texture.img);
}

void	init_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '1')
				place_texture(game, y, x, "../textures/Walls/wall.xpm");
			else if (game->map[y][x] == 'P')
				init_player(game, y, x);
			else if (game->map[y][x] == 'G')
				init_ennemie(game, y, x);
			else if (game->map[y][x] == 'E')
				place_texture(game, y, x, "../textures/exit.xpm");
			else if (game->map[y][x] == 'C')
			{
				place_texture(game, y, x, "../textures/pacdot_food.xpm");
				game->total_items++;
			}
		}
		y++;
	}
}

int	calcul_dim(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

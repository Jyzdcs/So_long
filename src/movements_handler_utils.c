/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_handler_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:10:54 by kclaudan          #+#    #+#             */
/*   Updated: 2025/02/10 19:10:54 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement_select(t_game *game, int direction)
{
	t_texture	player;
	char		*texture_path;

	if (direction == UP)
		texture_path = "../textures/pac_semi_up.xpm";
	else if (direction == DOWN)
		texture_path = "../textures/pac_semi_down.xpm";
	else if (direction == RIGHT)
		texture_path = "../textures/pac_semi_right.xpm";
	else
		texture_path = "../textures/pac_semi_left.xpm";
	player.img = mlx_xpm_file_to_image(game->mlx, texture_path,
			&(game->player.height), &(game->player.width));
	if (!player.img)
		return ((void)close_window(game));
	mlx_put_image_to_window(game->mlx, game->mlx_win, player.img,
		game->player.x * 32, game->player.y * 32);
	mlx_destroy_image(game->mlx, player.img);
}

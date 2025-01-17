/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:50:22 by kclaudan          #+#    #+#             */
/*   Updated: 2025/01/17 16:28:39 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_hook(int keycode, t_game *game)
{
	t_texture	eraser;

	eraser = fill_square(game->mlx, 30, 30, 0x00000000);
    mlx_put_image_to_window(game->mlx, game->mlx_win, eraser.img, game->player.x, game->player.y);
	game->player.old_x = game->player.x;
	game->player.old_y = game->player.y;
	if (keycode == 13)
		game->player.y -= 30;
	else if (keycode == 1)
		game->player.y += 30;
	else if (keycode == 0)
		game->player.x -= 30;
	else if (keycode == 2)
		game->player.x += 30;
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->player.img.img, game->player.x, game->player.y);
	printf("MOVE\n");
	return (0);
}
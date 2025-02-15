/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:50:22 by kclaudan          #+#    #+#             */
/*   Updated: 2025/01/29 12:38:53 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void update_player_position(t_game *game, int new_x, int new_y)
{
	t_texture eraser;

	eraser = fill_square(game->mlx, 32, 32, 0x00000000);
	game->player.old_x = game->player.x;
	game->player.old_y = game->player.y;
	game->player.x = new_x;
	game->player.y = new_y;
	mlx_put_image_to_window(game->mlx, game->mlx_win, eraser.img,
		game->player.old_x * 32, game->player.old_y * 32);
}

static void handle_collectible_and_exit(t_game *game)
{
	if (game->map[game->player.y][game->player.x] == 'C'
		&& game->player.items != game->total_items)
	{
		game->player.items++;
		game->map[game->player.y][game->player.x] = '0';
	}
	if (game->map[game->player.old_y][game->player.old_x] == 'E')
		place_texture(game, game->player.old_y * 32, game->player.old_x * 32, "../textures/exit.xpm");
}

static void update_hitbox(t_game *game, int direction)
{
	if (direction == UP || direction == DOWN)
	{
		if (direction == DOWN)
		{
			game->player.hitbox.bot_y += 1;
			game->player.hitbox.top_y += 1;
		}
		else
		{
			game->player.hitbox.bot_y -= 1;
			game->player.hitbox.top_y -= 1;
		}
	}
	else if (direction == LEFT || direction == RIGHT)
	{
		if (direction == RIGHT)
		{
			game->player.hitbox.front_x += 1;
			game->player.hitbox.back_x += 1;
		}
		else
		{
			game->player.hitbox.front_x -= 1;
			game->player.hitbox.back_x -= 1;
		}
	}
}

void	movement_select(t_game *game, int direction)
{
	t_texture player;

	if (direction == UP)
	{
		player.img = mlx_xpm_file_to_image(game->mlx, "../textures/pac_semi_up.xpm", &(game->player.height), &(game->player.width));
		mlx_put_image_to_window(game->mlx, game->mlx_win, player.img,
			game->player.x * 32, game->player.y * 32);
	}
	else if (direction == DOWN)
	{
		player.img = mlx_xpm_file_to_image(game->mlx, "../textures/pac_semi_down.xpm", &(game->player.height), &(game->player.width));
		mlx_put_image_to_window(game->mlx, game->mlx_win, player.img,
			game->player.x * 32, game->player.y * 32);
	}
	else if (direction == RIGHT)
	{
		player.img = mlx_xpm_file_to_image(game->mlx, "../textures/pac_semi_right.xpm", &(game->player.height), &(game->player.width));
		mlx_put_image_to_window(game->mlx, game->mlx_win, player.img,
			game->player.x * 32, game->player.y * 32);
	}
	else if (direction == LEFT)
	{
		player.img = mlx_xpm_file_to_image(game->mlx, "../textures/pac_semi_left.xpm", &(game->player.height), &(game->player.width));
		mlx_put_image_to_window(game->mlx, game->mlx_win, player.img,
			game->player.x * 32, game->player.y * 32);
	}
}

static int move_player(t_game *game, int direction)
{
	if (direction == UP && game->map[game->player.hitbox.top_y][game->player.x] != '1')
		update_player_position(game, game->player.x, game->player.y - 1);
	else if (direction == DOWN && game->map[game->player.hitbox.bot_y][game->player.x] != '1')
		update_player_position(game, game->player.x, game->player.y + 1);
	else if (direction == LEFT && game->map[game->player.y][game->player.hitbox.back_x] != '1')
		update_player_position(game, game->player.x - 1, game->player.y);
	else if (direction == RIGHT && game->map[game->player.y][game->player.hitbox.front_x] != '1')
		update_player_position(game, game->player.x + 1, game->player.y);
	else
		return (0);
	handle_collectible_and_exit(game);
	update_hitbox(game, direction);
	movement_select(game, direction);
	return (1);
}

int key_hook(int keycode, t_game *game)
{
	int moved;

	moved = 0;
	if (keycode == ESC)
		close_window(game);
	else if (keycode == W_KEY || keycode == UP_ARROW)
		moved = move_player(game, UP);
	else if (keycode == S_KEY || keycode == DOWN_ARROW)
		moved = move_player(game, DOWN);
	else if (keycode == A_KEY || keycode == LEFT_ARROW)
		moved = move_player(game, LEFT);
	else if (keycode == D_KEY || keycode == RIGHT_ARROW)
		moved = move_player(game, RIGHT);
	if (moved && game->map[game->player.y][game->player.x] == 'E'
		&& game->player.items == game->total_items)
		close_window(game);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:44:01 by kclaudan          #+#    #+#             */
/*   Updated: 2025/01/16 19:26:17 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	write_front_line(t_data img, int width)
{
	int	x;

	x = 0;
	while (x < width)
		my_mlx_pixel_put(&img, x++, 0, 0x00FF0000);
}

void	write_back_line(t_data img, int width, int y)
{
	int	x;

	x = width;
	while (x > 0)
		my_mlx_pixel_put(&img, x--, y, 0x00FF0000);
}

void	write_vertical_line(t_data img, int height, int x)
{
	int	y;

	y = 0;
	while (y < height)
		my_mlx_pixel_put(&img, x, y++, 0x00FF0000);
}

void	make_square(t_data img, int width, int height)
{
	write_front_line(img, width);
	write_back_line(img, width, height);
	write_vertical_line(img, height, 0);
	write_vertical_line(img, height, width);
}

t_data	fill_square(void *mlx, int width, int height, int color)
{
	t_data	fill;
	int		y;
	int		x;

	fill.img = mlx_new_image(mlx, width, height);
	fill.addr = mlx_get_data_addr(fill.img, &fill.bits_per_pixel, &fill.line_length,
								&fill.endian);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
			my_mlx_pixel_put(&fill, x++, y, color);
		y++;
	}
	return (fill);
}

int key_hook(int keycode, t_player *player) {
	if (keycode == 13)
	{
		player->old_x = player->x;
		player->old_y = player->y;
		player->y -= 30;
	}
	else if (keycode == 1)
	{
		player->old_x = player->x;
		player->old_y = player->y;
		player->y += 30;
	}
	else if (keycode == 0)
	{
		player->old_y = player->y;
		player->old_x = player->x;
		player->x -= 30;
	}
	else if (keycode == 2)
	{
		player->old_y = player->y;
		player->old_x = player->x;
		player->x += 30;
	}
	printf("UPDATE\n");
	return (0);
}

int update_game(t_game *game)
{
	t_data	eraser;

	eraser = fill_square(game->mlx, 30, 30, 0x00000000);
    mlx_put_image_to_window(game->mlx, game->mlx_win, eraser.img, game->player.old_x, game->player.old_y);
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->player.img.img, game->player.x, game->player.y);
    return (0);
}

int	main(void)
{
	t_game	game;


	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, 620, 480, "Hello world!");
	game.player.x = 50;
	game.player.y = 50;
	game.player.old_x = 50;
	game.player.old_y = 50;
	game.player.img = fill_square(game.mlx, 30, 30, 0x00FF0000);
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.player.img.img, game.player.x, game.player.y);
	mlx_hook(game.mlx_win, 2, 1L<<0, key_hook, &game.player);
	mlx_loop_hook(game.mlx, update_game, &game);
	mlx_loop(game.mlx);
}

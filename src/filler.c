/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:29:19 by kclaudan          #+#    #+#             */
/*   Updated: 2025/01/17 16:29:32 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_texture *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	write_front_line(t_texture img, int width)
{
	int	x;

	x = 0;
	while (x < width)
		my_mlx_pixel_put(&img, x++, 0, 0x00FF0000);
}

void	write_back_line(t_texture img, int width, int y)
{
	int	x;

	x = width;
	while (x > 0)
		my_mlx_pixel_put(&img, x--, y, 0x00FF0000);
}

void	write_vertical_line(t_texture img, int height, int x)
{
	int	y;

	y = 0;
	while (y < height)
		my_mlx_pixel_put(&img, x, y++, 0x00FF0000);
}

void	make_square(t_texture img, int width, int height)
{
	write_front_line(img, width);
	write_back_line(img, width, height);
	write_vertical_line(img, height, 0);
	write_vertical_line(img, height, width);
}

t_texture	fill_square(void *mlx, int width, int height, int color)
{
	t_texture	fill;
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
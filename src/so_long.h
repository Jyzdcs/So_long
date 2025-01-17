/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:29:25 by kclaudan          #+#    #+#             */
/*   Updated: 2025/01/17 16:48:26 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdio.h>
# include "../includes/libft/libft.h"
# include "../minilibx_opengl_20191021/mlx.h"


typedef struct	s_texture {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_texture;

typedef struct	win_dim {
	int	width;
	int height;
}				t_wind_dim;

typedef struct	s_player
{
	int	x;
	int	y;
	int	old_x;
	int	old_y;
	int movements;
	int	items;
	int score;
	t_texture img;
}		t_player;

typedef struct s_game {
    void *mlx;
    void *mlx_win;
    t_player player;
} t_game;

void	my_mlx_pixel_put(t_texture *data, int x, int y, int color);
void	write_front_line(t_texture img, int width);
void	write_back_line(t_texture img, int width, int y);
void	write_vertical_line(t_texture img, int height, int x);
void	make_square(t_texture img, int width, int height);
t_texture	fill_square(void *mlx, int width, int height, int color);
int key_hook(int keycode, t_game *game);

#endif
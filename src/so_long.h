/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:29:25 by kclaudan          #+#    #+#             */
/*   Updated: 2025/01/16 18:58:34 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdio.h>
# include "../includes/libft/libft.h"
# include "../minilibx_opengl_20191021/mlx.h"


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_player
{
	int	x;
	int	y;
	int	old_x;
	int	old_y;
	int movements;
	int	items;
	int score;
	t_data img;
}		t_player;

typedef struct s_game {
    void *mlx;
    void *mlx_win;
    t_player player;
} t_game;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:29:25 by kclaudan          #+#    #+#             */
/*   Updated: 2025/02/09 00:12:52 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include "../includes/libft/libft.h"
# include "../minilibx-linux/mlx.h"

# define TRUE 1
# define FALSE 0

/* Directions */
# define UP 1
# define DOWN 2
# define LEFT 3
# define RIGHT 4

/* Key codes */
# define ESC 53
# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2
# define UP_ARROW 126
# define DOWN_ARROW 125
# define LEFT_ARROW 123
# define RIGHT_ARROW 124

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_texture;

typedef struct s_enemie
{
	int		id;
	int		y;
	int		x;
	int		move;
	int		direction;
	void	*img;
}			t_enemie;

typedef struct s_win_dim
{
	int		width;
	int		height;
}			t_win_dim;

typedef struct s_hitbox
{
	int		top_y;
	int		bot_y;
	int		front_x;
	int		back_x;
}			t_hitbox;

typedef struct s_player
{
	int			x;
	int			y;
	int			old_x;
	int			old_y;
	int			width;
	int			height;
	int			movements;
	int			items;
	int			score;
	t_texture	img;
	t_hitbox	hitbox;
}			t_player;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	char		**map;
	int			map_height;
	int			map_width;
	int			total_items;
	t_enemie	**enemies;
	int			index;
	t_player	player;
}			t_game;

/* Function prototypes */
/* init_game.c */
void		init_player(t_game *game, int y, int x);
void		init_ennemie(t_game *game, int y, int x);
int			init_game(t_game *game);
int			init_map_dimensions(t_game *game);

/* window_handler.c */
int			close_window(t_game *game);
int			get_extension(char *str);
int			nbr_of_ghost(char **map);

/* texture_handler.c */
void		place_texture(t_game *game, int y, int x, char *path);
void		init_map(t_game *game);
int			calcul_dim(char **map);

/* movements_handler.c */
int			key_hook(int keycode, t_game *game);

/* enemies_handler.c */
int			update_enemies(t_game *game);

/* parsing.c */
int			is_valid(char **map, t_game *game);

/* utils.c */
void		my_mlx_pixel_put(t_texture *data, int x, int y, int color);
t_texture	fill_square(void *mlx, int width, int height, int color);
void		free_game_resources(t_game *game);
void		ft_error(const char *str);


#endif
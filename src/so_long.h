/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:29:25 by kclaudan          #+#    #+#             */
/*   Updated: 2025/02/10 19:12:19 by kclaudan         ###   ########.fr       */
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

// Directions
# define UP 1
# define DOWN 2
# define LEFT 3
# define RIGHT 4

// Key codes
# define ESC 65307
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363

typedef struct s_backtrack
{
	int			**visited;
	char		**map;
	t_items		*list;
}			t_backtrack;

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

/* utils.c */
int			ft_error(const char *str);
int			x_pos(char target, char **map);
int			y_pos(char target, char **map);
int			custom_rand(void);
int			get_random_direction(void);

/* movements_handler_utils.c */
void		movement_select(t_game *game, int direction);
/* movements_handler.c */
int			key_hook(int keycode, t_game *game);
/* init.c */
int			initialize_mlx(t_game *game);
/* enemies_handler_utils.c */
void		sprites_ghost(t_game *game, t_enemie *enemy, int direction);
int			check_collision(t_game *game, int i);
/* enemies_handler.c */
static void	handle_direction(t_game *game, char **map, int i, int move);
int			update_enemies(t_game *game);
/* backtracking.c */
int			**alloc_array_two_dim(char **map, t_game *game);
int			back_track(int y, int x, t_backtrack *bt);
int			is_map_feasible(char **map, int start_x, int start_y, t_game *game);
/* backtracking_utils.c */
int			is_valide_move(int y, int x, char **map, int **visited);
int			numbers_items(char **map);
int			not_visited(t_items *list, int y, int x);
int			rules_back_track(int y, int x, char **map, t_items **list);
int			try_move(int y, int x, t_backtrack *bt);

/* parsing.c */
int			is_valid(char **map, t_game *game);

/* filler.c */
void		my_mlx_pixel_put(t_texture *data, int x, int y, int color);
t_texture	fill_square(void *mlx, int width, int height, int color);

#endif
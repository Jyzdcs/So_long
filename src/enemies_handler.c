/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:30:22 by kclaudan          #+#    #+#             */
/*   Updated: 2025/01/28 16:34:22 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clear_enemy(t_game *game, int x, int y)
{
	t_texture	eraser;

	eraser = fill_square(game->mlx, 32, 32, 0x00000000);
	mlx_put_image_to_window(game->mlx, game->mlx_win, eraser.img,
		x * 32, y * 32);
}

static int	check_collision(t_game *game, int i)
{
	if (game->ennemies[i]->x == game->player.x
		&& game->ennemies[i]->y == game->player.y)
	{
		printf("Game Over! Ghost caught you!\n");
		close_window(game);
		return (1);
	}
	return (0);
}

static void move_horizontal(t_game *game, int i)
{
	game->ennemies[i]->direction = 1;
	clear_enemy(game, game->ennemies[i]->x, game->ennemies[i]->y);
	if (game->map[game->ennemies[i]->y][game->ennemies[i]->x] == 'C')
		place_texture(game, game->ennemies[i]->y, game->ennemies[i]->x, "../textures/Other/Pacdots/pacdot_food.xpm");
    if (game->map[game->ennemies[i]->y][game->ennemies[i]->x + game->ennemies[i]->move] == '1')
        game->ennemies[i]->move *= -1; // Inverse la direction
    game->ennemies[i]->x += game->ennemies[i]->move; // Déplace l'ennemi
	// game->map[game->ennemies[i]->y][game->ennemies[i]->x] = 'G';
}

static void move_vertical(t_game *game, int i)
{
	game->ennemies[i]->direction = 2;
	clear_enemy(game, game->ennemies[i]->x, game->ennemies[i]->y);
	if (game->map[game->ennemies[i]->y][game->ennemies[i]->x] == 'C')
		place_texture(game, game->ennemies[i]->y, game->ennemies[i]->x, "../textures/Other/Pacdots/pacdot_food.xpm");
    if (game->map[game->ennemies[i]->y + game->ennemies[i]->move][game->ennemies[i]->x] == '1')
        game->ennemies[i]->move *= -1; // Inverse la direction
    game->ennemies[i]->y += game->ennemies[i]->move; // Déplace l'ennemi
}

int	calcul_longest(char **map, t_ennemie *enemie)
{
	int	len_x;
	int	len_y;
	int	i;
	int	j;

	i = enemie->x;
	j = enemie->x;
	while (map[enemie->y][i] != '1')
		i++;
	while (map[enemie->y][j] != '1')
		j--;
	len_x = i + enemie->x - j;
	i = enemie->y;
	j = enemie->y;
	while (map[i][enemie->x] != '1')
		i++;
	while (map[j][enemie->x] != '1')
		j--;
	len_y = i + enemie->x - j;
	return (len_x >= len_y);
}

// void	semi_sprites(t_game *game, int i)
// {
// 	if (game->ennemies[i]->direction)
// 	{
// 		if ()
// 	}
// }

int	update_enemies(t_game *game)
{
	static int	update_counter = 0;
	int			i;

	update_counter++;
	if (update_counter % 900 != 0)
		return (1);
	i = 0;
	while (i < game->index)
	{
		if (calcul_longest(game->map, game->ennemies[i]))
			move_horizontal(game, i);
		else
			move_vertical(game, i);
		if (check_collision(game, i))
			return (0);
		// semi_sprites(game, i);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->ennemies[i]->img,
			game->ennemies[i]->x * 32,
			game->ennemies[i]->y * 32);
		i++;
	}
	return (1);
} 
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:30:22 by kclaudan          #+#    #+#             */
/*   Updated: 2025/01/29 12:36:37 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static unsigned int custom_seed = 42;

static int custom_rand(void)
{
    custom_seed = (1103515245 * custom_seed + 12345) % 2147483648;
    return (custom_seed);
}

static int get_random_direction(void)
{
    int directions[] = {RIGHT, UP, LEFT, DOWN};
    return (directions[custom_rand() % 4]);
}

void	sprites_ghost(t_game *game, t_enemie *enemy, int direction)
{
	int	size;

	size = 32;
	if (direction == DOWN)
		enemy->img = mlx_xpm_file_to_image(game->mlx, "../textures/R/ghost_down2.xpm", &size, &size);
	else if (direction == UP)
		enemy->img = mlx_xpm_file_to_image(game->mlx, "../textures/R/ghost_up2.xpm", &size, &size);
	else if (direction == RIGHT)
		enemy->img = mlx_xpm_file_to_image(game->mlx, "../textures/R/ghost_right2.xpm", &size, &size);
	else if (direction == LEFT)
		enemy->img = mlx_xpm_file_to_image(game->mlx, "../textures/R/ghost_left2.xpm", &size, &size);
}

static void clear_enemy(t_game *game, int i, int x, int y)
{
    t_texture eraser;

	eraser = fill_square(game->mlx, 32, 32, 0x00000000);
    mlx_put_image_to_window(game->mlx, game->mlx_win, eraser.img, x * 32, y * 32);
	if (game->map[game->enemies[i]->y][game->enemies[i]->x] == 'C')
		place_texture(game, game->enemies[i]->y, game->enemies[i]->x, "../textures/pacdot_food.xpm");
	if (game->map[game->enemies[i]->y][game->enemies[i]->x] == 'E')
		place_texture(game, game->enemies[i]->y, game->enemies[i]->x, "../textures/exit.xpm");
 }

static int check_collision(t_game *game, int i)
{
    if (game->enemies[i]->x == game->player.x && game->enemies[i]->y == game->player.y)
    {
        printf("Game Over! Ghost caught you!\n");
        close_window(game);
        return (1);
    }
    return (0);
}

void handle_move(t_game *game, char **map, int i, int move)
{
    clear_enemy(game, i, game->enemies[i]->x, game->enemies[i]->y);
    if (move == RIGHT && map[game->enemies[i]->y][game->enemies[i]->x + 1] != '1')
    {
        game->enemies[i]->x++;
        game->enemies[i]->move = RIGHT;
    }
    else if (move == UP && map[game->enemies[i]->y - 1][game->enemies[i]->x] != '1')
    {
        game->enemies[i]->y--;
        game->enemies[i]->move = UP;
    }
    else if (move == LEFT && map[game->enemies[i]->y][game->enemies[i]->x - 1] != '1')
    {
        game->enemies[i]->x--;
        game->enemies[i]->move = LEFT;
    }
    else if (move == DOWN && map[game->enemies[i]->y + 1][game->enemies[i]->x] != '1')
    {
        game->enemies[i]->y++;
        game->enemies[i]->move = DOWN;
    }
    else
        game->enemies[i]->direction = 1;
}

void handle_direction(t_game *game, char **map, int i, int move)
{
    int new_move;

    new_move = get_random_direction();
    if (new_move != move && new_move == RIGHT && map[game->enemies[i]->y][game->enemies[i]->x + 1] != '1')
        game->enemies[i]->move = RIGHT;
    else if (new_move != move && new_move == UP && map[game->enemies[i]->y - 1][game->enemies[i]->x] != '1')
        game->enemies[i]->move = UP;
    else if (new_move != move && new_move == LEFT && map[game->enemies[i]->y][game->enemies[i]->x - 1] != '1')
        game->enemies[i]->move = LEFT;
    else if (new_move != move && new_move == DOWN && map[game->enemies[i]->y + 1][game->enemies[i]->x] != '1')
        game->enemies[i]->move = DOWN;
    else
        game->enemies[i]->move = move;
    handle_move(game, map, i, game->enemies[i]->move);
    if (move != game->enemies[i]->move)
        game->enemies[i]->direction = 0;
}

int update_enemies(t_game *game)
{
	static int update_counter = 0;
	int i;

	update_counter++;
	if (update_counter % 2000 != 0)
		return (1);
	i = 0;
	while (i < game->index)
	{
		if (game->enemies[i]->direction)
			handle_direction(game, game->map, i, game->enemies[i]->move);
		else
			handle_move(game, game->map, i, game->enemies[i]->move);
		if (check_collision(game, i))
			return (0);
		sprites_ghost(game, game->enemies[i], game->enemies[i]->move);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->enemies[i]->img,
			game->enemies[i]->x * 32,
			game->enemies[i]->y * 32);
		i++;
	}
	return (1);
}
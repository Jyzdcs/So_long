/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:30:22 by kclaudan          #+#    #+#             */
/*   Updated: 2025/01/28 19:48:20 by kclaudan         ###   ########.fr       */
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

// static	void	change_direction(t_game *game, int i, int move, int sens)
// {
// 	if (move == LEFT)
// 	{
// 		if (game->map[game->ennemies[i]->y - 1][game->ennemies[i]->x] != '1')

// 	}
// }

static void move_horizontal(t_game *game, int i, int new_call)
{
	clear_enemy(game, game->ennemies[i]->x, game->ennemies[i]->y);
	if (game->map[game->ennemies[i]->y][game->ennemies[i]->x] == 'C')
		place_texture(game, game->ennemies[i]->y, game->ennemies[i]->x, "../textures/Other/Pacdots/pacdot_food.xpm");
    if (game->map[game->ennemies[i]->y][game->ennemies[i]->x + game->ennemies[i]->move] == '1')
	{
        game->ennemies[i]->move *= -1; // Inverse la direction
		game->ennemies[i]->direction = 1;
	}
	game->ennemies[i]->x += game->ennemies[i]->move; // Déplace l'ennemi
}

static void move_vertical(t_game *game, int i, int new_call)
{
	clear_enemy(game, game->ennemies[i]->x, game->ennemies[i]->y);
	if (game->map[game->ennemies[i]->y][game->ennemies[i]->x] == 'C')
		place_texture(game, game->ennemies[i]->y, game->ennemies[i]->x, "../textures/Other/Pacdots/pacdot_food.xpm");
    if (game->map[game->ennemies[i]->y + game->ennemies[i]->move][game->ennemies[i]->x] == '1')
        game->ennemies[i]->move *= -1; // Inverse la direction
    game->ennemies[i]->y += game->ennemies[i]->move; // Déplace l'ennemi
}

void	handle_direction(t_game *game, int i)
{
	clear_enemy(game, game->ennemies[i]->x, game->ennemies[i]->y);
	if (game->map[game->ennemies[i]->y - 1][game->ennemies[i]->x] != '1')
	{
		game->ennemies[i]->y--;
		game->ennemies[i]->move = UP;
	}
	else if (game->map[game->ennemies[i]->y][game->ennemies[i]->x - 1] != '1')
	{
		game->ennemies[i]->x--;
		game->ennemies[i]->move = LEFT;
	}
	else if (game->map[game->ennemies[i]->y + 1][game->ennemies[i]->x] != '1')
	{
		game->ennemies[i]->y++;
		game->ennemies[i]->move = DOWN;
	}
	else if (game->map[game->ennemies[i]->y][game->ennemies[i]->x + 1] != '1')
	{
		game->ennemies[i]->y++;
		game->ennemies[i]->move = RIGHT;
	}
}

int	hit_wall(t_game *game, int i)
{
	if (game->map[game->ennemies[i]->y - 1][game->ennemies[i]->x] == '1'
		&& game->ennemies[i]->move == UP)
		return (TRUE);
	if (game->map[game->ennemies[i]->y][game->ennemies[i]->x - 1] == '1'
		&& game->ennemies[i]->move == LEFT)
		return (TRUE);
	if (game->map[game->ennemies[i]->y + 1][game->ennemies[i]->x] == '1'
		&& game->ennemies[i]->move == DOWN)
		return (TRUE);
	if (game->map[game->ennemies[i]->y][game->ennemies[i]->x + 1] == '1'
		&& game->ennemies[i]->move == DOWN)
		return (TRUE);
}

int	update_enemies(t_game *game)
{
	static int	update_counter = 0;
	int			i;

	update_counter++;
	if (update_counter % 2000 != 0)
		return (1);
	i = 0;
	while (i < game->index)
	{
		if (!game->ennemies[i]->direction)
			handle_direction(game, i);
		if (hit_wall(game, i))
			game->ennemies[i]->direction = 1;
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



OBJECTIF PROCHAINE SEANCE :

Je suis parti sur une base de faire changer de direction a mes perso lorsquil touche un mur.

La theorie est la suivante :
- ma struct enemie contine direction
- quand direction passe a 1, on fait en sorte qu'a la prochaine intesection, on puisse changer directement
- apres ca on remet direction a 0 et on recommecne

2h

Deuxieme objectif :

Faire en sorte que selon le changement de direction, mes fantomes changes d'img, cela donnera un meilleur rendu

Cela devrait etre possible grace a la clé move qui contient la derniere action effectuer par le fantome

1h30

Tester tout les potentiel bug

Troisieme objectif :

Donner la possibiliter de fermer et kill le program quand on ferme a laide de la croix.
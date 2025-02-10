/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:43:56 by kclaudan          #+#    #+#             */
/*   Updated: 2025/02/08 22:43:56 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_game *game, int y, int x)
{
	game->player.x = x;
	game->player.y = y;
	game->player.width = 32;
	game->player.height = 32;
	game->player.items = 0;
	game->player.img.img = mlx_xpm_file_to_image(game->mlx,
			"../textures/pac_closed.xpm",
			&(game->player.width),
			&(game->player.height));
	if (!game->player.img.img)
		perror("ERROR OF FILE");
	game->player.hitbox.back_x = x - 1;
	game->player.hitbox.front_x = x + 1;
	game->player.hitbox.top_y = y - 1;
	game->player.hitbox.bot_y = y + 1;
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->player.img.img, x * 32, y * 32);
	mlx_destroy_image(game->mlx, game->player.img.img);
}

void	init_ennemie(t_game *game, int y, int x)
{
	t_enemie	*ghost;
	int			size;

	size = 32;
	ghost = ft_calloc(1, sizeof(t_enemie));
	if (!ghost)
		return ;
	ghost->x = x;
	ghost->id = game->index;
	ghost->y = y;
	ghost->direction = 0;
	ghost->move = RIGHT;
	game->enemies[game->index] = ghost;
	game->enemies[game->index]->img = mlx_xpm_file_to_image(game->mlx,
			"../textures/R/ghost_left2.xpm", &size, &size);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->enemies[game->index]->img, x * 32, y * 32);
	mlx_destroy_image(game->mlx, game->enemies[game->index]->img);
	game->index++;
}

int	init_game(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[0][i])
		i++;
	game->map_width = i;
	i = 0;
	while (game->map[i])
		i++;
	game->map_height = i;
	return (TRUE);
}

int	init_map_dimensions(t_game *game)
{
	game->mlx_win = mlx_new_window(game->mlx,
			game->map_width * 32,
			game->map_height * 32,
			"PacMan v2");
	game->total_items = 0;
	game->index = 0;
	return (TRUE);
}

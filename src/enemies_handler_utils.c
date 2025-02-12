/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_handler_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:55:52 by kclaudan          #+#    #+#             */
/*   Updated: 2025/02/10 18:55:52 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sprites_ghost(t_game *game, t_enemie *enemy, int direction)
{
	int	size;

	size = 32;
	if (direction == DOWN)
		enemy->img = mlx_xpm_file_to_image(game->mlx,
				"../textures/R/ghost_down2.xpm", &size, &size);
	else if (direction == UP)
		enemy->img = mlx_xpm_file_to_image(game->mlx,
				"../textures/R/ghost_up2.xpm", &size, &size);
	else if (direction == RIGHT)
		enemy->img = mlx_xpm_file_to_image(game->mlx,
				"../textures/R/ghost_right2.xpm", &size, &size);
	else if (direction == LEFT)
		enemy->img = mlx_xpm_file_to_image(game->mlx,
				"../textures/R/ghost_left2.xpm", &size, &size);
	if (!enemy->img)
	{
		ft_error("ERROR: Texture not found");
		close_window(game);
	}
}

int	check_collision(t_game *game, int i)
{
	if (game->enemies[i]->x == game->player.x
		&& game->enemies[i]->y == game->player.y)
	{
		perror("Game Over! Ghost caught you!");
		close_window(game);
		return (1);
	}
	return (0);
}

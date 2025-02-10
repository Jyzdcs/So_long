/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:06:34 by kclaudan          #+#    #+#             */
/*   Updated: 2025/02/10 19:06:34 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initialize_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (close_window(game));
	init_map_dimensions(game);
	init_map(game);
	return (1);
}

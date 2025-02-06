/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:44:01 by kclaudan          #+#    #+#             */
/*   Updated: 2025/02/06 13:22:03 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	free_all_ptr((void **)game->map);
	free_all_ptr((void **)game->enemies);
	exit(0);
	return 0;
}

void	place_texture(t_game *game, int y, int x, char *path)
{
	t_texture	texture;

	texture.img = mlx_xpm_file_to_image(game->mlx, path, &(game->player.width), &(game->player.height));
    mlx_put_image_to_window(game->mlx, game->mlx_win, texture.img, x * 32, y * 32);
}

int		calcul_dim(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

void	init_player(t_game *game, int y, int x)
{
	game->player.x = x;
	game->player.y = y;
	game->player.width = 32;
	game->player.height = 32;
	game->player.items = 0;
	game->player.img.img = mlx_xpm_file_to_image(game->mlx, "../textures/pac_closed.xpm", &(game->player.width), &(game->player.height));
	if (!game->player.img.img)
		printf("ERROR OF FILE\n");
	game->player.hitbox.back_x = x - 1;
	game->player.hitbox.front_x = x + 1;
	game->player.hitbox.top_y = y - 1;
	game->player.hitbox.bot_y = y + 1;
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->player.img.img, x * 32, y * 32);
}

void	init_ennemie(t_game *game, int y, int x)
{
	t_enemie	*ghost;
	int			size;

	ghost = malloc(sizeof(t_enemie));
	if (!ghost)
		return ;
	size = 32;
	ghost->x = x;
	ghost->id = game->index;
	ghost->y = y;
	ghost->direction = 0;
	ghost->move = RIGHT;
	game->enemies[game->index] = ghost;
	game->enemies[game->index]->img = mlx_xpm_file_to_image(game->mlx, "../textures/R/ghost_left2.xpm", &size, &size);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->enemies[game->index]->img, x * 32, y * 32);
	game->index++;
}

void	init_map(t_game *game)
{
	int		y;
	int		x;

	game->mlx_win = mlx_new_window(game->mlx, game->map_width * 32, game->map_height * 32, "PacMan v2");
	game->total_items = 0;
	game->index = 0;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				place_texture(game, y, x, "../textures/Walls/wall.xpm");
			else if (game->map[y][x] == 'P')
				init_player(game, y, x);
			else if (game->map[y][x] == 'G')
				init_ennemie(game, y, x);
			else if (game->map[y][x] == 'E')
				place_texture(game, y, x, "../textures/exit.xpm");
			else if (game->map[y][x] == 'C')
			{
				place_texture(game, y, x, "../textures/pacdot_food.xpm");
				game->total_items++;
			}
			x++;
		}
		y++;
	}
	return ;
}

int	get_extension(char *str)
{
	int		i;
	char	**path;
	char	**file_name;

	i = 0;
	path = ft_split(str, '/');
	if (!path)
		return (1);
	while (path[i + 1])
		i++;
	file_name = ft_split(path[i], '.');
	if (!file_name)
		return (1);
	i = 0;
	while (file_name[i + 1])
		i++;
	if (ft_strcmp(file_name[i], "ber") != 0)
	{
		free_all_ptr((void **)path);
		free_all_ptr((void **)file_name);
		return (1);
	}
	free_all_ptr((void **)path);
	free_all_ptr((void **)file_name);
	return (0);
}

int	nbr_of_ghost(char **map)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'G')
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
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

int	main(int ac, char **av)
{
	t_game	game;
	int		i;
	int		fd;
	int		map_height;

	if (ac != 2)
		return (printf("Error: wrong number of arguments\n"));
	// if (get_extension(av[1]))
	// {
	// 	printf("ERROR OF EXTENSION\n");
	// 	return (0);
	// }
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (printf("ERROR: Cannot open file\n"));
	map_height = 0;
	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		map_height++;
		free(line);
	}
	close(fd);
	game.map = (char **)malloc(sizeof(char *) * (map_height + 1));
	if (!game.map)
		return (printf("ERROR: Memory allocation failed\n"));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		free(game.map);
		return (printf("ERROR: Cannot open file\n"));
	}
	i = 0;
	while (i < map_height)
	{
		game.map[i] = get_next_line(fd);
		if (!game.map[i])
		{
			while (i > 0)
				free(game.map[--i]);
			free(game.map);
			close(fd);
			return (printf("ERROR: Reading file failed\n"));
		}
		i++;
	}
	game.map[i] = NULL;
	close(fd);
	init_game(&game);
	if (!is_valid(game.map, &game))
	{
		printf("ERROR\n");
		i = 0;
		while (game.map[i])
			free(game.map[i++]);
		free(game.map);
		exit(0);
		return (1);
	}
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		printf("ERREUR lors de l'initialisation de mlx\n");
		return (1);
	}
	init_map(&game);
	mlx_hook(game.mlx_win, 2, 1L<<0, key_hook, &game);
	mlx_hook(game.mlx_win, 17, 0, close_window, &game);
	mlx_loop_hook(game.mlx, update_enemies, &game);
	mlx_loop(game.mlx);
	return (0);
}

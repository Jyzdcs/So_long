/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:44:01 by kclaudan          #+#    #+#             */
/*   Updated: 2025/01/24 11:11:29 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(t_game *game)
{
	int	i;
	
	mlx_destroy_window(game->mlx, game->mlx_win);
	free_all_ptr(game->map);
	exit(0); // Quitte le programme
    return 0;
}

void	place_texture(t_game *game, int y, int x, char *path)
{
	t_texture	texture;

	texture.img = mlx_xpm_file_to_image(game->mlx, path, &(game->player.width), &(game->player.height));
    mlx_put_image_to_window(game->mlx, game->mlx_win, texture.img, x, y);
}

int		calcul_dim(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

void	init_player(t_game *game, int y, int x, int width, int height)
{
	game->player.x = x;
	game->player.y = y;
	game->player.width = 32;
	game->player.height = 32;
	game->player.items = 0;
	game->player.img.img = mlx_xpm_file_to_image(game->mlx, "../textures/Pac-Man/pac_closed.xpm", &(game->player.width), &(game->player.height));
	if (!game->player.img.img)
		printf("ERROR OF FILE\n");
	game->player.hitbox.back_x = x - 1;
	game->player.hitbox.front_x = x + 1;
	game->player.hitbox.top_y = y - 1;
	game->player.hitbox.bot_y = y + 1;
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->player.img.img, x * 32, y * 32);
}

void	init_map(t_game *game)
{
	int		y;
	int		x;
	int		height;

	game->mlx_win = mlx_new_window(game->mlx, ft_strlen(game->map[0]) * 32, 15 * 32, "Hello world!");
	game->total_items = 0;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				place_texture(game, y * 32, x * 32, "../textures/Other/Walls/wall.xpm"); //blanc
			else if (game->map[y][x] == 'P')
				init_player(game, y, x, 32, 32); // Jaune
			else if (game->map[y][x] == 'E')
				place_texture(game, y * 32, x * 32, "../textures/exit.xpm"); // Violet
			else if (game->map[y][x] == 'C')
			{
				place_texture(game, y * 32, x * 32, "../textures/Other/Pacdots/pacdot_food.xpm"); // Saumon
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
	while (path[i + 1])
		i++;
	file_name = ft_split(path[i], '.');
	i = 0;
	while (file_name[i + 1])
		i++;
	if (ft_strcmp(file_name[i], "ber") != 0)
	{
		free_all_ptr(path);
		free_all_ptr(file_name);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;
	int		i;
	int		fd;
	int		map_height;

	if (ac != 2)
		return (printf("Error: wrong number of arguments\n"));
	if (get_extension(av[1]))
	{
		printf("ERROR OF EXTENSION\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (printf("ERROR: Cannot open file\n"));

	// Compter d'abord le nombre de lignes
	map_height = 0;
	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		map_height++;
		free(line);
	}
	close(fd);

	// Allouer la mémoire pour map
	game.map = (char **)malloc(sizeof(char *) * (map_height + 1));
	if (!game.map)
		return (printf("ERROR: Memory allocation failed\n"));

	// Relire le fichier
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		free(game.map);
		return (printf("ERROR: Cannot open file\n"));
	}

	// Lire et stocker chaque ligne
	i = 0;
	while (i < map_height)
	{
		game.map[i] = get_next_line(fd);
		if (!game.map[i])
		{
			// Gérer l'erreur de lecture
			while (i > 0)
				free(game.map[--i]);
			free(game.map);
			close(fd);
			return (printf("ERROR: Reading file failed\n"));
		}
		i++;
	}
	game.map[i] = NULL;  // Terminer le tableau par NULL
	close(fd);
	if (!is_valid(game.map))
	{
		printf("ERROR\n");
		i = 0;
		while (game.map[i])
			free(game.map[i++]);
		free(game.map);
		exit(0); // Quitte le programme
		return (1);
	}
	// Initialiser la map
	game.mlx = mlx_init();
	init_map(&game);
	mlx_hook(game.mlx_win, 2, 1L<<0, key_hook, &game);
	mlx_loop(game.mlx);
	// Libérer la mémoire à la fin
	return (0);
}

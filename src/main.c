/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:44:01 by kclaudan          #+#    #+#             */
/*   Updated: 2025/01/28 14:18:22 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_window(t_game *game)
{
	int	i;
	
	mlx_destroy_window(game->mlx, game->mlx_win);
	free_all_ptr((void **)game->map);
	free_all_ptr((void **)game->ennemies);
	// free((void **)game->ennemies);
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

void	init_ennemie(t_game *game, int y, int x)
{
	t_ennemie	*ghost;
	int			size;

	ghost = malloc(sizeof(t_ennemie));
	if (!ghost)
		return ;
	size = 32;
	ghost->x = x;
	ghost->y = y;
	ghost->direction = 0;
	ghost->move = 1;
	game->ennemies[game->index] = ghost;
	game->ennemies[game->index]->img = mlx_xpm_file_to_image(game->mlx, "../textures/Ghosts/R/ghost_left1.xpm", &size, &size);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->ennemies[game->index]->img, x * 32, y * 32);
	game->index++;
}

void	init_map(t_game *game)
{
	int		y;
	int		x;
	int		height;

	game->mlx_win = mlx_new_window(game->mlx, ft_strlen(game->map[0]) * 32, 15 * 32, "PacMan v2");
	game->total_items = 0;
	game->index = 0;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				place_texture(game, y, x, "../textures/Other/Walls/wall.xpm"); //blanc
			else if (game->map[y][x] == 'P')
				init_player(game, y, x, 32, 32); // Jaune
			else if (game->map[y][x] == 'G')
				init_ennemie(game, y, x);
			else if (game->map[y][x] == 'E')
				place_texture(game, y, x, "../textures/exit.xpm"); // Violet
			else if (game->map[y][x] == 'C')
			{
				place_texture(game, y, x, "../textures/Other/Pacdots/pacdot_food.xpm"); // Saumon
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
		free_all_ptr((void **)path);
		free_all_ptr((void **)file_name);
		return (1);
	}
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
	game->map_width = 0;
	game->map_height = 0;
	while (game->map[game->map_height][game->map_width])
		game->map_width++;
	while (game->map[game->map_height][game->map_width])
		game->map_height++;
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
	game.ennemies = malloc(sizeof(t_ennemie *) * (nbr_of_ghost(game.map) + 1));
	init_map(&game);
	init_game(&game);
	mlx_hook(game.mlx_win, 2, 1L<<0, key_hook, &game);
	mlx_loop_hook(game.mlx, update_enemies, &game); // Enregistre la fonction de mise à jour des ennemis
	mlx_loop(game.mlx);
	// Libérer la mémoire à la fin
	return (0);
}

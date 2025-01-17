/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:44:01 by kclaudan          #+#    #+#             */
/*   Updated: 2025/01/17 18:56:13 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_texture(t_game game, int y, int x, int color)
{
	t_texture	texture;

	texture = fill_square(game.mlx, 40, 40, color);
    mlx_put_image_to_window(game.mlx, game.mlx_win, texture.img, x, y);
}

int		calcul_dim(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

t_game	init_map(char **map)
{
	t_game	game;
	int		i;
	int		j;
	int		height;

	height = calcul_dim(map);
	if (height == 0)
		return (game);

	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, ft_strlen(map[0]) * 40, 8 * 40, "Hello world!");
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				place_texture(game, i * 40, j * 40, 0x00FFFFFF); //blanc
			else if (map[i][j] == 'E')
				place_texture(game, i * 40, j * 40, 0x00990000); //
			else if (map[i][j] == '0')
				place_texture(game, i * 40, j * 40, 0x0000FF33);
			else if (map[i][j] == 'C')
				place_texture(game, i * 40, j * 40, 0x00CCCC00);
			j++;
		}
		i++;
	}
	return (game);
}

int	main(int ac, char **av)
{
	t_game	game;
	char	**map;
	int		i;
	int		fd;
	int		map_height;

	if (ac != 2)
		return (printf("Error: wrong number of arguments\n"));
	
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
	map = (char **)malloc(sizeof(char *) * (map_height + 1));
	if (!map)
		return (printf("ERROR: Memory allocation failed\n"));

	// Relire le fichier
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		free(map);
		return (printf("ERROR: Cannot open file\n"));
	}

	// Lire et stocker chaque ligne
	i = 0;
	while (i < map_height)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			// Gérer l'erreur de lecture
			while (i > 0)
				free(map[--i]);
			free(map);
			close(fd);
			return (printf("ERROR: Reading file failed\n"));
		}
		i++;
	}
	map[i] = NULL;  // Terminer le tableau par NULL
	close(fd);

	// Initialiser la map
	game = init_map(map);
	mlx_hook(game.mlx_win, 2, 1L<<0, key_hook, &game);
	mlx_loop(game.mlx);
	// Libérer la mémoire à la fin
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);

	return (0);
}

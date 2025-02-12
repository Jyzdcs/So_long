/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:44:01 by kclaudan          #+#    #+#             */
/*   Updated: 2025/02/12 12:26:42 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	read_map_height(char *file_path)
{
	int		fd;
	int		map_height;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	map_height = 0;
	line = get_next_line(fd);
	if (!line)
		return (-1);
	while (line != NULL)
	{
		map_height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map_height);
}

static int	load_map_content(t_game *game, char *file_path, int map_height)
{
	int		fd;
	int		i;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	while (i < map_height)
	{
		game->map[i] = get_next_line(fd);
		if (!game->map[i])
		{
			while (i > 0)
				free(game->map[--i]);
			free(game->map);
			close(fd);
			return (0);
		}
		i++;
	}
	game->map[i] = NULL;
	close(fd);
	return (1);
}

static void	setup_hooks(t_game *game)
{
	mlx_hook(game->mlx_win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->mlx_win, 17, 0, close_window, game);
	mlx_loop_hook(game->mlx, update_enemies, game);
	mlx_loop(game->mlx);
}

int	basic_parse(int ac, char **av, t_game *game)
{
	int		map_height;

	if (ac != 2)
		return (ft_error("Error: wrong number of arguments"));
	map_height = read_map_height(av[1]);
	if (map_height < 0)
		return (ft_error("ERROR: Cannot open file"));
	game->map = (char **)ft_calloc((map_height + 1), sizeof(char *));
	if (!game->map)
		return (ft_error("ERROR: Memory allocation failed"));
	if (!load_map_content(game, av[1], map_height))
		return (ft_error("ERROR: Reading file failed"));
	return (TRUE);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (!basic_parse(ac, av, &game))
		return (0);
	init_game(&game);
	game.enemies = ft_calloc((nbr_of_ghost(game.map) + 1), sizeof(t_enemie *));
	if (!game.enemies)
	{
		free_all_ptr((void **)game.map);
		return (ft_error("Error allocation"));
	}
	if (!is_valid(game.map, &game))
	{
		free_all_ptr((void **)game.map);
		free_all_ptr((void **)game.enemies);
		return (ft_error("ERROR: Map invalid"));
	}
	initialize_mlx(&game);
	setup_hooks(&game);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:01:44 by kclaudan          #+#    #+#             */
/*   Updated: 2025/02/09 14:57:04 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valide_move(int y, int x, char **map, int **visited)
{
	if (map[y][x] != '1' && !visited[y][x])
		return (TRUE);
	return (FALSE);
}

static int	numbers_items(char **map)
{
	int	tot_items;
	int	i;
	int	j;

	i = 0;
	tot_items = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				tot_items++;
			j++;
		}
		i++;
	}
	return (tot_items);
}

static int	not_visited(t_items *list, int y, int x)
{
	while (list)
	{
		if (list->y == y && list->x == x)
			return (FALSE);
		list = list->next;
	}
	return (TRUE);
}

static int	back_track(int y, int x, char **map, int **visited, t_items **list)
{
	if ((map[y][x] == 'E' || map[y][x] == 'C') 
		&& not_visited((*list)->next, y, x))
	{
		ft_lstadd_back(list, ft_lstnew(y, x));
		(*list)->counter++;
	}
	if ((*list)->counter == numbers_items(map))
		return (TRUE);
	visited[y][x] = TRUE;
	if (is_valide_move(y, x + 1, map, visited) 
		&& back_track(y, x + 1, map, visited, list))
		return (TRUE);
	if (is_valide_move(y, x - 1, map, visited) 
		&& back_track(y, x - 1, map, visited, list))
		return (TRUE);
	if (is_valide_move(y + 1, x, map, visited) 
		&& back_track(y + 1, x, map, visited, list))
		return (TRUE);
	if (is_valide_move(y - 1, x, map, visited) 
		&& back_track(y - 1, x, map, visited, list))
		return (TRUE);
	visited[y][x] = FALSE;
	return (FALSE);
}

static int	check_borders(char **map, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if ((i == 0 || i == height - 1 || j == 0 || j == width - 1) 
				&& map[i][j] != '1')
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

static int	**alloc_array_two_dim(char **map)
{
	int	**arr;
	int	height;
	int	width;

	height = 0;
	width = 0;
	while (map[height][width])
		width++;
	while (map[height])
		height++;
	arr = ft_calloc((height + 1), sizeof(int *));
	if (!arr)
		return (NULL);
	arr[height + 1] = NULL;
	height = 0;
	while (map[height])
	{
		arr[height] = ft_calloc(width, sizeof(int));
		if (!arr[height++])
			return (NULL);
	}
	return (arr);
}

static int	is_map_feasible(char **map, int start_x, int start_y)
{
	int		**visited;
	t_items	*items;

	visited = alloc_array_two_dim(map);
	if (!visited)
		return (0);
	items = ft_lstnew(start_y, start_x);
	items->counter = 0;
	if (back_track(start_y, start_x, map, visited, &items))
	{
		ft_lstclear(&items, free);
		free_all_ptr((void **)visited);
		return (TRUE);
	}
	ft_lstclear(&items, free);
	free_all_ptr((void **)visited);
	return (FALSE);
}

static int	not_a_rect(char **map)
{
	int	i;
	int	j;
	int	width;
	int	height;

	i = 0;
	width = 0;
	height = 0;
	while (map[height])
		height++;
	while (map[i][width])
		width++;
	if (width == height)
		return (1);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j != width)
			return (1);
		i++;
	}
	return (0);
}

int	is_valid(char **map, t_game *game)
{
	int	i;
	int	j;
	int	exit;
	int	item;
	int	player;

	i = 0;
	exit = 0;
	item = 0;
	player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' && !exit)
				exit++;
			if (map[i][j] == 'C' && !item)
				item++;
			if (map[i][j] == 'P' && !player)
				player++;
			if (map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != 'E'
				&& map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'G')
				return (FALSE);
			j++;
		}
		i++;
	}
	if (not_a_rect(map) || check_borders(map, game->map_height, game->map_width)
		|| !exit || !item || !player)
		return (FALSE);
	return (TRUE);
}

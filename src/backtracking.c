/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:20:59 by kclaudan          #+#    #+#             */
/*   Updated: 2025/03/04 17:01:41 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**alloc_visited_matrix(char **map, t_game *game)
{
	char	**visited;
	int		i;

	visited = ft_calloc((game->map_height + 1), sizeof(char *));
	if (!visited)
		return (NULL);
	i = 0;
	while (map[i])
	{
		visited[i] = ft_calloc(game->map_width, sizeof(char));
		if (!visited[i++])
			return ((char **)free_all_ptr((void **)visited));
	}
	return (visited);
}

void	flood_fill(t_arr arr, int y, int x, t_count *count)
{
	int	directions[4][2];
	int	i;

	if (arr.visited[y][x])
		return ;
	arr.visited[y][x] = 1;
	if (arr.map[y][x] == 'C')
		count->collectibles++;
	if (arr.map[y][x] == 'E')
		count->exit = 1;
	directions[0][0] = y;
	directions[0][1] = x + 1;
	directions[1][0] = y;
	directions[1][1] = x - 1;
	directions[2][0] = y + 1;
	directions[2][1] = x;
	directions[3][0] = y - 1;
	directions[3][1] = x;
	i = -1;
	while (++i < 4)
	{
		if (arr.map[directions[i][0]][directions[i][1]] != '1'
			&& !arr.visited[directions[i][0]][directions[i][1]])
			flood_fill(arr, directions[i][0], directions[i][1], count);
	}
}

int	count_map_items(char **map)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	is_map_feasible(char **map, int start_x, int start_y, t_game *game)
{
	t_count	count;
	int		total_collectibles;
	int		result;
	t_arr	arr;

	arr.visited = alloc_visited_matrix(map, game);
	if (!arr.visited)
		return (FALSE);
	arr.map = map;
	count.collectibles = 0;
	count.exit = 0;
	total_collectibles = count_map_items(map);
	flood_fill(arr, start_y, start_x, &count);
	result = (count.collectibles == total_collectibles && count.exit);
	free_all_ptr((void **)arr.visited);
	return (result);
}

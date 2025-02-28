/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:20:59 by kclaudan          #+#    #+#             */
/*   Updated: 2025/02/28 12:29:38 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	back_track(int y, int x, t_backtrack *bt)
{
	int	directions[4][2];
	int	i;

	bt->visited[y][x] = TRUE;
	if (rules_back_track(y, x, bt->map, &bt->list))
		return (TRUE);
	directions[0][0] = y;
	directions[0][1] = x + 1;
	directions[1][0] = y;
	directions[1][1] = x - 1;
	directions[2][0] = y + 1;
	directions[2][1] = x;
	directions[3][0] = y - 1;
	directions[3][1] = x;
	i = 0;
	while (i < 4)
	{
		if (try_move(directions[i][0], directions[i][1], bt))
			return (TRUE);
		i++;
	}
	bt->visited[y][x] = FALSE;
	return (FALSE);
}

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

int	is_map_feasible(char **map, int start_x, int start_y, t_game *game)
{
	int			res;
	t_items		*items;
	t_backtrack	bt;

	bt.visited = alloc_visited_matrix(map, game);
	if (!bt.visited)
		return (FALSE);
	items = ft_lstnew(start_y, start_x);
	if (!items)
	{
		free_all_ptr((void **)bt.visited);
		return (FALSE);
	}
	items->counter = 0;
	bt.map = map;
	bt.list = items;
	res = back_track(start_y, start_x, &bt);
	ft_lstclear(&items, free);
	free_all_ptr((void **)bt.visited);
	return (res);
}

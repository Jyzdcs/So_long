/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:20:59 by kclaudan          #+#    #+#             */
/*   Updated: 2025/02/10 16:20:59 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	back_track(int y, int x, t_backtrack *bt)
{
	bt->visited[y][x] = TRUE;
	if (rules_back_track(y, x, bt->map, &bt->list))
		return (TRUE);
	if (try_move(y, x + 1, bt)
		|| try_move(y, x - 1, bt)
		|| try_move(y + 1, x, bt)
		|| try_move(y - 1, x, bt))
		return (TRUE);
	bt->visited[y][x] = FALSE;
	return (FALSE);
}

int	**alloc_array_two_dim(char **map, t_game *game)
{
	int	**arr;
	int	i;

	arr = ft_calloc((game->map_height + 1), sizeof(int *));
	if (!arr)
		return (NULL);
	i = 0;
	while (map[i])
	{
		arr[i] = ft_calloc(game->map_width, sizeof(int));
		if (!arr[i++])
			return ((int **)free_all_ptr((void **)arr));
	}
	return (arr);
}

int	is_map_feasible(char **map, int start_x, int start_y, t_game *game)
{
	int			res;
	t_items		*items;
	t_backtrack	bt;

	bt.visited = alloc_array_two_dim(map, game);
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

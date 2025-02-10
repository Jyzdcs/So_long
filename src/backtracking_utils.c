/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:19:50 by kclaudan          #+#    #+#             */
/*   Updated: 2025/02/10 16:19:50 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valide_move(int y, int x, char **map, int **visited)
{
	if (map[y][x] != '1' && !visited[y][x])
		return (TRUE);
	return (FALSE);
}

int	numbers_items(char **map)
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

int	not_visited(t_items *list, int y, int x)
{
	while (list)
	{
		if (list->y == y && list->x == x)
			return (FALSE);
		list = list->next;
	}
	return (TRUE);
}

int	rules_back_track(int y, int x, char **map, t_items **list)
{
	if ((map[y][x] == 'E' || map[y][x] == 'C')
		&& not_visited((*list)->next, y, x))
	{
		ft_lstadd_back(list, ft_lstnew(y, x));
		(*list)->counter++;
	}
	if ((*list)->counter == numbers_items(map))
		return (TRUE);
	return (FALSE);
}

int	try_move(int y, int x, t_backtrack *bt)
{
	if (is_valide_move(y, x, bt->map, bt->visited))
		return (back_track(y, x, bt));
	return (FALSE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:19:50 by kclaudan          #+#    #+#             */
/*   Updated: 2025/02/28 16:58:18 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valide_move(int y, int x, char **map, char **visited)
{
	if (map[y][x] != '1' && !visited[y][x])
		return (TRUE);
	return (FALSE);
}

int	numbers_items(char **map)
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
			if (map[i][j] == 'C' || map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	not_visited(t_items *list, int y, int x)
{
	t_items	*current;

	current = list;
	while (current)
	{
		if (current->y == y && current->x == x)
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}

int	rules_back_track(int y, int x, char **map, t_items **list, int total_items)
{
	char	current;

	current = map[y][x];
	if ((current == 'E' || current == 'C') && not_visited(*list, y, x))
	{
		ft_lstadd_back(list, ft_lstnew(y, x));
		(*list)->counter++;
		if ((*list)->counter == total_items)
			return (TRUE);
	}
	return (FALSE);
}

int	try_move(int y, int x, t_backtrack *bt)
{
	if (is_valide_move(y, x, bt->map, bt->visited))
		return (back_track(y, x, bt));
	return (FALSE);
}

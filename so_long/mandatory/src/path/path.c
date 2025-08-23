/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:09:26 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/23 15:09:27 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

static void	init_visited(t_vec_2 *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i].x = -1;
		i++;
	}
}

static	t_vec_2	search_neighbors(char **map, t_vec_2 start,
		t_map *map_t, t_vec_2 *visited)
{
	t_vec_2			dest;
	t_vec_2			new_start;
	const int		dirs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	int				i;

	dest.x = -1;
	dest.y = -1;
	i = neighbor_check(map, start, map_t, visited);
	if (i == 1)
		return (start);
	else if (i == 0)
		return (dest);
	i = 0;
	while (i < 4)
	{
		new_start = start;
		new_start.x = start.x + dirs[i][0];
		new_start.y = start.y + dirs[i][1];
		dest = search_neighbors(map, new_start, map_t, visited);
		if (dest.x >= 0 && dest.y >= 0)
			return (dest);
		i++;
	}
	return (dest);
}

int	valid_path_exists(char **map, t_map *map_t)
{
	t_vec_2	*visited;
	t_vec_2	dest;

	visited = malloc(sizeof(t_vec_2) * (map_t->map_size.x * map_t->map_size.y));
	if (!visited)
		return (0);
	init_visited(visited, map_t->map_size.x * map_t->map_size.y);
	dest = search_neighbors(map, map_t->start_index, map_t, visited);
	free(visited);
	if (dest.x == -1 && dest.y == -1)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_extra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:09:30 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/23 15:09:31 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

static int	is_visited(t_vec_2 *visited_arr, t_vec_2 pos)
{
	int	i;

	i = 0;
	while (visited_arr[i].x >= 0)
	{
		if (visited_arr[i].x == pos.x && visited_arr[i].y == pos.y)
			return (1);
		i++;
	}
	return (0);
}

static void	add_to_visited(t_vec_2 *visited_arr, t_vec_2 pos)
{
	int	i;

	if (is_visited(visited_arr, pos))
		return ;
	i = 0;
	while (visited_arr[i].x >= 0)
		i++;
	visited_arr[i] = pos;
}

int	neighbor_check(char **map, t_vec_2 start,
		t_map *map_t, t_vec_2 *visited)
{
	t_vec_2	exit;

	exit = map_t->end_index;
	if (start.x == exit.x && start.y == exit.y)
		return (1);
	if ((start.x < 0 || start.y < 0) || is_visited(visited, start))
		return (0);
	add_to_visited(visited, start);
	if (map[(int)start.y][(int)start.x] == OBJ_WALL_CHAR)
		return (0);
	return (-1);
}

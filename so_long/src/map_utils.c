/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:04:04 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/20 15:07:26 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_full_wall(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != OBJ_WALL_CHAR)
			return (0);
		i++;
	}
	return (1);
}

int	is_enclosed_wall(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	return (str[0] == OBJ_WALL_CHAR && str[len - 1] == OBJ_WALL_CHAR);
}

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

static	t_vec_2	search_neighbors(char **map, t_vec_2 start,
		t_map *map_t, t_vec_2 *visited)
{
	t_vec_2	dest;
	t_vec_2	exit;
	t_vec_2	size;
	t_vec_2	new_start;

	exit = map_t->end_index;
	if (start.x == exit.x && start.y == exit.y)
		return (start);
	dest.x = -1;
	dest.y = -1;
	if ((start.x < 0 || start.y < 0) || is_visited(visited, start))
		return (dest);
	add_to_visited(visited, start);
	size = map_t->map_size;
	(void)size;
	if (map[(int)start.y][(int)start.x] == OBJ_WALL_CHAR)
		return (dest);
	new_start = start;
	new_start.x = start.x - 1;
	dest = search_neighbors(map, new_start, map_t, visited);
	if (dest.x >= 0 && dest.y >= 0)
		return (dest);
	new_start = start;
	new_start.y = start.y - 1;
	dest = search_neighbors(map, new_start, map_t, visited);
	if (dest.x >= 0 && dest.y >= 0)
		return (dest);
	new_start = start;
	new_start.x = start.x + 1;
	dest = search_neighbors(map, new_start, map_t, visited);
	if (dest.x >= 0 && dest.y >= 0)
		return (dest);
	new_start = start;
	new_start.y = start.y + 1;
	dest = search_neighbors(map, new_start, map_t, visited);
	if (dest.x >= 0 && dest.y >= 0)
		return (dest);
	return (dest);
}

static int	valid_path_exists(char **map, t_map *map_t)
{
	t_vec_2	*visited;
	t_vec_2	dest;

	visited = malloc(sizeof(t_vec_2) * (map_t->map_size.x * map_t->map_size.y));
	if (!visited)
		return (0);
	init_visited(visited, map_t->map_size.x * map_t->map_size.y);
	dest = search_neighbors(map, map_t->start_index, map_t, visited);
	if (dest.x == -1 && dest.y == -1)
		return (0);
	return (1);
}

int	is_map_valid(char **map_buff, int current_line_index, t_map *map)
{
	if (!map_buff || map_buff[current_line_index])
		return (0);
	if (map->start_pos.x == -999 || map->exit_pos.x == -999)
		return (0);
	if (map->target_collect == 0)
		return (0);
	if (!valid_path_exists(map_buff, map))
		return (0);
	return (1);
}

void	free_map_buffer(char **buffer)
{
	int	i;

	if (!buffer)
		return ;
	i = 0;
	while (buffer[i])
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
}

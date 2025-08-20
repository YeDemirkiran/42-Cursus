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
		arr[i].x = -1;
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

static int	valid_path_exists(char **map, t_vec_2 start, t_vec_2 exit,
		t_vec_2 size)
{
	int		x;
	int		y;
	t_vec_2	*visited;

	visited = malloc(sizeof(t_vec_2) * size.x * size.y);
	if (!visited)
		return (0);
	init_visited(visited, size.x * size.y);
	y = start.y;
	while ()
	x = 0;
	
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
	if (!valid_path_exists(map_buff, map->start_pos, map->exit_pos))
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

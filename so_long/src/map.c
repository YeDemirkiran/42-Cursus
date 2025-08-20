/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:04:08 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/20 11:56:48 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"

// STEP 1: Save map to a 2D buffer array
/* STEP 2: Check if the map is valid (rectangular, 
enclosed by walls, start, exit) */
// STEP 3: Check if a path exists from start to finish

static void	parse_wall(t_frame *frame, t_vec_2 pos)
{
	pos.x *= frame->sprites[S_WALL].size.x;
	pos.y *= frame->sprites[S_WALL].size.y;
	add_wall(frame, pos);
}

static void	parse_collectible(t_frame *frame, t_map *map, t_vec_2 pos)
{
	pos.x *= frame->sprites[S_COLL].size.x;
	pos.y *= frame->sprites[S_COLL].size.y;
	(map->target_collect)++;
	add_collectible(frame, pos);
}

static int	parse_start_exit(t_map *map, t_frame *frame, char c, t_vec_2 pos)
{
	if (c == OBJ_EXIT_CHAR)
	{
		if (!(map->exit_pos.x == -999 && map->exit_pos.y == -999))
			return (0);
		map->exit_pos.x = pos.x * frame->sprites[S_EXIT].size.x;
		map->exit_pos.y = pos.y * frame->sprites[S_EXIT].size.y;
	}
	else if (c == OBJ_START_CHAR)
	{
		if (!(map->start_pos.x == -999 && map->start_pos.y == -999))
			return (0);
		map->start_pos.x = pos.y * frame->sprites[S_PLAYER].size.x;
		map->start_pos.y = pos.y * frame->sprites[S_PLAYER].size.y;
	}
	return (1);
}

static int	read_line(char *line, int line_y, t_map *map, t_frame *frame)
{
	int		i;
	t_vec_2	pos;

	i = 0;
	pos.y = line_y;
	while (line[i])
	{
		pos.x = i;
		if (line[i] == OBJ_WALL_CHAR)
			parse_wall(frame, pos);
		else if (line[i] == OBJ_COLL_CHAR)
			parse_collectible(frame, map, pos);
		else if (line[i] == OBJ_START_CHAR || line[i] == OBJ_EXIT_CHAR)
		{
			if (!parse_start_exit(map, frame, line[i], pos))
				return (0);
		}
		else if (line[i] != OBJ_EMPTY_CHAR)
			return (0);
		i++;
	}
	return (1);
}

t_map	parse_map(char *path, t_frame *frame)
{
	t_map	map;
	char	**map_buff;
	int		i;

	map = init_map();
	if (!check_filename(path))
		return (map);
	map_buff = save_map(path, &map);
	i = 0;
	while (map_buff && map_buff[i])
	{
		if ((i == 0 || map_buff[i + 1] == NULL) && !is_full_wall(map_buff[i]))
			break ;
		if (i == 0)
			map.map_width = ft_strlen(map_buff[i]);
		else if (map.map_width != (int)ft_strlen(map_buff[i])
			|| !is_enclosed_wall(map_buff[i]))
			break ;
		if (!read_line(map_buff[i], i, &map, frame))
			break ;
		i++;
	}
	map.map_valid = is_map_valid(map_buff, i, &map);
	free_map_buffer(map_buff);
	return (map);
}

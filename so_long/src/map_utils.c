/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:04:04 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/20 11:56:24 by yademirk         ###   ########.fr       */
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

int	valid_path_exists(char **map, t_vec_2 start, t_vec_2 exit)
{
	(void)map;
	(void)start;
	(void)exit;
	return (1);
}

int	is_map_valid(char **map_buff, int current_line_index, t_map *map)
{
	if (!map_buff || map_buff[current_line_index])
		return (0);
	if (map->start_pos.x == -999 || map->exit_pos.x == -999)
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

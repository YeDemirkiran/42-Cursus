/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:03:53 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/20 11:51:06 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map	*set_map_error(t_map *map, char *msg)
{
	map->map_error = msg;
	return (map);
}

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

void	is_map_valid(char **map_buff, t_map *map)
{
	if (map->map_error)
		return ;
	else if (!map_buff)
		set_map_error(map, "The map doesn't have enough data! (maybe empty)\n");
	else if (map->start_pos.x == -999)
		set_map_error(map, "The map doesn't contain Start character!\n");
	else if (map->exit_pos.x == -999)
		set_map_error(map, "The map doesn't contain Exit character!\n");
	else if (map->target_collect == 0)
		set_map_error(map, "The map doesn't contain any Collectible!\n");
	else if (!valid_path_exists(map_buff, map))
		set_map_error(map, "The map doesn't contain a valid path!\n");
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

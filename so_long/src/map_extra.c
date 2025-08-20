/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:03:53 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/20 11:03:54 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_map_height(char *path)
{
	int		i;
	int		fd;
	int		height;
	ssize_t	read_size;
	char	buffer[BUFFER_SIZE];

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	height = 0;
	read_size = read(fd, buffer, BUFFER_SIZE - 1);
	while (read_size > 0)
	{
		buffer[read_size] = 0;
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
				height++;
			i++;
		}
		read_size = read(fd, buffer, BUFFER_SIZE - 1);
	}
	close(fd);
	return (height);
}

static void	save_to_buffer(char **map_buff, int fd)
{
	char	*buffer;
	ssize_t	read_size;
	int		i;

	buffer = get_next_line(fd);
	if (!buffer)
	{
		free(map_buff);
		return ;
	}
	i = 0;
	while (buffer)
	{
		read_size = ft_strlen(buffer);
		if (buffer[read_size - 1] == '\n')
			buffer[read_size - 1] = 0;
		map_buff[i++] = buffer;
		buffer = get_next_line(fd);
	}
	map_buff[i] = NULL;
}

char	**save_map(char *path, t_map *map)
{
	int		fd;
	char	**map_buff;

	map->map_height = get_map_height(path);
	if (map->map_height <= 1)
		return (NULL);
	map_buff = malloc(sizeof(char *) * (map->map_height + 1));
	if (!map_buff)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	save_to_buffer(map_buff, fd);
	return (map_buff);
}

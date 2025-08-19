#include "so_long.h"
#include "stdio.h"

// STEP 1: Save map to a 2D buffer array
/* STEP 2: Check if the map is valid (rectangular, 
enclosed by walls, start, exit) */
// STEP 3: Check if a path exists from start to finish

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

void	save_to_buffer(char **map_buff, int fd)
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

static int	read_line(char *line, int line_y, t_map *map, t_frame *frame)
{
	int		i;
	t_vec_2	pos;

	i = 0;
	while (line[i])
	{
		if (line[i] == OBJ_WALL_CHAR)
		{
			pos.x = i * frame->sprites[S_WALL].size.x;
			pos.y = line_y * frame->sprites[S_WALL].size.y;
			add_wall(frame, pos);
		}
		else if (line[i] == OBJ_COLL_CHAR)
		{
			pos.x = i * frame->sprites[S_COLL].size.x;
			pos.y = line_y * frame->sprites[S_COLL].size.y;
			add_collectible(frame, pos);
		}
		else if (line[i] == OBJ_EXIT_CHAR)
		{
			if (!(map->exit_pos.x == -999 && map->exit_pos.y == -999))
				return (0);
			map->exit_pos.x = i * frame->sprites[S_EXIT].size.x;
			map->exit_pos.y = line_y * frame->sprites[S_EXIT].size.y;
		}
		else if (line[i] == OBJ_START_CHAR)
		{
			if (!(map->start_pos.x == -999 && map->start_pos.y == -999))
				return (0);
			map->start_pos.x = i * frame->sprites[S_PLAYER].size.x;
			map->start_pos.y = line_y * frame->sprites[S_PLAYER].size.y;
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
	map_buff = save_map(path, &map);
	i = 0;
	while (map_buff && map_buff[i])
	{
		if ((i == 0 || map_buff[i + 1] == NULL) && !is_full_wall(map_buff[i]))
			break ;
		if (i == 0)
			map.map_width = ft_strlen(map_buff[i]);
		else if (map.map_width != (int)ft_strlen(map_buff[i]) || !is_enclosed_wall(map_buff[i]))
			break ;
		if (!read_line(map_buff[i], i, &map, frame))
			break ;
		i++;
	}
	map.map_valid = is_map_valid(map_buff, map_buff[i], &map);
	free_map_buffer(map_buff);
	return (map);
}

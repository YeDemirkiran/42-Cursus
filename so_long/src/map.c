#include "so_long.h"
#include "stdio.h"


// STEP 1: Save map to a 2D buffer array
// STEP 2: Check if the map is valid (rectangular, enclosed by walls, start, exit)
// STEP 3: Check if a path exists from start to finish

// static int	check_map_width(char *line, t_map *map)
// {
// 	int	tmp;

// 	if (map->map_width == -1)
// 		map->map_width = (int)ft_strlen(line) - 1;
// 	else
// 	{
// 		tmp = (int)ft_strlen(line);
// 		if (line[tmp - 1] == '\n')
// 			tmp--;
// 		if (map->map_width != tmp)
// 			return (0);
// 	}
// 	return (1);
// }

static int	read_line(char *line, int line_y, t_map *map, t_frame *frame)
{
	int		i;
	t_vec_2	pos;

	i = 0;
	while (line[i])
	{
		//printf("Current map char: %c\n", line[i]);
		if (line[i] == OBJ_WALL_CHAR)
		{
			pos.x = i * frame->sprites[S_WALL].size.x;
			pos.y = line_y * frame->sprites[S_WALL].size.y;
			add_wall(frame, pos);
		}
		else if (line[i] == OBJ_COLL_CHAR)
		{
			
		}
		else if (line[i] == OBJ_EXIT_CHAR)
		{
			map->exit_pos.x = i * frame->sprites[S_EXIT].size.x;
			map->exit_pos.y = line_y * frame->sprites[S_EXIT].size.y;
		}
		else if (line[i] == OBJ_START_CHAR)
		{
			map->start_pos.x = i * frame->sprites[S_PLAYER].size.x;
			map->start_pos.y = line_y * frame->sprites[S_PLAYER].size.y;
		}
		else if (line[i] != OBJ_EMPTY_CHAR)
			return (0);
		i++;
	}
	return (1);
}

// static t_map	read_map(char *path, t_frame *frame)
// {
// 	t_map	map;
// 	int		i;
// 	int		fd;
// 	char	*line;

// 	map.map_valid = 0;
// 	fd = open(path, O_RDONLY);
// 	if (fd < 0)
// 		return (map);
// 	map.map_width = -1;
// 	line = get_next_line(fd);
// 	i = 0;
// 	while (line)
// 	{
// 		read_line(line, i, &map, frame);
// 		free(line);
// 		line = get_next_line(fd);
// 		i++;
// 	}
// 	if (map.map_width == -1)
// 		return (map);
// 	map.map_height = i;
// 	return (map);
// }

char	**save_map(char *path, t_map *map)
{
	int		i;
	ssize_t	read_size;
	int		fd;
	char	**map_buff;
	char	*buffer;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map->map_height = 0;
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	read_size = read(fd, buffer, BUFFER_SIZE - 1);
	while (read_size > 0)
	{
		buffer[read_size] = 0;
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
				map->map_height++;
			i++;
		}
		read_size = read(fd, buffer, BUFFER_SIZE - 1);
	}
	free(buffer);
	if (map->map_height == 0)
		return (NULL);
	map_buff = malloc(sizeof(char *) * (map->map_height + 1));
	if (!map_buff)
		return (NULL);
	close(fd);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buffer = get_next_line(fd);
	if (!buffer)
	{
		free(map_buff);
		return (NULL);
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
	return (map_buff);
}



int	is_full_wall(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != OBJ_WALL_CHAR)
		{
			printf("%i is not a wall\n", str[i]);
			return (0);
		}
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


t_map	parse_map(char *path, t_frame *frame)
{
	t_map	map;
	char	**map_buff;
	int		i;

	map.map_valid = 0;
	map_buff = save_map(path, &map);
	if (!map_buff)
	{
		printf("Couldn't save the map.\n");
		return (map);
	}
	i = 0;
	while (map_buff[i])
	{
		if ((i == 0 || map_buff[i + 1] == NULL) && !is_full_wall(map_buff[i]))
		{
			printf("First or last not a full wall\n");
			break;
		}
		if (i == 0)
			map.map_width = ft_strlen(map_buff[i]);
		else if (map.map_width != (int)ft_strlen(map_buff[i]) || !is_enclosed_wall(map_buff[i]))
			break;
		if (!read_line(map_buff[i], i, &map, frame))
			break ;
		i++;
	}
	if (map_buff[i])
	{
		printf("Map is not valid.\n");
		return (map);
	}
	printf("Map is valid so far. Checking the path now\n");
	// int		i;
	// int		j;
	// int		tmp;
	// int		fd;
	// char	*line;
	// t_vec_2	pos;

	// fd = open(path, O_RDONLY);
	// if (fd < 0)
	// 	exit(EXIT_FAILURE);
	// map.map_width = -1;
	// line = get_next_line(fd);
	// j = 0;
	// while (line)
	// {
	// 	if (map.map_width == -1)
	// 		map.map_width = (int)ft_strlen(line) - 1;
	// 	else
	// 	{
	// 		tmp = (int)ft_strlen(line);
	// 		if (line[tmp - 1] == '\n')
	// 			tmp--;
	// 		if (map.map_width != tmp)
	// 			exit(EXIT_FAILURE);
	// 	}
	// 	i = 0;
	// 	while (line[i] && line[i] != '\n')
	// 	{
	// 		if (line[i] == OBJ_WALL_CHAR)
	// 		{
	// 			pos.x = i * frame->sprites[S_WALL].size.x;
	// 			pos.y = j * frame->sprites[S_WALL].size.y;
	// 			add_wall(frame, pos);
	// 		}
	// 		else if (line[i] == OBJ_COLL_CHAR)
	// 		{
				
	// 		}
	// 		else if (line[i] == OBJ_EXIT_CHAR)
	// 		{
	// 			map.exit_pos.x = i * frame->sprites[S_EXIT].size.x;
	// 			map.exit_pos.y = j * frame->sprites[S_EXIT].size.y;
	// 		}
	// 		else if (line[i] == OBJ_START_CHAR)
	// 		{
	// 			map.start_pos.x = i * frame->sprites[S_PLAYER].size.x;
	// 			map.start_pos.y = j * frame->sprites[S_PLAYER].size.y;
	// 		}
	// 		else if (line[i] != OBJ_EMPTY_CHAR)
	// 			exit(EXIT_FAILURE);
	// 		i++;
	// 	}
	// 	free(line);
	// 	line = get_next_line(fd);
	// 	j++;
	// }
	// if (map.map_width == -1)
	// 	exit(EXIT_FAILURE);
	map.map_valid = 1;
	return (map);
}

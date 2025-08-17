#include "so_long.h"

t_map	parse_map(char *path, t_frame *frame)
{
	t_map	map;
	int		i;
	int		j;
	int		tmp;
	int		fd;
	char	*line;
	t_vec_2	pos;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	map.map_width = -1;
	line = get_next_line(fd);
	j = 0;
	while (line)
	{
		if (map.map_width == -1)
			map.map_width = (int)ft_strlen(line) - 1;
		else
		{
			tmp = (int)ft_strlen(line);
			if (line[tmp - 1] == '\n')
				tmp--;
			if (map.map_width != tmp)
				exit(EXIT_FAILURE);
		}
		i = 0;
		while (line[i] && line[i] != '\n')
		{
			if (line[i] == OBJ_WALL_CHAR)
			{
				pos.x = i * frame->sprites[S_WALL].size.x;
				pos.y = j * frame->sprites[S_WALL].size.y;
				add_wall(frame, pos);
			}
			else if (line[i] == OBJ_COLL_CHAR)
			{
				
			}
			else if (line[i] == OBJ_EXIT_CHAR)
			{
				map.exit_pos.x = i * frame->sprites[S_EXIT].size.x;
				map.exit_pos.y = j * frame->sprites[S_EXIT].size.y;
			}
			else if (line[i] == OBJ_START_CHAR)
			{
				map.start_pos.x = i * frame->sprites[S_PLAYER].size.x;
				map.start_pos.y = j * frame->sprites[S_PLAYER].size.y;
			}
			else if (line[i] != OBJ_EMPTY_CHAR)
				exit(EXIT_FAILURE);
			i++;
		}
		free(line);
		line = get_next_line(fd);
		j++;
	}
	if (map.map_width == -1)
		exit(EXIT_FAILURE);
	return (map);
}

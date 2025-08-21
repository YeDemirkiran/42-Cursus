#ifndef MAP_H
# define MAP_H

# include <stddef.h>
# include <fcntl.h>

# include "t_frame.h"
# include "e_sprite_indices.h"
# include "init.h"

// map.c
t_map	parse_map(char *path, t_frame *frame);

// map_extra.c
int		is_map_valid(char **map_buff, int current_line_index, t_map *map);

// map_utils.c
char	**save_map(char *path, t_map *map);

#endif

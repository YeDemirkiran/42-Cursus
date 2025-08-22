#ifndef PATH_H
# define PATH_H

# include <stdlib.h>

# include "macro.h"
# include "t_map.h"

int	neighbor_check(char **map, t_vec_2 start,
		t_map *map_t, t_vec_2 *visited);
int	valid_path_exists(char **map, t_map *map_t);

#endif

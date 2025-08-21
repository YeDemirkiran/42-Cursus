#ifndef T_MAP_H
# define T_MAP_H

# include "t_vec_2.h"

typedef struct s_map
{
	int			map_valid;
	t_vec_2		map_size;
	t_vec_2		start_pos;
	t_vec_2		exit_pos;
	t_vec_2		start_index;
	t_vec_2		end_index;
	int			target_collect;
}			t_map;

#endif

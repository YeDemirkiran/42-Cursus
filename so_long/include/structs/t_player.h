#ifndef T_PLAYER_H
# define T_PLAYER_H

# include "t_object.h"

typedef struct s_player
{
	t_object	object;
	int			move_count;
	int			current_collect;
}			t_player;

#endif

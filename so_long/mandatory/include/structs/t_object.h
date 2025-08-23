#ifndef T_OBJECT_H
# define T_OBJECT_H

# include "t_sprite.h"

typedef struct s_object
{
	t_sprite	*sprite;
	t_vec_2		position;
	t_vec_2		velocity;
}			t_object;

#endif

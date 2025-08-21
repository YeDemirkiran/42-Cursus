#ifndef T_SPRITE_H
# define T_SPRITE_H

# include "t_vec_2.h"
# include "t_image.h"

typedef struct s_sprite
{
	t_image	image;
	int		id;
	t_vec_2	size;
}			t_sprite;

#endif

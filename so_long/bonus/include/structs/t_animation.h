#ifndef T_ANIMATION_H
# define T_ANIMATION_H

# include "t_sprite.h"
# include "macro.h"

# include "delta_time.h"

typedef struct s_animation
{
	t_sprite	*sprites[12];
	int			current_index;
	int			sprite_length;
	float		timer;
	float		frequency;
}			t_animation;

#endif

#ifndef ANIMATION_H
# define ANIMATION_H

# include "t_frame.h"

void	add_animation(t_frame *frame, float frequency, int sprite_indices[]);
void	animation_loop(t_animation *animation);

#endif

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>

# include "t_frame.h"
# include "e_sprite_indices.h"

# include "mlx.h"

void	add_sprite(char *path, t_sprite *sprites_buffer, void *mlx_addr);
void	add_object(t_object *objects_buffer, t_sprite *sprite, t_vec_2 pos);
void	add_wall(t_frame *frame, t_vec_2 pos);
void	add_collectible(t_frame *frame, t_vec_2 pos);
void	destroy_object(t_object *buffer, int index);

#endif

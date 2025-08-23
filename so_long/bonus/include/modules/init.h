/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:07:52 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/23 15:07:53 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include <stddef.h>
# include <X11/X.h>

# include "macro.h"
# include "t_frame.h"
# include "e_sprite_indices.h"

# include "events.h"
# include "update.h"
# include "utils.h"
# include "animation.h"

// init.c
void	init_sprites_empty(t_sprite *sprites_buffer);
void	init_objects_empty(t_object *objects_buffer);
void	init_background(t_frame *frame);
void	init_sprites(t_sprite *sprites_buffer, void *mlx_addr);
void	init_objects(t_frame *frame);

// init_extra.c
t_map	init_map(void);
void	init_player(t_frame *frame);
void	init_animations(t_frame *frame);
void	init_exit(t_frame *frame);
void	init_hooks(t_frame *frame);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_animation.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 12:39:25 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/24 12:39:26 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ANIMATION_H
# define T_ANIMATION_H

# include "t_sprite.h"
# include "macro.h"

# include "delta_time.h"

# ifndef ANIM_SPRITE_LIMIT
#  define ANIM_SPRITE_LIMIT 12
# endif

typedef struct s_animation
{
	t_sprite	*sprites[ANIM_SPRITE_LIMIT];
	int			current_index;
	int			sprite_length;
	float		timer;
	float		frequency;
}			t_animation;

#endif

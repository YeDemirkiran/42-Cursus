/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 12:39:08 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/24 12:39:09 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

# include "t_frame.h"

void	add_animation(t_frame *frame, float frequency, int sprite_indices[]);
void	animation_loop(t_animation *animation, float dt);

#endif

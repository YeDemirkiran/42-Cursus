/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_object.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:08:33 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/23 15:08:34 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_OBJECT_H
# define T_OBJECT_H

# include "t_animation.h"

typedef struct s_object
{
	t_sprite	*sprite;
	t_vec_2		position;
	t_vec_2		velocity;
}			t_object;

typedef struct s_object_anim
{
	t_animation	*animation;
	t_vec_2		position;
	t_vec_2		velocity;
}			t_object_anim;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:03:27 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/24 11:59:30 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "overlap.h"

t_vec_2	are_objects_overlapping(t_object obj_1, t_object obj_2)
{
	t_vec_2	overlap;
	float	obj_1_right;
	float	obj_2_right;
	float	obj_1_bottom;
	float	obj_2_bottom;

	obj_1_right = obj_1.position.x + obj_1.sprite->size.x;
	obj_2_right = obj_2.position.x + obj_2.sprite->size.x;
	overlap.x = 0;
	if (obj_2.position.x >= obj_1.position.x && obj_2.position.x <= obj_1_right)
		overlap.x = obj_2.position.x - obj_1_right;
	else if
	(obj_1.position.x >= obj_2.position.x && obj_1.position.x <= obj_2_right)
		overlap.x = obj_2_right - obj_1.position.x;
	obj_1_bottom = obj_1.position.y + obj_1.sprite->size.y;
	obj_2_bottom = obj_2.position.y + obj_2.sprite->size.y;
	overlap.y = 0;
	if
	(obj_2.position.y >= obj_1.position.y && obj_2.position.y <= obj_1_bottom)
		overlap.y = obj_2.position.y - obj_1_bottom;
	else if
	(obj_1.position.y >= obj_2.position.y && obj_1.position.y <= obj_2_bottom)
		overlap.y = obj_2_bottom - obj_1.position.y;
	return (overlap);
}

t_vec_2	is_player_overlapping(t_object_anim player, t_object obj_2)
{
	t_object	player_obj;

	player_obj.position = player.position;
	player_obj.velocity = player.velocity;
	player_obj.sprite = player.animation->sprites
	[player.animation->current_index];
	return (are_objects_overlapping(player_obj, obj_2));
}

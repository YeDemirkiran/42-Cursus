/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:03:27 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/23 15:26:57 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "overlap.h"

static t_vec_2	are_objects_overlapping(t_object obj_1, t_object obj_2)
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

static t_vec_2	are_objects_overlapping_anim(t_object_anim obj_1, t_object obj_2)
{
	t_object	new_obj_1;

	new_obj_1.position = obj_1.position;
	new_obj_1.velocity = obj_1.velocity;
	new_obj_1.sprite = obj_1.animation->sprites[obj_1.animation->current_index];
	return (are_objects_overlapping(new_obj_1, obj_2));
}

void	check_walls(t_frame *frame, int move_count)
{
	int		i;
	t_vec_2	overlap;

	i = 0;
	while (frame->walls[i].sprite)
	{
		overlap = are_objects_overlapping_anim(frame->player.object,
				frame->walls[i]);
		if (overlap.x && overlap.y)
		{
			if (fabs(overlap.x) < fabs(overlap.y))
				frame->player.object.position.x += overlap.x;
			else
				frame->player.object.position.y += overlap.y;
			frame->player.move_count = move_count;
		}
		i++;
	}
}

void	check_collectibles(t_frame *frame)
{
	int		i;
	t_vec_2	overlap;

	i = 0;
	while (frame->collectibles[i].sprite)
	{
		overlap = are_objects_overlapping_anim(frame->player.object,
				frame->collectibles[i]);
		if (overlap.x && overlap.y)
		{
			frame->player.current_collect++;
			destroy_object(frame->collectibles, i);
		}
		i++;
	}
}

void	check_enemies(t_frame *frame)
{
	int		i;
	t_vec_2	overlap;

	i = 0;
	while (frame->enemies[i].sprite)
	{
		overlap = are_objects_overlapping_anim(frame->player.object,
				frame->enemies[i]);
		if (overlap.x && overlap.y)
		{
			ft_putstr("You died! You touched an enemy.\n");
			mlx_loop_end(frame->mlx_addr);
		}
		i++;
	}
}

void	check_exit(t_frame *frame)
{
	t_vec_2	overlap;

	if (frame->player.current_collect != frame->map->target_collect)
		return ;
	overlap = are_objects_overlapping_anim(frame->player.object, frame->exit);
	if (overlap.x && overlap.y)
	{
		ft_putstr("Congrats! You finished the map.\n");
		mlx_loop_end(frame->mlx_addr);
	}
}

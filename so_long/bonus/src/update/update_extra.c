/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 13:05:00 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/24 13:35:40 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update.h"

static void	check_walls_enemy(t_object *enemy, t_frame *frame)
{
	int		i;
	t_vec_2	overlap;

	i = 0;
	while (frame->walls[i].sprite)
	{
		overlap = are_objects_overlapping(*enemy,
				frame->walls[i]);
		if (overlap.x && overlap.y)
		{
			if (fabs(overlap.x) < fabs(overlap.y))
				enemy->position.x += overlap.x;
			else
				enemy->position.y += overlap.y;
		}
		i++;
	}
}

static void	update_enemy(t_object *enemy, t_frame *frame)
{
	static float	dec_timer;

	if (dec_timer < ENEMY_DECISION)
		dec_timer += frame->delta_time;
	else
	{
		dec_timer = 0;
		if (frame->player.object.position.x > enemy->position.x)
		enemy->velocity.x = ENEMY_SPEED;
		else
			enemy->velocity.x = -ENEMY_SPEED;
		if (frame->player.object.position.y > enemy->position.y)
			enemy->velocity.y = ENEMY_SPEED;
		else
			enemy->velocity.y = -ENEMY_SPEED;
	}
	enemy->position.x += frame->delta_time * enemy->velocity.x;
	enemy->position.y += frame->delta_time * enemy->velocity.y;
	check_walls_enemy(enemy, frame);
}

void	update_enemies(t_frame *frame)
{
	int	i;

	i = 0;
	while (frame->enemies[i].sprite)
	{
		update_enemy(frame->enemies + i, frame);
		i++;
	}
}
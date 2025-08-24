/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 13:05:00 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/24 13:43:07 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update.h"

static void	check_wall_enemy(int enemy_index, t_frame *frame)
{
	int			i;
	t_vec_2		overlap;
	t_object	*enemy;

	i = 0;
	enemy = frame->enemies + enemy_index;
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

static void	check_enemy_self(int enemy_index, t_frame *frame)
{
	int			i;
	t_vec_2		overlap;
	t_object	*enemy;

	enemy = frame->enemies + enemy_index;
	i = 0;
	while (frame->enemies[i].sprite)
	{
		if (i == enemy_index)
		{
			i++;
			continue ;
		}
		overlap = are_objects_overlapping(*enemy,
				frame->enemies[i]);
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

static void	update_enemy(int enemy_index, t_frame *frame)
{
	static float	dec_timer;
	t_object		*enemy;

	enemy = frame->enemies + enemy_index;
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
	check_wall_enemy(enemy_index, frame);
	check_enemy_self(enemy_index, frame);
}

void	update_enemies(t_frame *frame)
{
	int	i;

	i = 0;
	while (frame->enemies[i].sprite)
	{
		update_enemy(i, frame);
		i++;
	}
}
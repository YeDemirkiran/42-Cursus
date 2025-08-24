/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 13:05:00 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/24 13:19:13 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update.h"

static void	update_enemy(t_object *enemy, t_frame *frame)
{
	enemy->velocity.x = 0;
	enemy->velocity.y = ENEMY_SPEED;
	enemy->position.x += frame->delta_time * enemy->velocity.x;
	enemy->position.y += frame->delta_time * enemy->velocity.y;
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
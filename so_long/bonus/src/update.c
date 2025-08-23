/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:04:16 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/23 14:03:39 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update.h"

static void	update_player(t_player *player, t_frame *frame)
{
	static int	count;

	player->object.position.x += player->object.velocity.x;
	player->object.position.y += player->object.velocity.y;
	check_walls(frame, count);
	check_collectibles(frame);
	check_exit(frame);
	if (player->move_count != count)
	{
		count = player->move_count;
		ft_putstr("PLAYER MOVE COUNT: ");
		ft_putnbr(player->move_count);
		ft_putstr("\n");
	}
}

static void	update_camera_offset(t_frame *frame)
{
	t_vec_2	p_pos;
	t_vec_2	p_size;
	t_vec_2	offset;

	p_pos = frame->player.object.position;
	p_size = frame->player.object.sprite->size;
	offset = frame->camera_offset;
	if (p_pos.x + offset.x >= RES_X)
		offset.x = p_pos.x * -1;
	else if ((p_pos.x + p_size.x) + offset.x <= 0)
		offset.x = RES_X - (p_pos.x + p_size.x);
	if (p_pos.y + offset.y >= RES_Y)
		offset.y = p_pos.y * -1;
	else if ((p_pos.y + p_size.y) + offset.y <= 0)
		offset.y = RES_Y - (p_pos.y + p_size.y);
	frame->camera_offset = offset;
}

int	update_frame(t_frame *frame)
{
	update_player(&(frame->player), frame);
	update_camera_offset(frame);
	render_frame(frame);
	return (0);
}

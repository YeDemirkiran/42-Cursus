/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:04:16 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/24 14:29:28 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update.h"

void	update_move_count(t_player *player)
{
	t_vec_2		size;
	float		x_diff;
	float		y_diff;

	x_diff = fabs(player->object.position.x - player->last_tile_pos.x);
	y_diff = fabs(player->object.position.y - player->last_tile_pos.y);
	size = player->object.sprite->size;
	if (x_diff >= size.x - 1)
	{
		player->move_count++;
		player->last_tile_pos = player->object.position;
	}
	if (y_diff >= size.y - 1)
	{
		player->move_count++;
		player->last_tile_pos = player->object.position;
	}
}

static void	update_player(t_player *player, t_frame *frame)
{
	static int	count;

	player->object.position.x += player->object.velocity.x;
	player->object.position.y += player->object.velocity.y;
	check_walls(frame);
	check_collectibles(frame);
	check_exit(frame);
	update_move_count(player);
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

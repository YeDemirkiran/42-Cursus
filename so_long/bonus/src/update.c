/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:04:16 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/23 16:09:01 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "update.h"

static void	update_move_count(int *count, t_player *player, t_frame *frame)
{
	char		*num_str;

	if (player->move_count != *count)
	{
		if (frame->move_str)
			free(frame->move_str);
		*count = player->move_count;
		num_str = ft_itoa(player->move_count);
		if (!num_str)
		{
			ft_putstr_fd("Error\nA memory error occured.\n", 2);
			mlx_loop_end(frame->mlx_addr);
		}
		frame->move_str = ft_strjoin("PLAYER MOVE COUNT: ", num_str);
		free(num_str);
		if (!frame->move_str)
		{
			ft_putstr_fd("Error\nA memory error occured.\n", 2);
			mlx_loop_end(frame->mlx_addr);
		}
	}
}

static void	update_player(t_player *player, t_frame *frame)
{
	static int	count;
	float		dt;

	dt = frame->delta_time;
	player->object.position.x += player->object.velocity.x * dt;
	player->object.position.y += player->object.velocity.y * dt;
	check_walls(frame, count);
	check_collectibles(frame);
	check_enemies(frame);
	check_exit(frame);
	update_move_count(&count, player, frame);
}

static void	update_camera_offset(t_frame *frame)
{
	t_vec_2	p_pos;
	t_vec_2	p_size;
	t_vec_2	offset;

	p_pos = frame->player.object.position;
	p_size = frame->player.object.animation->sprites[frame->player.object.animation->current_index]->size;
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
#include "stdio.h"
static void	update_animations(t_frame *frame)
{
	int	i;

	i = 0;
	while (frame->animations[i].current_index >= 0)
	{
		printf("ANIM LOOP: %i\n", i);
		animation_loop(&(frame->animations[i]), frame->delta_time);
		i++;
	}
}

int	update_frame(t_frame *frame)
{
	frame->delta_time = get_delta_time();
	update_player(&(frame->player), frame);
	update_camera_offset(frame);
	update_animations(frame);
	render_frame(frame);
	return (0);
}

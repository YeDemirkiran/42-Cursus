/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_extra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:03:45 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/24 14:07:05 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_map	init_map(void)
{
	t_map	map;

	map.map_error = NULL;
	map.map_size.x = 0;
	map.map_size.y = 0;
	map.target_collect = 0;
	map.start_pos.x = -999;
	map.start_pos.y = -999;
	map.exit_pos.x = -999;
	map.exit_pos.y = -999;
	return (map);
}

void	init_player(t_frame *frame)
{
	frame->player.current_collect = 0;
	frame->player.move_count = 0;
	frame->player.object.animation = frame->animations + 0;
	frame->player.object.position.x = frame->map->start_pos.x;
	frame->player.object.position.y = frame->map->start_pos.y;
	frame->player.object.velocity.x = 0;
	frame->player.object.velocity.y = 0;
	frame->player.last_tile_pos = frame->player.object.position;
}

void	init_exit(t_frame *frame)
{
	frame->exit.sprite = &(frame->sprites[S_EXIT]);
	frame->exit.position.x = frame->map->exit_pos.x;
	frame->exit.position.y = frame->map->exit_pos.y;
	frame->exit.velocity.x = 0;
	frame->exit.velocity.y = 0;
}

void	init_animations(t_frame *frame)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		frame->animations[i].current_index = -1;
		i++;
	}
	add_animation(frame, (float)GLOBAL_FREQUENCY, (int [5]){S_PLAYER_FRONT_0,
		S_PLAYER_FRONT_1, S_PLAYER_FRONT_2, S_PLAYER_FRONT_3, -1});
}

void	init_hooks(t_frame *frame)
{
	mlx_hook(frame->mlx_window, KeyPress, KeyPressMask, on_key_down, frame);
	mlx_hook(frame->mlx_window, KeyRelease, KeyReleaseMask, on_key_up, frame);
	mlx_hook(frame->mlx_window, DestroyNotify,
		0, on_destroy_notify, frame->mlx_addr);
	mlx_loop_hook(frame->mlx_addr, update_frame, frame);
}

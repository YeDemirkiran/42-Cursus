/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:03:27 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/24 14:23:58 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "overlap.h"

void	check_walls(t_frame *frame)
{
	int		i;
	t_vec_2	overlap;

	i = 0;
	while (frame->walls[i].sprite)
	{
		overlap = is_player_overlapping(frame->player.object,
				frame->walls[i]);
		if (overlap.x && overlap.y)
		{
			if (fabs(overlap.x) < fabs(overlap.y))
				frame->player.object.position.x += overlap.x;
			else
				frame->player.object.position.y += overlap.y;
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
		overlap = is_player_overlapping(frame->player.object,
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
		overlap = is_player_overlapping(frame->player.object,
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
	overlap = is_player_overlapping(frame->player.object, frame->exit);
	if (overlap.x && overlap.y)
	{
		ft_putstr("Congrats! You finished the map.\n");
		mlx_loop_end(frame->mlx_addr);
	}
}

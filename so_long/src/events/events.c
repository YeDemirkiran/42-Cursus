/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:03:36 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/23 13:33:02 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

static void	on_esc_press(unsigned char key, void *mlx_addr)
{
	if (key == K_ESC)
	{
		ft_putstr("Closing the game by request... (ESC pressed)\n");
		mlx_loop_end(mlx_addr);
	}
}

static void	on_move(unsigned int key, t_player *player)
{
	int	input_x;
	int	input_y;

	input_x = ((key == K_D) || (key == K_RIGHT))
		- ((key == K_A) || (key == K_LEFT));
	input_y = ((key == K_S) || (key == K_DOWN))
		- ((key == K_W) || (key == K_UP));
	if (input_x)
		player->object.velocity.x = input_x * PLAYER_SPEED;
	else if (input_y)
		player->object.velocity.y = input_y * PLAYER_SPEED;
	player->move_count += (input_x || input_y);
}

static void	on_stop_move(unsigned int key, t_player *player)
{
	int	input_x;
	int	input_y;

	input_x = ((key == K_D) || (key == K_RIGHT))
		- ((key == K_A) || (key == K_LEFT));
	input_y = ((key == K_S) || (key == K_DOWN))
		- ((key == K_W) || (key == K_UP));
	if (input_x)
		player->object.velocity.x = 0;
	if (input_y)
		player->object.velocity.y = 0;
}

int	on_key_down(int keycode, t_frame *frame)
{
	unsigned char	key;

	key = (unsigned char)keycode;
	on_esc_press(key, frame->mlx_addr);
	on_move(key, &(frame->player));
	return (0);
}

int	on_key_up(int keycode, t_frame *frame)
{
	unsigned char	key;

	key = (unsigned char)keycode;
	on_stop_move(key, &(frame->player));
	return (0);
}

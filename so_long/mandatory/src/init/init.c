/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:03:47 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/24 12:59:14 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	init_sprites_empty(t_sprite *sprites_buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		sprites_buffer[i].id = -1;
		i++;
	}
}

void	init_objects_empty(t_object *objects_buffer)
{
	int		i;
	t_vec_2	zero;

	i = 0;
	zero.x = 0;
	zero.y = 0;
	while (i < BUFFER_SIZE)
	{
		objects_buffer[i].sprite = NULL;
		objects_buffer[i].position = zero;
		objects_buffer[i].velocity = zero;
		i++;
	}
}

void	init_background(t_frame *frame)
{
	frame->background.sprite = &(frame->sprites[S_BACKGROUND]);
}

void	init_sprites(t_sprite *sprites_buffer, void *mlx_addr)
{
	init_sprites_empty(sprites_buffer);
	add_sprite(TEXTURES_PATH "Background.xpm",
		sprites_buffer, mlx_addr);
	add_sprite(TEXTURES_PATH "Player_0.xpm", sprites_buffer, mlx_addr);
	add_sprite(TEXTURES_PATH "Exit_0.xpm", sprites_buffer, mlx_addr);
	add_sprite(TEXTURES_PATH "Wall.xpm", sprites_buffer, mlx_addr);
	add_sprite(TEXTURES_PATH "Collectible.xpm", sprites_buffer, mlx_addr);
}

void	init_objects(t_frame *frame)
{
	init_objects_empty(frame->walls);
	init_objects_empty(frame->collectibles);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:03:47 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/20 13:38:08 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
#include "stdio.h"
void	init_sprites(t_sprite *sprites_buffer, void *mlx_addr)
{
	init_sprites_empty(sprites_buffer);
	add_sprite(TEXTURES_PATH "background_placeholder.xpm",
		sprites_buffer, mlx_addr);
	add_sprite(TEXTURES_PATH "Player.xpm", sprites_buffer, mlx_addr);
	add_sprite(TEXTURES_PATH "exit.xpm", sprites_buffer, mlx_addr);
	add_sprite(TEXTURES_PATH "Water.xpm", sprites_buffer, mlx_addr);
	add_sprite(TEXTURES_PATH "Collectible.xpm", sprites_buffer, mlx_addr);
	// int	i = 0;
	// while (((int *)(sprites_buffer[1].image.img_addr))[i] != -1)
	// {
	// 	printf("PIXEL %i: %#X\n", i, ((int *)(sprites_buffer[0].image.img_addr))[i]);
	// 	fflush(stdout);
	// 	i++;
	// }
}

void	init_objects(t_frame *frame)
{
	init_objects_empty(frame->walls);
	init_objects_empty(frame->collectibles);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:02:55 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/01 17:15:41 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"

int	main(int argc, char **argv)
{
	t_frame	frame;
	t_map	map;

	if (argc != 2)
	{
		write(2, "Error\n", 6);
		write(2, "Too few or too much arguments!\n", 31);
		exit(EXIT_FAILURE);
	}
	frame.mlx_addr = mlx_init();
	if (!frame.mlx_addr)
		return (EXIT_FAILURE);
	frame.mlx_window = mlx_new_window(frame.mlx_addr, RES_X, RES_Y, WINDOW_TITLE);
	if (!frame.mlx_window)
		return (EXIT_FAILURE);
	mlx_do_key_autorepeatoff(frame.mlx_addr);
	frame.camera_offset.x = 0;
	frame.camera_offset.y = 0;
	init_sprites(frame.sprites, frame.mlx_addr);
	init_background(&frame);
	init_objects(&frame);
	map = parse_map(argv[1], &frame);
	if (!map.map_valid)
	{
		write(2, "Error\n", 6);
		write(2, "The given map is not valid!\n", 28);
		return (EXIT_FAILURE);
	}
	frame.map = &map;
	init_player(&frame);
	init_exit(&frame);
	init_hooks(&frame);
	mlx_loop(frame.mlx_addr);
	mlx_do_key_autorepeaton(frame.mlx_addr);
	mlx_destroy_window(frame.mlx_addr, frame.mlx_window);
	mlx_destroy_display(frame.mlx_addr);
	printf("End.\n");
	return (EXIT_SUCCESS);
}

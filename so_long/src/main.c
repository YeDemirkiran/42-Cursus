/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:02:55 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/20 13:34:35 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_write.h"

static int	initialize_mlx(t_frame *frame)
{
	frame->mlx_addr = mlx_init();
	if (!frame->mlx_addr)
		return (0);
	frame->mlx_window = mlx_new_window(frame->mlx_addr,
			RES_X, RES_Y, WINDOW_TITLE);
	if (!frame->mlx_window)
	{
		mlx_destroy_display(frame->mlx_addr);
		return (0);
	}
	frame->camera_offset.x = 0;
	frame->camera_offset.y = 0;
	init_sprites(frame->sprites, frame->mlx_addr);
	init_background(frame);
	init_objects(frame);
	return (1);
}

static void	error_exit(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_frame	frame;
	t_map	map;

	if (argc <= 1)
		error_exit("No maps provided!\n");
	else if (argc > 2)
		error_exit("Too many arguments!\n");
	if (!initialize_mlx(&frame))
		exit(EXIT_FAILURE);
	map = parse_map(argv[1], &frame);
	if (!map.map_valid)
		error_exit("The given map is not valid!\n");
	frame.map = &map;
	init_player(&frame);
	init_exit(&frame);
	init_hooks(&frame);
	mlx_do_key_autorepeatoff(frame.mlx_addr);
	mlx_loop(frame.mlx_addr);
	mlx_do_key_autorepeaton(frame.mlx_addr);
	mlx_destroy_window(frame.mlx_addr, frame.mlx_window);
	mlx_destroy_display(frame.mlx_addr);
	return (EXIT_SUCCESS);
}

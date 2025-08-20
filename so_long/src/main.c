/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:02:55 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/20 13:55:44 by yademirk         ###   ########.fr       */
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

static void	error_exit(char *msg, t_frame *frame,
		void (*clear_func)(t_frame *frame))
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	if (frame && clear_func)
		clear_func(frame);
	exit(EXIT_FAILURE);
}

static void	destroy_sprites(t_frame *frame)
{
	int	i;

	i = 0;
	while (frame->sprites[i].id != -1)
	{
		mlx_destroy_image(frame->mlx_addr, frame->sprites[i].image.img_addr);
		i++;
	}
}

static void	clean_up(t_frame *frame)
{
	mlx_do_key_autorepeaton(frame->mlx_addr);
	destroy_sprites(frame);
	mlx_destroy_window(frame->mlx_addr, frame->mlx_window);
	mlx_destroy_display(frame->mlx_addr);
	free(frame->mlx_addr);
	frame->mlx_addr = NULL;
}

int	main(int argc, char **argv)
{
	t_frame	frame;
	t_map	map;

	if (argc <= 1)
		error_exit("No maps provided!\n", NULL, NULL);
	else if (argc > 2)
		error_exit("Too many arguments!\n", NULL, NULL);
	if (!initialize_mlx(&frame))
		exit(EXIT_FAILURE);
	map = parse_map(argv[1], &frame);
	if (!map.map_valid)
		error_exit("The given map is not valid!\n", &frame, clean_up);
	frame.map = &map;
	init_player(&frame);
	init_exit(&frame);
	init_hooks(&frame);
	mlx_do_key_autorepeatoff(frame.mlx_addr);
	mlx_loop(frame.mlx_addr);
	clean_up(&frame);
	return (EXIT_SUCCESS);
}

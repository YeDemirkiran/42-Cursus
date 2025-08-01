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

void	ft_put_pixel(t_image image, int pos_x, int pos_y, int color)
{
	char	*dst;

	dst = image.mod_addr + (pos_y * image.line_length + pos_x * (image.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	void	*mlx_addr;
	void	*mlx_window;
	t_image	mlx_image;
	int		x;
	int		y;

	(void)argc;
	(void)argv;
	mlx_addr = mlx_init();
	if (!mlx_addr)
		return (EXIT_FAILURE);
	mlx_window = mlx_new_window(mlx_addr, RES_X, RES_Y, WINDOW_TITLE);
	if (!mlx_window)
		return (EXIT_FAILURE);
	mlx_image.img_addr = mlx_new_image(mlx_addr, RES_X, RES_Y);
	mlx_image.mod_addr = mlx_get_data_addr(mlx_image.img_addr, &mlx_image.bits_per_pixel, &mlx_image.line_length, &mlx_image.endian);
	x = 0;
	while (x < RES_X)
	{
		y = 0;
		while (y < RES_Y)
		{
			ft_put_pixel(mlx_image, x, y, 0x00FFFFFF);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx_addr, mlx_window, mlx_image.img_addr, 0, 0);
	mlx_loop(mlx_addr);
	return (EXIT_SUCCESS);
}

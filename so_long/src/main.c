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

t_image	gen_square_img(void *mlx_pointer)
{
	t_image	img;
	int		x;
	int		y;

	img.img_addr = mlx_new_image(mlx_pointer, RES_X / 2, RES_Y / 2);
	img.mod_addr = mlx_get_data_addr(img.img_addr, &img.bits_per_pixel, &img.line_length, &img.endian);
	x = 0;
	while (x < RES_X / 2)
	{
		y = 0;
		while (y < RES_Y / 2)
		{
			ft_put_pixel(img, x, y, 0x00FFFFFF);
			y++;
		}
		x++;
	}
	return (img);
}

t_image	gen_right_triangle_img(void *mlx_pointer)
{
	t_image	img;
	int		x;
	int		y;

	img.img_addr = mlx_new_image(mlx_pointer, RES_X / 2, RES_Y / 2);
	img.mod_addr = mlx_get_data_addr(img.img_addr, &img.bits_per_pixel, &img.line_length, &img.endian);
	y = 0;
	while (y < RES_Y / 2)
	{
		x = 0;
		while (x <= y)
		{
			ft_put_pixel(img, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	return (img);
}

int	main(int argc, char **argv)
{
	void	*mlx_addr;
	void	*mlx_window;
	t_image	mlx_image;

	(void)argc;
	(void)argv;
	mlx_addr = mlx_init();
	if (!mlx_addr)
		return (EXIT_FAILURE);
	mlx_window = mlx_new_window(mlx_addr, RES_X, RES_Y, WINDOW_TITLE);
	if (!mlx_window)
		return (EXIT_FAILURE);
	mlx_image = gen_right_triangle_img(mlx_addr);
	mlx_put_image_to_window(mlx_addr, mlx_window, mlx_image.img_addr, RES_X / 4, RES_Y / 4);
	mlx_loop(mlx_addr);
	return (EXIT_SUCCESS);
}

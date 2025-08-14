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
#include "X11/X.h"
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

t_image	gen_triangle_img(void *mlx_pointer, int width, int height)
{
	t_image	img;
	int		x;
	int		y;

	img.img_addr = mlx_new_image(mlx_pointer, width, height);
	img.mod_addr = mlx_get_data_addr(img.img_addr, &img.bits_per_pixel, &img.line_length, &img.endian);
	y = 0;
	while (y * 2 < height)
	{
		x = 0;
		while (x <= y * 2)
		{
			ft_put_pixel(img, (width / 2) + (x - y), y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	return (img);
}

// t_vec_2	get_texture_size(char *texture_path)
// {
// 	t_vec_2	vec_2;
// 	int		fd;
// 	int		i;
// 	ssize_t	read_size;
// 	char	buffer[BUFFER_SIZE];

// 	fd = open(texture_path, O_RDONLY);
// 	if (fd < 0)
// 		exit(EXIT_FAILURE);
// 	read_size = -999;
// 	vec_2.x = 0;
// 	vec_2.y = 0;
// 	while (read_size > 0 || read_size == -999)
// 	{
// 		read_size = read(fd, buffer, BUFFER_SIZE - 1);
// 		buffer[read_size] = 0;
// 		i = 0;
// 		while (i < read_size)
// 		{
// 			if (buffer[i] == '\n')
// 				(vec_2.y)++;
// 			else
// 				(vec_2.x)++;
// 			i += 4;
// 		}
// 	}
// 	return (vec_2);
// }

// t_image	gen_texture_img(char *texture_path, void *mlx_pointer)
// {
// 	char	buffer[BUFFER_SIZE];
// 	ssize_t	read_size;
// 	t_image	img;
// 	int		x;
// 	int		y;
// 	int		fd;
// 	t_vec_2	txt_size;

// 	txt_size = get_texture_size(texture_path);
// 	printf("TEXT X: %i, Y: %i\n", txt_size.x, txt_size.y);
// 	img.img_addr = mlx_new_image(mlx_pointer, txt_size.x, txt_size.y);
// 	img.mod_addr = mlx_get_data_addr(img.img_addr, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	read_size = -999;
// 	fd = open(texture_path, O_RDONLY);
// 	if (fd < 0)
// 		exit(EXIT_FAILURE);
// 	y = 0;
// 	x = 0;
// 	read_size = -999;
// 	while (read_size > 0 || read_size == -999)
// 	{
// 		read_size = read(fd, buffer, BUFFER_SIZE - 1);
// 		buffer[BUFFER_SIZE - 1] = 0;
// 		while (x < read_size)
// 		{

// 		}
// 	}
// 	y = 0;
// 	while (y * 2 < txt_size.y)
// 	{
// 		x = 0;
// 		while (x <= y * 2)
// 		{
// 			ft_put_pixel(img, (txt_size.x / 2) + (x - y), y, 0x00FFFFFF);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (img);
// }

int	render_frame(t_image *img) 
{
	static t_vec_2	current_pos;

	if (current_pos.x != img->pos.x || current_pos.y != img->pos.y)
	{
		mlx_put_image_to_window(img->mlx_addr, img->mlx_window, img->img_addr, img->pos.x, img->pos.y);
		current_pos.x = img->pos.x;
		current_pos.y = img->pos.y;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	void	*mlx_addr;
	void	*mlx_window;
	t_image	mlx_image;
	t_vec_2	vec_2;

	(void)argc;
	(void)argv;
	mlx_addr = mlx_init();
	if (!mlx_addr)
		return (EXIT_FAILURE);
	mlx_window = mlx_new_window(mlx_addr, RES_X, RES_Y, WINDOW_TITLE);
	if (!mlx_window)
		return (EXIT_FAILURE);
	mlx_image.mlx_addr = mlx_addr;
	mlx_image.mlx_window = mlx_window;
	mlx_image.pos.x = RES_X / 2;
	mlx_image.pos.y = RES_Y / 2;
	mlx_image.img_addr = mlx_xpm_file_to_image(mlx_addr, TEXTURES_PATH "Water.xpm", &(vec_2.x), &(vec_2.y));
	//mlx_put_image_to_window(mlx_addr, mlx_window, mlx_image.img_addr, mlx_image.pos.x, mlx_image.pos.x);
	mlx_hook(mlx_window, KeyPress, KeyPressMask, on_key_press, &(mlx_image.pos));
	//mlx_hook(mlx_window, KeyPress, KeyPressMask, on_movement, &(mlx_image.pos));
	//mlx_hook(mlx_window, ButtonPress, ButtonPressMask, on_cross_press, );
	mlx_loop_hook(mlx_addr, render_frame, &mlx_image);
	mlx_loop(mlx_addr);
	return (EXIT_SUCCESS);
}

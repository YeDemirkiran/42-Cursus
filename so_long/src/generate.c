#include "so_long.h"

void	ft_put_pixel(t_image image, int pos_x, int pos_y, int color)
{
	char	*dst;

	dst = image.mod_addr + (pos_y * image.line_length + pos_x * (image.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_image	gen_square_img(void *mlx_pointer, int width, int height, int color)
{
	t_image	img;
	int		x;
	int		y;

	img.img_addr = mlx_new_image(mlx_pointer, width, height);
	img.mod_addr = mlx_get_data_addr(img.img_addr, &img.bits_per_pixel, &img.line_length, &img.endian);
	x = 0;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			ft_put_pixel(img, x, y, color);
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

t_image	gen_triangle_img(void *mlx_pointer, int width, int height, int color)
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
			ft_put_pixel(img, (width / 2) + (x - y), y, color);
			x++;
		}
		y++;
	}
	return (img);
}

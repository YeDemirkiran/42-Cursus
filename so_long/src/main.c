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

void	render_background(t_frame *frame)
{
	// static t_image	img;

	// if (img.img_addr == NULL)
	// 	img = gen_square_img(mlx_addr, RES_X, RES_Y, 0);
	//printf("SIZE %i %i\n", frame->background.sprite.size.x, frame->background.sprite.size.y);
	mlx_put_image_to_window(frame->mlx_addr, frame->mlx_window, frame->background.sprite.image.img_addr, (int)(frame->background.sprite.size.x) / -4, (int)(frame->background.sprite.size.y) / -4);
}

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
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		objects_buffer[i].sprite_id = -1;
		i++;
	}
}

void	add_sprite(char *path, t_sprite *sprites_buffer, void *mlx_addr)
{
	int	i;
	int	x;
	int	y;
	
	i = 0;
	while (sprites_buffer[i].id >= 0)
		i++;
	sprites_buffer[i].id = i;
	x = 0;
	y = 0;
	sprites_buffer[i].image.img_addr = mlx_xpm_file_to_image(mlx_addr, path, &x, &y);
	sprites_buffer[i].size.x = (float)x;
	sprites_buffer[i].size.y = (float)y;
	//printf("Size %f %f\n", sprites_buffer[i].size.x, sprites_buffer[i].size.y);
}

void	add_object(t_object *objects_buffer, t_sprite sprite, t_vec_2 pos, int object_type)
{
	int			i;
	
	i = 0;
	while (objects_buffer[i].sprite_id >= 0)
		i++;
	objects_buffer[i].sprite = sprite;
	objects_buffer[i].sprite_id = 1;
	objects_buffer[i].position.x = pos.x;
	objects_buffer[i].position.y = pos.y;
	objects_buffer[i].type = object_type;
}

void	init_sprites(t_sprite *sprites_buffer, void *mlx_addr)
{
	init_sprites_empty(sprites_buffer);
	// Add all the required textures here
	add_sprite(TEXTURES_PATH "background_placeholder.xpm", sprites_buffer, mlx_addr);
	add_sprite(TEXTURES_PATH "Player.xpm", sprites_buffer, mlx_addr);
	add_sprite(TEXTURES_PATH "Water.xpm", sprites_buffer, mlx_addr);
}

void	init_background(t_frame *frame)
{
	frame->background.sprite = frame->sprites[0];
}

void	init_walls(t_object *objects_buffer, t_sprite wall_sprite)
{
	t_vec_2	tmp;

	tmp.x = 200;
	tmp.y = 400;
	add_object(objects_buffer, wall_sprite, tmp, OBJ_WALL);
	tmp.x = 400;
	tmp.y = 500;
	add_object(objects_buffer, wall_sprite, tmp, OBJ_WALL);
}

void	init_objects(t_object *objects_buffer, t_sprite *sprites)
{
	init_objects_empty(objects_buffer);
	init_walls(objects_buffer, sprites[2]);
}

void	init_player(t_frame *frame)
{
	frame->player.object.sprite = frame->sprites[1];
	frame->player.object.position.x = RES_X / 2;
	frame->player.object.position.y = RES_Y / 2;
}

void	render_sprite(t_frame frame, t_sprite sprite, t_vec_2 pos, t_vec_2 *offset)
{
	t_vec_2	tmp;

	tmp.x = 0;
	tmp.y = 0;
	if (offset)
	{
		tmp.x = offset->x;
		tmp.y = offset->y;
	}
	mlx_put_image_to_window(frame.mlx_addr, frame.mlx_window, sprite.image.img_addr, (int)(pos.x + tmp.x), (int)(pos.y + tmp.y));
}

void	render_objects(t_object *objects, t_frame frame)
{
	int	i;

	i = 0;
	while (objects[i].sprite_id >= 0)
	{
		render_sprite(frame, objects[i].sprite, objects[i].position, &(frame.camera_offset));
		i++;
	}
}

void	render_player(t_frame frame)
{
	//printf("Player pos: x %i, y %i\n", frame.player.object.position.x, frame.player.object.position.y);
	//mlx_destroy_image(frame.mlx_addr, frame.player.object.sprite.image.img_addr);
	render_sprite(frame, frame.player.object.sprite, frame.player.object.position, NULL);
}

t_vec_2	are_objects_overlapping(t_object obj_1, t_object obj_2)
{
	t_vec_2	overlap;

	overlap.x = 0;
	if (obj_2.position.x > obj_1.position.x && obj_2.position.x < obj_1.position.x + obj_1.sprite.size.x)
		overlap.x = obj_2.position.x - (obj_1.position.x + obj_1.sprite.size.x);
	else if (obj_1.position.x > obj_2.position.x && obj_1.position.x < obj_2.position.x + obj_2.sprite.size.x)
		overlap.x = (obj_2.position.x + obj_2.sprite.size.x) - obj_1.position.x;
	overlap.y = 0;
	if (obj_2.position.y > obj_1.position.y && obj_2.position.y < obj_1.position.y + obj_1.sprite.size.y)
		overlap.y = obj_2.position.y - (obj_1.position.y + obj_1.sprite.size.y);
	else if (obj_1.position.y > obj_2.position.y && obj_1.position.y < obj_2.position.y + obj_2.sprite.size.y)
		overlap.y = (obj_2.position.y + obj_2.sprite.size.y) - obj_1.position.y;
	// overlap.x = (obj_2.position.x > obj_1.position.x && obj_2.position.x < obj_1.position.x + obj_1.sprite.size.x)
	// 			|| (obj_1.position.x >= obj_2.position.x && obj_1.position.x < obj_2.position.x + obj_2.sprite.size.x);
	// overlap.y = (obj_2.position.y >= obj_1.position.y && obj_2.position.y < obj_1.position.y + obj_1.sprite.size.y)
	// 			|| (obj_1.position.y > obj_2.position.y && obj_1.position.y < obj_2.position.y + obj_2.sprite.size.y);
	// if (overlap.x || overlap.y)
	// {	
	// 	printf("S1 Size %f %f\n", obj_1.sprite.size.x, obj_1.sprite.size.y);
	// 	printf("S2 Size %f %f\n", obj_2.sprite.size.x, obj_2.sprite.size.y);
	// 	printf("Overlap %f %f\n", overlap.x, overlap.y);
	// }
	return (overlap);
}

t_vec_2	player_overlapping_wall(t_frame frame)
{
	int		i;
	t_vec_2	overlap;

	i = 0;
	while (frame.objects[i].sprite_id >= 0)
	{
		if (frame.objects[i].type == OBJ_WALL)
		{
			overlap = are_objects_overlapping(frame.player.object, frame.objects[i]);
			if (overlap.x && overlap.y)
			{
			//	printf("Found overlap with wall\n");
				return (overlap);
			}
		}
		i++;
	}
	overlap.x = 0;
	overlap.y = 0;
	return (overlap);
}

void	update_player(t_player *player, t_frame frame)
{
	//t_vec_2	old_pos;
	t_vec_2	overlap;

	// old_pos.x = player->object.position.x;
	// old_pos.y = player->object.position.y;
	player->object.position.x += player->object.velocity.x;
	player->object.position.y += player->object.velocity.y;
	overlap = player_overlapping_wall(frame);
	if (overlap.x && overlap.y)
	{
		printf("X Y %f %f\n", overlap.x, overlap.y);
		if (overlap.x < overlap.y)
			player->object.position.x += overlap.x;
		else if (overlap.y < overlap.x)
			player->object.position.y += overlap.y;
	}
	//printf("Vel: %i %i\n", player->object.velocity.x, player->object.velocity.y);
}

void	update_camera_offset(t_frame *frame, t_vec_2 pos)
{
	frame->camera_offset = pos;
	printf("Cam offset: %f %f\n", pos.x, pos.y);
}

void	render_frame(t_frame *frame) 
{
	//printf("Cleaning screen...\n");
	//clear_screen(frame->mlx_addr, frame->mlx_window);
	render_background(frame);
	//printf("Done. Rendering objects...\n");
	render_player(*frame);
	render_objects(frame->objects, *frame);
	//printf("Done. Rendering player...\n");
//	printf("Done.\n");
}

int	frame_update(t_frame *frame)
{
	update_player(&(frame->player), *frame);
	//update_camera_offset(frame, frame->player.object.position);
	render_frame(frame);
	return (0);
}

void	init_hooks(t_frame *frame)
{
	mlx_hook(frame->mlx_window, KeyPress, KeyPressMask, on_key_press, frame);
	mlx_hook(frame->mlx_window, KeyRelease, KeyReleaseMask, on_key_up, frame);
	mlx_loop_hook(frame->mlx_addr, frame_update, frame);
}

t_map	parse_map(char *path)
{
	t_map	map;
	int		i;
	int		tmp;
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	map.map_width = -1;
	line = get_next_line(fd);
	while (line)
	{
		if (map.map_width == -1)
			map.map_width = (int)ft_strlen(line) - 1;
		else
		{
			tmp = (int)ft_strlen(line) - 1;
			if (map.map_width != tmp)
				exit(EXIT_FAILURE);
		}
		i = 0;
		while (line[i])
		{
			if (line[i] == OBJ_WALL_CHAR)
			{
				// Add to map wall
			}
			else if (line[i] == OBJ_COLL_CHAR)
			{
				// Add to map collectibles
			}
			else if (line[i] == OBJ_EXIT_CHAR)
			{
				// Add to map exit
			}
			else if (line[i] == OBJ_START_CHAR)
			{
				// Add to map start
			}
			else if (line[i] != OBJ_EMPTY_CHAR)
				exit(EXIT_FAILURE);
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	if (map.map_width == -1)
		exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_frame	frame;

	(void)argc;
	(void)argv;
	if (argc != 2)
	{
		write(2, "Error\n", 6);
		write(2, "Too few or too much arguments!\n", 31);
		exit(EXIT_FAILURE);
	}
	parse_map();
	frame.mlx_addr = mlx_init();
	if (!frame.mlx_addr)
		return (EXIT_FAILURE);
	frame.mlx_window = mlx_new_window(frame.mlx_addr, RES_X, RES_Y, WINDOW_TITLE);
	if (!frame.mlx_window)
		return (EXIT_FAILURE);
	mlx_do_key_autorepeatoff(frame.mlx_addr);
	frame.camera_offset.x = 0;
	frame.camera_offset.y = 0;
	printf("Init sprites...\n");
	init_sprites(frame.sprites, frame.mlx_addr);
	printf("Done. Init background...\n");
	init_background(&frame);
	printf("Done. Init objects...\n");
	init_objects(frame.objects, frame.sprites);
	printf("Done. Init player...\n");
	init_player(&frame);
	printf("Done. Init hooks...\n");
	init_hooks(&frame);
	printf("Done. Start loop...\n");
	mlx_loop(frame.mlx_addr);
	printf("Done. Start cleaning...\n");
	mlx_destroy_window(frame.mlx_addr, frame.mlx_window);
	mlx_destroy_display(frame.mlx_addr);
	printf("End.\n");
	return (EXIT_SUCCESS);
}

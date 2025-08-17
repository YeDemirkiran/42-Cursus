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
}

void	add_object(t_object *objects_buffer, t_sprite *sprite, t_vec_2 pos)
{
	int	i;
	
	i = 0;
	while (objects_buffer[i].sprite)
		i++;
	objects_buffer[i].sprite = sprite;
	objects_buffer[i].position.x = pos.x;
	objects_buffer[i].position.y = pos.y;
	objects_buffer[i].velocity.x = 0;
	objects_buffer[i].velocity.y = 0;
}

void	init_sprites(t_sprite *sprites_buffer, void *mlx_addr)
{
	init_sprites_empty(sprites_buffer);
	// Add all the required textures here
	add_sprite(TEXTURES_PATH "background_placeholder.xpm", sprites_buffer, mlx_addr);
	add_sprite(TEXTURES_PATH "Player.xpm", sprites_buffer, mlx_addr);
	add_sprite(TEXTURES_PATH "exit.xpm", sprites_buffer, mlx_addr);
	add_sprite(TEXTURES_PATH "Water.xpm", sprites_buffer, mlx_addr);
}

void	init_background(t_frame *frame)
{
	frame->background.sprite =  &(frame->sprites[S_BACKGROUND]);
}

void	add_wall(t_frame *frame, t_vec_2 pos)
{
	add_object(frame->walls, &(frame->sprites[S_WALL]), pos);
}

void	init_objects(t_frame *frame)
{
	init_objects_empty(frame->walls);
	init_objects_empty(frame->collectibles);
}

void	init_player(t_frame *frame)
{
	frame->player.object.sprite =  &(frame->sprites[S_PLAYER]);
	frame->player.object.position.x = frame->map->start_pos.x;
	frame->player.object.position.y = frame->map->start_pos.y;
	frame->player.object.velocity.x = 0;
	frame->player.object.velocity.y = 0;
}

void	init_exit(t_frame *frame)
{
	frame->exit.sprite =  &(frame->sprites[S_EXIT]);
	frame->exit.position.x = frame->map->exit_pos.x;
	frame->exit.position.y = frame->map->exit_pos.y;
	frame->exit.velocity.x = 0;
	frame->exit.velocity.y = 0;
}

void	render_sprite(t_frame *frame, t_sprite *sprite, t_vec_2 pos, t_vec_2 *offset)
{
	t_vec_2	tmp;

	tmp.x = 0;
	tmp.y = 0;
	if (offset)
	{
		tmp.x = offset->x;
		tmp.y = offset->y;
	}
	mlx_put_image_to_window(frame->mlx_addr, frame->mlx_window, sprite->image.img_addr, (int)(pos.x + tmp.x), (int)(pos.y + tmp.y));
}

void	render_background(t_frame *frame)
{
	t_vec_2	pos;
	t_vec_2	pos_2;
	t_vec_2	offset;

	pos.x = (int)(frame->background.sprite->size.x) / -4;
	pos.y = (int)(frame->background.sprite->size.y) / -4;
	pos_2.x = pos.x + frame->background.sprite->size.x;
	pos_2.y = pos.y;
	offset.x = frame->camera_offset.x * 0.1f;
	offset.y = frame->camera_offset.y * 0.1f;
	render_sprite(frame, frame->background.sprite, pos, &offset);
	render_sprite(frame, frame->background.sprite, pos_2, &offset);
}

void	render_object(t_frame *frame, t_object object, t_vec_2 *offset)
{
	render_sprite(frame, object.sprite, object.position, offset);
}

void	render_objects(t_object *objects, t_frame *frame)
{
	int	i;

	i = 0;
	while (objects[i].sprite)
	{
		render_object(frame, objects[i], &(frame->camera_offset));
		i++;
	}
}

t_vec_2	are_objects_overlapping(t_object obj_1, t_object obj_2)
{
	t_vec_2	overlap;

	overlap.x = 0;
	if (obj_2.position.x >= obj_1.position.x && obj_2.position.x <= obj_1.position.x + obj_1.sprite->size.x)
		overlap.x = obj_2.position.x - (obj_1.position.x + obj_1.sprite->size.x);
	else if (obj_1.position.x >= obj_2.position.x && obj_1.position.x <= obj_2.position.x + obj_2.sprite->size.x)
		overlap.x = (obj_2.position.x + obj_2.sprite->size.x) - obj_1.position.x;
	overlap.y = 0;
	if (obj_2.position.y >= obj_1.position.y && obj_2.position.y <= obj_1.position.y + obj_1.sprite->size.y)
		overlap.y = obj_2.position.y - (obj_1.position.y + obj_1.sprite->size.y);
	else if (obj_1.position.y >= obj_2.position.y && obj_1.position.y <= obj_2.position.y + obj_2.sprite->size.y)
		overlap.y = (obj_2.position.y + obj_2.sprite->size.y) - obj_1.position.y;
	return (overlap);
}

t_vec_2	player_overlapping_wall(t_frame *frame)
{
	int		i;
	t_vec_2	overlap;
	t_vec_2	total;

	i = 0;
	total.x = 0;
	total.y = 0;
	while (frame->walls[i].sprite)
	{
		overlap = are_objects_overlapping(frame->player.object, frame->walls[i]);
		if (overlap.x && overlap.y)
		{
			return (overlap);
			// if (fabs(overlap.x) < fabs(total.x) || !first)
			// 	total.x = overlap.x;
			// if (fabs(overlap.y) < fabs(total.y) || !first)
			// 	total.y = overlap.y;
			// first = 1;
		}
		i++;
	}
	return (total);
}

void	update_player(t_player *player, t_frame *frame)
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
		//printf("OVERLAP: %f %f\n", overlap.x, overlap.y);
		if (fabs(overlap.x) < fabs(overlap.y))
			player->object.position.x += overlap.x;
		else
			player->object.position.y += overlap.y;
	}
}

void	update_camera_offset(t_frame *frame)
{
	if (frame->player.object.position.x + frame->camera_offset.x >= RES_X)
		frame->camera_offset.x = frame->player.object.position.x * -1;
	else if ((frame->player.object.position.x + frame->player.object.sprite->size.x) + frame->camera_offset.x <= 0)
		frame->camera_offset.x = RES_X - (frame->player.object.position.x + frame->player.object.sprite->size.x);
	frame->camera_offset.y = 0;
}

void	render_frame(t_frame *frame) 
{
	render_background(frame);
	render_object(frame, frame->exit, &(frame->camera_offset));
	render_object(frame, frame->player.object, &(frame->camera_offset));
	render_objects(frame->walls, frame);
	render_objects(frame->collectibles, frame);
	mlx_string_put(frame->mlx_addr, frame->mlx_window, RES_X / 2, RES_Y / 2, 0x00000000, "TEST");
}

int	frame_update(t_frame *frame)
{
	update_player(&(frame->player), frame);
	update_camera_offset(frame);
	render_frame(frame);
	return (0);
}

void	init_hooks(t_frame *frame)
{
	mlx_hook(frame->mlx_window, KeyPress, KeyPressMask, on_key_press, frame);
	mlx_hook(frame->mlx_window, KeyRelease, KeyReleaseMask, on_key_up, frame);
	mlx_loop_hook(frame->mlx_addr, frame_update, frame);
}

t_map	parse_map(char *path, t_frame *frame)
{
	t_map	map;
	int		i;
	int		j;
	int		tmp;
	int		fd;
	char	*line;
	t_vec_2	pos;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	map.map_width = -1;
	line = get_next_line(fd);
	j = 0;
	while (line)
	{
		if (map.map_width == -1)
			map.map_width = (int)ft_strlen(line) - 1;
		else
		{
			tmp = (int)ft_strlen(line);
			if (line[tmp - 1] == '\n')
				tmp--;
			if (map.map_width != tmp)
				exit(EXIT_FAILURE);
		}
		i = 0;
		while (line[i] && line[i] != '\n')
		{
			if (line[i] == OBJ_WALL_CHAR)
			{
				pos.x = i * frame->sprites[S_WALL].size.x;
				pos.y = j * frame->sprites[S_WALL].size.y;
				add_wall(frame, pos);
				// Add to map wall
			}
			else if (line[i] == OBJ_COLL_CHAR)
			{
				// pos.x = i * frame.sprites[2].size.x;
				// pos.x = j * frame.sprites[2].size.y;
				// add_wall(frame, pos);
				// Add to map collectibles
			}
			else if (line[i] == OBJ_EXIT_CHAR)
			{
				map.exit_pos.x = i * frame->sprites[S_EXIT].size.x;
				map.exit_pos.y = j * frame->sprites[S_EXIT].size.y;
				printf("EXIT ADDED at %f %f\n", map.exit_pos.x, map.exit_pos.y);
				// Add to map exit
			}
			else if (line[i] == OBJ_START_CHAR)
			{
				map.start_pos.x = i * frame->sprites[S_PLAYER].size.x;
				map.start_pos.y = j * frame->sprites[S_PLAYER].size.y;
				printf("PLAYER ADDED at %f %f\n", map.start_pos.x, map.start_pos.y);
				// Add to map start
			}
			else if (line[i] != OBJ_EMPTY_CHAR)
				exit(EXIT_FAILURE);
			i++;
		}
		free(line);
		line = get_next_line(fd);
		j++;
	}
	if (map.map_width == -1)
		exit(EXIT_FAILURE);
	return (map);
}

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
	fflush(stdout);
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

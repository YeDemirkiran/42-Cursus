/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:02:50 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/20 12:44:53 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "math.h"
# include "mlx.h"
# include "stddef.h"
# include "stdlib.h"
# include "unistd.h"
# include "fcntl.h"
# include "X11/X.h"
# include "get_next_line.h"
# include "ft_string.h"

// overlap.c
t_vec_2	are_objects_overlapping(t_object obj_1, t_object obj_2);
void	check_walls(t_frame *frame, int move_count);
void	check_collectibles(t_frame *frame);
void	check_exit(t_frame *frame);

// events.c
int		on_key_down(int keycode, t_frame *frame);
int		on_key_up(int keycode, t_frame *frame);

// events_extra.c
int		on_destroy_notify(void *mlx_addr);

// init.c
void	init_sprites_empty(t_sprite *sprites_buffer);
void	init_objects_empty(t_object *objects_buffer);
void	init_background(t_frame *frame);
void	init_sprites(t_sprite *sprites_buffer, void *mlx_addr);
void	init_objects(t_frame *frame);

// init_extra.c
void	init_player(t_frame *frame);
void	init_exit(t_frame *frame);
void	init_hooks(t_frame *frame);

// map.c
t_map	parse_map(char *path, t_frame *frame);

// map_extra.c
int		check_filename(char *path);
char	**save_map(char *path, t_map *map);

// map_utils.c
int		is_full_wall(char *str);
int		is_enclosed_wall(char *str);
int		is_map_valid(char **map_buff, int current_line_index, t_map *map);
void	free_map_buffer(char **buffer);

// render.c
void	render_sprite(t_frame *frame, t_sprite *sprite,
			t_vec_2 pos, t_vec_2 *offset);
void	render_background(t_frame *frame);
void	render_object(t_frame *frame, t_object object, t_vec_2 *offset);
void	render_objects(t_object *objects, t_frame *frame);
void	render_frame(t_frame *frame);

// update.c
void	update_player(t_player *player, t_frame *frame);
void	update_camera_offset(t_frame *frame);
int		update_frame(t_frame *frame);

// utils.c
void	add_sprite(char *path, t_sprite *sprites_buffer, void *mlx_addr);
void	add_object(t_object *objects_buffer, t_sprite *sprite, t_vec_2 pos);
void	add_wall(t_frame *frame, t_vec_2 pos);
void	add_collectible(t_frame *frame, t_vec_2 pos);
t_map	init_map(void);

// utils_extra.c
void	destroy_object(t_object *buffer, int index);

#endif

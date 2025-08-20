/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:02:50 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/20 11:27:45 by yademirk         ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef WINDOW_TITLE
#  define WINDOW_TITLE "So Long"
# endif

# ifndef RES_X
#  define RES_X 960
# endif

# ifndef RES_Y
#  define RES_Y 540
# endif

# ifndef ASSETS_PATH
#  define ASSETS_PATH "./assets/"
# endif

# ifndef TEXTURES_PATH
#  define TEXTURES_PATH "./assets/textures/"
# endif

# ifndef PLAYER_SPEED
#  define PLAYER_SPEED 0.1
# endif

# define OBJ_EMPTY_CHAR '0'
# define OBJ_WALL_CHAR '1'
# define OBJ_COLL_CHAR 'C'
# define OBJ_EXIT_CHAR 'E'
# define OBJ_START_CHAR 'P'

typedef struct s_vec_2
{
	float	x;
	float	y;
}			t_vec_2;

typedef struct s_image
{
	void	*img_addr;
	char	*mod_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_sprite
{
	t_image	image;
	int		id;
	t_vec_2	size;
}			t_sprite;

typedef struct s_object
{
	t_sprite	*sprite;
	t_vec_2		position;
	t_vec_2		velocity;
}			t_object;

typedef struct s_player
{
	t_object	object;
	int			move_count;
	int			current_collect;
}			t_player;

typedef struct s_map
{
	int			map_valid;
	int			map_width;
	int			map_height;
	t_vec_2		start_pos;
	t_vec_2		exit_pos;
	int			target_collect;
}			t_map;

typedef struct s_frame
{
	void		*mlx_addr;
	void		*mlx_window;
	t_map		*map;
	t_object	background;
	t_sprite	sprites[BUFFER_SIZE];
	t_object	walls[BUFFER_SIZE];
	t_object	collectibles[BUFFER_SIZE];
	t_player	player;
	t_object	exit;
	t_vec_2		camera_offset;
}			t_frame;

enum	e_keys
{
	K_ESC = 27,
	K_W = 119,
	K_S = 115,
	K_A = 97,
	K_D = 100,
	K_UP = 0,
	K_DOWN = 0,
	K_LEFT = 0,
	K_RIGHT = 0,
};

enum	e_sprite_indexes
{
	S_BACKGROUND = 0,
	S_PLAYER = 1,
	S_EXIT = 2,
	S_WALL = 3,
	S_COLL = 4,
};

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
char	**save_map(char *path, t_map *map);

// map_utils.c
int		is_full_wall(char *str);
int		is_enclosed_wall(char *str);
int		valid_path_exists(char **map, t_vec_2 start, t_vec_2 exit);
int		is_map_valid(char **map_buff, char *current_line, t_map *map);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:02:50 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/01 16:56:36 by yademirk         ###   ########.fr       */
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

# ifndef WINDOW_TITLE
#  define WINDOW_TITLE "So Long"
# endif

# ifndef ASSETS_PATH
#  define ASSETS_PATH "./assets/"
# endif

# ifndef TEXTURES_PATH
#  define TEXTURES_PATH "./assets/textures/"
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef RES_X
#  define RES_X 960
# endif

# ifndef RES_Y
#  define RES_Y 540
# endif

# ifndef PLAYER_SPEED
#  define PLAYER_SPEED 1
# endif

# define OBJ_EMPTY_CHAR '0'
# define OBJ_WALL_CHAR '1'
# define OBJ_COLL_CHAR 'C'
# define OBJ_EXIT_CHAR 'E'
# define OBJ_START_CHAR 'P'

# include "get_next_line.h"
# include "ft_string.h"

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
	int			target_collect;
	int			current_collect;
}			t_player;

typedef	struct s_map
{
	int			map_valid;
	int			map_width;
	t_vec_2		start_pos;
	t_vec_2		exit_pos;
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
};

int		on_key_press(int keycode, t_frame *frame);
int		on_key_up(int keycode, t_frame *frame);
void	on_esc_press(unsigned char key, void *mlx_addr);
void	on_move(unsigned int key, t_player *player);
void	on_stop_move(unsigned int key, t_player *player);

#endif
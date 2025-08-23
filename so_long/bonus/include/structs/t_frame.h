/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_frame.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:08:13 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/23 16:03:43 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FRAME_H
# define T_FRAME_H

# include "t_player.h"
# include "t_map.h"
# include "macro.h"

typedef struct s_frame
{
	void		*mlx_addr;
	void		*mlx_window;
	t_map		*map;
	t_object	background;
	t_sprite	sprites[BUFFER_SIZE];
	t_object	walls[BUFFER_SIZE];
	t_object	collectibles[BUFFER_SIZE];
	t_object	enemies[BUFFER_SIZE];
	t_player	player;
	t_object	exit;
	t_vec_2		camera_offset;
	char		*move_str;
}			t_frame;

#endif

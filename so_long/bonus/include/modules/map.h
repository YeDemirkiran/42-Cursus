/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:07:55 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/23 15:24:41 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stddef.h>
# include <fcntl.h>

# include "t_frame.h"
# include "e_sprite_indices.h"

# include "init.h"
# include "utils.h"
# include "get_next_line.h"
# include "path.h"

// map.c
t_map	parse_map(char *path, t_frame *frame);

// map_extra.c
t_map	*set_map_error(t_map *map, char *msg);
int		is_full_wall(char *str);
int		is_enclosed_wall(char *str);
void	is_map_valid(char **map_buff, t_map *map);
void	free_map_buffer(char **buffer);

// map_utils.c
int		check_filename(char *path);
char	**save_map(char *path, t_map *map);

// map_bonus.c
void	parse_enemy(t_frame *frame, t_vec_2 pos);

#endif

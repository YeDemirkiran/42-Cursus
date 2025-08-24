/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:07:57 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/24 11:59:45 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OVERLAP_H
# define OVERLAP_H

# include <math.h>

# include "t_frame.h"
# include "t_animation.h"

# include "mlx.h"
# include "utils.h"
# include "ft_write.h"

t_vec_2	are_objects_overlapping(t_object obj_1, t_object obj_2);
t_vec_2	is_player_overlapping(t_object_anim player, t_object obj_2);
void	check_walls(t_frame *frame, int move_count);
void	check_collectibles(t_frame *frame);
void	check_exit(t_frame *frame);
void	check_enemies(t_frame *frame);

#endif

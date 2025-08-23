/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:08:19 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/23 15:08:20 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MAP_H
# define T_MAP_H

# include "t_vec_2.h"

typedef struct s_map
{
	char		*map_error;
	t_vec_2		map_size;
	t_vec_2		start_pos;
	t_vec_2		exit_pos;
	t_vec_2		start_index;
	t_vec_2		end_index;
	int			target_collect;
}			t_map;

#endif

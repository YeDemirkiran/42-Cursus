/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:23:21 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/23 15:33:47 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	parse_enemy(t_frame *frame, t_vec_2 pos)
{
	pos.x *= frame->sprites[S_ENEMY].size.x;
	pos.y *= frame->sprites[S_ENEMY].size.y;
	add_enemy(frame, pos);
}

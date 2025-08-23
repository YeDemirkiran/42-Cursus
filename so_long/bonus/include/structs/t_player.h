/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_player.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:08:35 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/23 15:08:36 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PLAYER_H
# define T_PLAYER_H

# include "t_object.h"

typedef struct s_player
{
	t_object_anim	object;
	int				move_count;
	int				current_collect;
}			t_player;

#endif

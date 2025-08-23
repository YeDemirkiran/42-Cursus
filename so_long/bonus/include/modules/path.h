/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:08:00 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/23 15:08:01 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

# include <stdlib.h>

# include "macro.h"
# include "t_map.h"

int	neighbor_check(char **map, t_vec_2 start,
		t_map *map_t, t_vec_2 *visited);
int	valid_path_exists(char **map, t_map *map_t);

#endif

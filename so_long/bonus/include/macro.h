/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:08:48 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/24 13:36:03 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

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
#  define PLAYER_SPEED 200
# endif

# ifndef ENEMY_SPEED
#  define ENEMY_SPEED 100
# endif

# ifndef ENEMY_RADIUS
#  define ENEMY_RADIUS 100
# endif

# ifndef ENEMY_DECISION
#  define ENEMY_DECISION 1
# endif

# ifndef GLOBAL_FREQUENCY
#  define GLOBAL_FREQUENCY 1.5f
# endif

# define OBJ_EMPTY_CHAR '0'
# define OBJ_WALL_CHAR '1'
# define OBJ_COLL_CHAR 'C'
# define OBJ_EXIT_CHAR 'E'
# define OBJ_START_CHAR 'P'
# define OBJ_ENEMY_CHAR 'D'

#endif

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
#  define BUFFER_SIZE 8192
# endif

# ifndef RES_X
#  define RES_X 960
# endif

# ifndef RES_Y
#  define RES_Y 540
# endif

typedef struct s_vec_2
{
	int	x;
	int	y;
}			t_vec_2;


typedef struct s_image
{
	void	*img_addr;
	char	*mod_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

#endif
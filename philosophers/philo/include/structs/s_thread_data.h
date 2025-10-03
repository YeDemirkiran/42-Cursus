/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_thread_data.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:12:08 by yademirk          #+#    #+#             */
/*   Updated: 2025/10/03 21:00:33 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef S_THREAD_DATA_H
# define S_THREAD_DATA_H

# include <structs/s_philosopher.h>
# include <structs/s_config.h>

typedef struct s_thread_data
{
	t_philosopher	*philosopher;
	t_config		*config;
	t_byte			*signal;
	pthread_mutex_t	*signal_mutex;
	pthread_mutex_t	*print_mutex;
}	t_thread_data;

#endif

/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_philosopher.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:56:29 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/04 22:11:02 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef S_PHILOSOPHER_H
# define S_PHILOSOPHER_H

# include <pthread.h>
# include <types/t_byte.h>

typedef struct s_philosopher
{
	int				id;
	pthread_t		thread_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_byte			current_routine;
	t_byte			is_dead;
}	t_philosopher;

#endif

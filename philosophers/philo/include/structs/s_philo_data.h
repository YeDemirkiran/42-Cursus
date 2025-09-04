/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_philo_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:12:08 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/04 18:41:36 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef S_PHILO_DATA_H
# define S_PHILO_DATA_H

# include <structs/s_philosopher.h>

typedef struct s_philo_data
{
	t_philosopher	*philosopher;
	pthread_mutex_t	*signal_mutex;
	t_byte			*signal;
}	t_philo_data;

#endif

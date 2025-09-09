/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_philo_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:12:08 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/09 12:25:30 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PHILO_DATA_H
# define S_PHILO_DATA_H

# include <structs/s_philosopher.h>

typedef struct s_philo_data
{
	t_philosopher	*philosopher;
	t_config		*config;
	pthread_mutex_t	*signal_mutex;
	pthread_mutex_t	*print_mutex;
	t_byte			*signal;
}	t_philo_data;

#endif

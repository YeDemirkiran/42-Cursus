/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:16:51 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/23 20:53:18 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <structs/s_philo_data.h>
# include <structs/s_table.h>

long	time_philosopher(long ms);
t_byte	read_signal_mutex(t_byte *signal, pthread_mutex_t *mutex);
void	*philosopher_routine(void *data);
int		start_philosophers(t_table *table, int count,
			void *(*philo_routine)(void *));

#endif

/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:00:08 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/22 23:37:14 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#include <structs/s_table.h>
#include <structs/s_philo_data.h>
#include <macros/status.h>

/**
 * @brief Sleep for ms, then return the time difference since the beginning.
 *
 * The first call returns always 0. To get the current timestamp without
 * sleeping, make ms 0.
 */
long	time_philosopher(long ms)
{
	static long				start_time;
	//static pthread_mutex_t	mutex;
	long					current_time;
	long					timestamp;
	struct timeval			tv;

	//pthread_mutex_init(&mutex, NULL);
	if (ms > 0)
		usleep(ms * 1000);
	gettimeofday(&tv, NULL);
	current_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	//pthread_mutex_lock(&mutex);
	if (start_time == 0)
		start_time = current_time;
	timestamp = current_time - start_time;
	//pthread_mutex_unlock(&mutex);
	return (timestamp);
}

static t_byte	read_signal_mutex(t_byte *signal, pthread_mutex_t *mutex)
{
	t_byte	res;

	pthread_mutex_lock(mutex);
	res = *signal;
	pthread_mutex_unlock(mutex);
	return (res);
}

void	*philosopher_routine(void *data)
{
	t_philo_data	*philo_data;
	t_byte			*dinner_over;

	philo_data = (t_philo_data *)data;
	dinner_over = philo_data->signal;
	while (1)
	{
		if (read_signal_mutex(dinner_over, philo_data->signal_mutex))
			break ;
		philosopher_eat(data);
		if (read_signal_mutex(dinner_over, philo_data->signal_mutex))
			break ;
		philosopher_sleep(data);
		if (read_signal_mutex(dinner_over, philo_data->signal_mutex))
			break ;
	}
	free(data);
	return (NULL);
}

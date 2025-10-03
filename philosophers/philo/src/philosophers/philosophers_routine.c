/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:35:34 by yademirk          #+#    #+#             */
/*   Updated: 2025/10/03 22:12:05 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdio.h>
#include <pthread.h>

#include <structs/s_thread_data.h>

#include <modules/philosophers/philosophers.h>

static void	leave_forks(t_thread_data *data)
{
	pthread_mutex_unlock(data->philosopher->left_fork);
	pthread_mutex_unlock(data->philosopher->right_fork);
}

static void	take_forks(t_thread_data *data)
{
	long	time;

	if (read_signal_mutex(data->signal, data->signal_mutex))
		return ;
	pthread_mutex_lock(data->philosopher->left_fork);
	time = time_philosopher(data, 0);
	if (read_signal_mutex(data->signal, data->signal_mutex))
	{
		pthread_mutex_unlock(data->philosopher->left_fork);
		return ;
	}
	printf("%li %i has taken a fork\n", time, *data->philosopher->id);
	pthread_mutex_lock(data->philosopher->right_fork);
	time = time_philosopher(data, 0);
	if (read_signal_mutex(data->signal, data->signal_mutex))
	{
		leave_forks(data);
		return ;
	}
	printf("%li %i has taken a fork\n", time, *data->philosopher->id);
}

void	philosopher_die(t_thread_data *data)
{
	long	time;

	pthread_mutex_lock(data->signal_mutex);
	if (*data->signal == 1)
	{
		pthread_mutex_unlock(data->signal_mutex);
		return ;
	}
	*(data->signal) = 1;
	pthread_mutex_unlock(data->signal_mutex);
	time = time_philosopher(data, 0);
	printf("%li %i died\n", time, *(data->philosopher->id));
}

void	philosopher_eat(t_thread_data *data)
{
	long	time;

	time = time_philosopher(data, 0);
	if (read_signal_mutex(data->signal, data->signal_mutex))
		return ;
	printf("%li %i is thinking\n", time, *data->philosopher->id);
	take_forks(data);
	time = time_philosopher(data, 0);
	if (read_signal_mutex(data->signal, data->signal_mutex))
	{
		leave_forks(data);
		return ;
	}
	printf("%li %i is eating\n", time, *data->philosopher->id);
	time_philosopher(data, data->config->eat_time);
	leave_forks(data);
}

void	philosopher_sleep(t_thread_data *data)
{
	long	time;
	long	diff;

	time = time_philosopher(data, 0);
	if (read_signal_mutex(data->signal, data->signal_mutex))
		return ;
	printf("%li %i is sleeping\n", time, *data->philosopher->id);
	diff = data->config->starve_time - data->config->sleep_time;
	if (diff <= 0)
	{
		time_philosopher(data, data->config->starve_time);
		philosopher_die(data);
	}
	else
		time_philosopher(data, data->config->sleep_time);
}

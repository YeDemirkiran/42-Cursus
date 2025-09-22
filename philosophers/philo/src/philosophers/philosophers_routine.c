/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:35:34 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/22 23:36:54 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdio.h>
#include <pthread.h>

#include <structs/s_philo_data.h>

static void	leave_forks(t_philo_data *data)
{
	pthread_mutex_unlock(data->philosopher->left_fork);
	pthread_mutex_unlock(data->philosopher->right_fork);
}

static void	take_forks(t_philo_data *data)
{
	long	time;

	//printf("(%i waiting for left fork %p)\n", *data->philosopher->id, data->philosopher->left_fork);
	if (read_signal_mutex(data->signal, data->signal_mutex))
		return ;
	pthread_mutex_lock(data->philosopher->left_fork);
	time = time_philosopher(0);
	if (read_signal_mutex(data->signal, data->signal_mutex))
	{
		pthread_mutex_unlock(data->philosopher->left_fork);
		return ;
	}
	printf("%li %i has taken a fork\n", time, *data->philosopher->id);
	//printf("(%i waiting for right fork %p)\n", *data->philosopher->id, data->philosopher->right_fork);
	pthread_mutex_lock(data->philosopher->right_fork);
	time = time_philosopher(0);
	if (read_signal_mutex(data->signal, data->signal_mutex))
	{
		leave_forks(data);
		return ;
	}
	printf("%li %i has taken a fork\n", time, *data->philosopher->id);
}

void	philosopher_die(t_philo_data *data)
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
	time = time_philosopher(0);
	printf("%li %i died\n", time, *(data->philosopher->id));
}

void	philosopher_eat(t_philo_data *data)
{
	long	time;

	time = time_philosopher(0);
	if (read_signal_mutex(data->signal, data->signal_mutex))
		return ;
	printf("%li %i is thinking\n", time, *data->philosopher->id);
	take_forks(data);
	time = time_philosopher(0);
	if (read_signal_mutex(data->signal, data->signal_mutex))
	{
		leave_forks(data);
		return ;
	}
	printf("%li %i is eating\n", time, *data->philosopher->id);
	time_philosopher(data->config->eat_time);
	leave_forks(data);
}

void	philosopher_sleep(t_philo_data *data)
{
	long	time;
	long	diff;

	time = time_philosopher(0);
	if (read_signal_mutex(data->signal, data->signal_mutex))
		return ;
	printf("%li %i is sleeping\n", time, *data->philosopher->id);
	diff = data->config->starve_time - data->config->sleep_time;
	if (diff <= 0)
	{
		time_philosopher(data->config->starve_time);
		philosopher_die(data);
	}
	else
		time_philosopher(data->config->sleep_time);
}

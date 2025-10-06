/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:35:34 by yademirk          #+#    #+#             */
/*   Updated: 2025/10/06 20:46:30 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdio.h>
#include <pthread.h>

#include <structs/s_thread_data.h>

#include <modules/philosophers/philosophers.h>

// colors
#define THINK_COLOR "\e[1;93m"
#define TAKE_FORK_COLOR "\e[1;37m"
#define EAT_COLOR "\e[1;92m"
#define SLEEP_COLOR "\e[1;96m"
#define DEATH_COLOR "\e[1;91m"
#define COLOR_RESET "\e[0m"

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
	printf("%li %i %shas taken a fork%s\n", time, *data->philosopher->id,
		TAKE_FORK_COLOR, COLOR_RESET);
	pthread_mutex_lock(data->philosopher->right_fork);
	time = time_philosopher(data, 0);
	if (read_signal_mutex(data->signal, data->signal_mutex))
	{
		leave_forks(data);
		return ;
	}
	printf("%li %i %shas taken a fork%s\n", time, *data->philosopher->id,
		TAKE_FORK_COLOR, COLOR_RESET);
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
	printf("%li %i %sdied\n%s", time, *data->philosopher->id,
		DEATH_COLOR, COLOR_RESET);
}

void	philosopher_eat(t_thread_data *data)
{
	long	time;

	time = time_philosopher(data, 0);
	if (read_signal_mutex(data->signal, data->signal_mutex))
		return ;
	printf("%li %i %sis thinking%s\n", time, *data->philosopher->id,
		THINK_COLOR, COLOR_RESET);
	take_forks(data);
	time = time_philosopher(data, 0);
	if (read_signal_mutex(data->signal, data->signal_mutex))
	{
		leave_forks(data);
		return ;
	}
	printf("%li %i %sis eating%s\n", time, *data->philosopher->id,
		EAT_COLOR, COLOR_RESET);
	time_philosopher(data, data->config->eat_time);
	leave_forks(data);
	data->philosopher->eat_count += 1;
	if (data->config->eat_count > 0 &&
		data->philosopher->eat_count >= data->config->eat_count)
	{
		pthread_mutex_lock(data->signal_mutex);
		*(data->signal) = 1;
		pthread_mutex_unlock(data->signal_mutex);
	}
}

void	philosopher_sleep(t_thread_data *data)
{
	long	time;
	long	diff;

	time = time_philosopher(data, 0);
	if (read_signal_mutex(data->signal, data->signal_mutex))
		return ;
	printf("%li %i %sis sleeping%s\n", time, *data->philosopher->id,
		SLEEP_COLOR, COLOR_RESET);
	diff = data->config->starve_time - data->config->sleep_time;
	if (diff <= 0)
	{
		time_philosopher(data, data->config->starve_time);
		philosopher_die(data);
	}
	else
		time_philosopher(data, data->config->sleep_time);
}

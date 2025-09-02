/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 21:35:53 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/02 17:44:53 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _DEFAULT_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_thread
{
	pthread_t		thread_id;
	int				id;
	int				ms;
	pthread_mutex_t	*mutex;
	int				*integer;
}			t_thread;

void	*test_threads(void *thread_data)
{
	int			*i;
	useconds_t	t;
	t_thread	*data;

	data = (t_thread *)thread_data;
	pthread_mutex_lock(data->mutex);
	i = data->integer;
	t = data->ms * 1000;
	while (*i < 100)
	{
		if (data->id == 0 && *i == 20)
			printf("...\n");
		printf("Thread %i accessed i: now %i\n", data->id, ++(*i));
		usleep(t);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_thread		threads[3];
	int				i;
	pthread_mutex_t	mutex;

	(void)argc;
	(void)argv;
	threads[0] = (t_thread){.id = 0, .ms = 100, .mutex = &mutex};
	threads[1] = (t_thread){.id = 1, .ms = 100, .mutex = &mutex};
	threads[2] = (t_thread){.id = 2, .ms = 50, .mutex = &mutex};
	threads[0].integer = &i;
	threads[1].integer = &i;
	threads[2].integer = &i;
	i = -1;
	pthread_create(&(threads[0].thread_id), NULL, test_threads, threads + 0);
	pthread_create(&(threads[1].thread_id), NULL, test_threads, threads + 1);
	pthread_create(&(threads[2].thread_id), NULL, test_threads, threads + 2);
	pthread_join(threads[0].thread_id, NULL);
	pthread_join(threads[1].thread_id, NULL);
	pthread_join(threads[2].thread_id, NULL);
	printf("Done.\n");
	return (EXIT_SUCCESS);
}

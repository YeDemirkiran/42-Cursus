/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 21:35:53 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/01 23:38:18 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#define _DEFAULT_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_thread
{
	pthread_t	thread_id;
	int			id;
	int			ms;
	int			*integer;
}			t_thread;

void	*test_threads(void *thread_data)
{
	int			*i;
	useconds_t	t;

	i = ((t_thread *)thread_data)->integer;
	t = ((t_thread *)thread_data)->ms * 100;
	while (*i < 1000)
	{
		printf("Thread %i accessed i: now %i\n", ((t_thread *)thread_data)->id, ++(*i));
		usleep(t);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_thread	threads[3];
	int			i;

	(void)argc;
	(void)argv;
	threads[0] = (t_thread){.id = 0, .ms = 50};
	threads[1] = (t_thread){.id = 1, .ms = 150};
	threads[2] = (t_thread){.id = 2, .ms = 1000};
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
	return (EXIT_SUCCESS);
}

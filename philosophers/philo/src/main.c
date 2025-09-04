/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 21:35:53 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/04 14:19:53 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#define _DEFAULT_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int				mails = 0;
pthread_mutex_t	mutex;

void	*test_threads()
{
	static int	id;

	pthread_mutex_lock(&mutex);
	for (size_t i = 0; i < 100000; i++)
	{
		printf("ID: %i, i: %lu\n", id, i);
		mails++;
	}
	id++;
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	threads[2];

	(void)argc;
	(void)argv;
	pthread_mutex_init(&mutex, NULL);
	pthread_create(threads, NULL, test_threads, NULL);
	pthread_create(threads + 1, NULL, test_threads, NULL);
	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);
	printf("Mails: %i\n", mails);
	pthread_mutex_destroy(&mutex);
	return (EXIT_SUCCESS);
}

/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 21:35:53 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/03 00:20:43 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#define _DEFAULT_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int	mails = 0;

void	*test_threads()
{
	for (size_t i = 0; i < 100000; i++)
	{
		mails++;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	threads[2];

	(void)argc;
	(void)argv;
	pthread_create(threads, NULL, test_threads, NULL);
	pthread_create(threads + 1, NULL, test_threads, NULL);
	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);
	printf("Mails: %i\n", mails);
	return (EXIT_SUCCESS);
}

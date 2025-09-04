/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:20:11 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/04 23:51:37 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include <pthread.h>

#include <macros/status.h>

void	destroy_mutexes(pthread_mutex_t *mutexes, int count)
{
	while (count-- >= 0)
		pthread_mutex_destroy(&mutexes[count]);
	free(mutexes);
}
#include "stdio.h"
int	init_mutexes(pthread_mutex_t **mutexes, int count)
{
	int				res;
	int				i;

	*mutexes = malloc(sizeof(pthread_mutex_t) * count);
	if (!*mutexes)
		return (FAILURE);
	i = 0;
	while (i < count)
	{
		printf("anan %i\n", i);
		fflush(stdout);
		res = pthread_mutex_init(&(*mutexes)[count], NULL);
		if (res != SUCCESS)
		{
			destroy_mutexes(&(*mutexes)[count], i);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

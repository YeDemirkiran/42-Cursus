/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:20:11 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/04 15:20:50 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <pthread.h>

pthread_mutex_t	*init_mutexes(int count)
{
	pthread_mutex_t	*mutexes;

	mutexes = malloc(sizeof(*mutexes) * count);
	if (!mutexes)
		return (NULL);
	while (count-- >= 0)
		pthread_mutex_init(mutexes + count, NULL);
	return (mutexes);
}

void	destroy_mutexes(pthread_mutex_t *mutexes, int count)
{
	while (count-- >= 0)
		pthread_mutex_destroy(mutexes + count);
}

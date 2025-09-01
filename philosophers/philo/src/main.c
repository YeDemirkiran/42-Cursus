/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 21:35:53 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/01 22:43:05 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#define _DEFAULT_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	test_threads(void)
{
	int			i;
	useconds_t	t;

	i = -1;
	t = 1000000;
	while (i < 100)
	{
		printf("Thread %i accessed i: now %i\n", 0, ++i);
		usleep(t);
	}
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	test_threads();
	return (EXIT_SUCCESS);
}

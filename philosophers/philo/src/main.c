/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 21:35:53 by yademirk          #+#    #+#             */
/*   Updated: 2025/09/04 18:39:26 by yademirk         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#define _DEFAULT_SOURCE
#include <stdlib.h>

#include <structs/s_table.h>
#include <modules/table.h>
#include <modules/simulation.h>

int	main(int argc, char **argv)
{
	t_table		table;

	init_table(&table, argc, argv);
	start_simulation(&table);
	clear_table(&table);
	return (EXIT_SUCCESS);
}

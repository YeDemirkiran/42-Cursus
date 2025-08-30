/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:05:04 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/30 16:47:14 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int	err_print(char *str,
	void (*clear)(t_stack_pair *), t_stack_pair *pair)
{
	if (clear && pair)
		clear(pair);
	if (str)
		ft_putstr_fd(str, 2);
	return (EXIT_FAILURE);
}

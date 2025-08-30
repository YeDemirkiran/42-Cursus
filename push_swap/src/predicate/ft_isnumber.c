/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:56:49 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/30 14:12:00 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generic_macros.h"
#include "predicate.h"

int	ft_isnumber(char *str)
{
	int	contains_num;

	contains_num = 0;
	if (*str == '\0')
		return (FALSE);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (FALSE);
		contains_num = 1;
		str++;
	}
	if (!contains_num)
		return (FALSE);
	return (TRUE);
}

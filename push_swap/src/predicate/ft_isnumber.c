/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:56:49 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/13 13:10:06 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "predicate.h"

int	ft_isnumber(char *str)
{
	if (*str == '\0')
		return (FALSE);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

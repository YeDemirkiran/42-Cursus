/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:56:43 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/02 11:56:44 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converter.h"

long long	ft_atol(char *str)
{
	long long	total;
	char		sign;

	total = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			sign = -1;
	while (*str && ft_isdigit(*str))
	{
		total = (total * 10) + (*str - '0');
		str++;
	}
	return (total * sign);
}
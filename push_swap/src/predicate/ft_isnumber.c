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
#include "ft_string.h"
#include "limits.h"

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

static size_t	int_digit_count(int num)
{
	size_t	count;

	count = num < 0;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	ft_num_too_long(char *str)
{
	size_t	len;
	int		result;

	len = ft_strlen(str);
	if (str[0] == '-')
		result = (len > int_digit_count(INT_MIN));
	else if (str[0] == '+')
		result = (len > int_digit_count(INT_MAX) + 1);
	else
		result = (len > int_digit_count(INT_MAX));
	return (result);
}

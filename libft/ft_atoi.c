/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:04:18 by yademirk          #+#    #+#             */
/*   Updated: 2025/06/02 13:08:20 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while (*nptr)
	{
		if (*nptr == '-' && sign != -1)
			sign = -1;
		else if (*nptr >= '0' && *nptr <= '9')
		{
			num *= 10;
			num += *nptr - 48;
		}
		else
			break ;
		nptr++;
	}
	return (num * sign);
}

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

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int	ft_atoi(const char *nptr)
{
	int	num;
	int	sign;
	int	skip;

	num = 0;
	sign = 1;
	skip = 1;
	while (*nptr)
	{
		// if (skip)
		// {
		// 	if (*nptr == '-')
		// 		sign = -1;
		// 	if (!ft_isspace(*nptr))
		// 	{
		// 		skip = 0;
		// 		if (*nptr == '-' || *nptr == '+')
		// 			nptr++;
		// 	}
		// }
		// if (!skip)
		// {
		// 	if (*nptr >= '0' && *nptr <= '9')
		// 	{
		// 		num *= 10;
		// 		num += *nptr - 48;
		// 	}
		// 	else
		// 		break ;
		// }
		if (*nptr == '-' && skip)
			sign = -1;
		else if (*nptr >= '0' && *nptr <= '9')
		{
			num *= 10;
			num += *nptr - 48;
		}
		else if (!(skip && (*nptr == '+' || ft_isspace(*nptr))))
			break ;
		if (skip && !ft_isspace(*nptr))
			skip = 0;
		nptr++;
	}
	return (num * sign);
}

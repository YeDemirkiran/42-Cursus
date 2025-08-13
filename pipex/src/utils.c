/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:03:42 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/13 12:50:04 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_string_array(char **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	is_delimiter(char *str, char *delimiter, ssize_t read_size)
{
	int		is_delimiter;
	char	tmp;

	is_delimiter = 0;
	tmp = str[read_size - 1];
	str[read_size - 1] = 0;
	if (ft_strcmp(str, delimiter) == 0)
		is_delimiter = 1;
	str[read_size - 1] = tmp;
	return (is_delimiter);
}

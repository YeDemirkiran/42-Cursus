/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:03:42 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/11 15:23:16 by yademirk         ###   ########.fr       */
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

void	strerror_exit(char *perror_str, int free_str)
{
	perror(perror_str);
	if (free_str)
		free(perror_str);
	exit(EXIT_FAILURE);
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

void	print_cmd_not_found(char *cmd_name)
{
	if (cmd_name)
		write(2, cmd_name, ft_strlen(cmd_name));
	write(2, ": command not found\n", 20);
}

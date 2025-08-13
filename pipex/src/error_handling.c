/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:41:01 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/13 12:50:14 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	strerror_exit(char *perror_str, int free_str)
{
	perror(perror_str);
	if (free_str)
		free(perror_str);
	exit(EXIT_FAILURE);
}

void	print_cmd_not_found(char *cmd_name)
{
	if (cmd_name)
		write(2, cmd_name, ft_strlen(cmd_name));
	write(2, ": command not found\n", 20);
}

void	not_found_exit(char *cmd_name)
{
	print_cmd_not_found(cmd_name);
	exit(EXIT_FAILURE);
}

void	print_input_prompt(char *buffer, ssize_t read_size)
{
	if (read_size == -999 || buffer[read_size - 1] == '\n')
		write(1, "> ", 2);
}

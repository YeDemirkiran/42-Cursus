/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:02:38 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/11 17:12:26 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	prepare_stdin(char *input_file_path, int *io_fd)
{
	if (ft_strncmp(input_file_path, "here_doc", 9) == 0)
	{
		//printf("FIRST ARG IS HEREDOOOOOOOC\n");
		io_fd[0] = 0;
	}
	else if (access(input_file_path, R_OK) < 0)
	{
		write(2, "bash: ", 6);
		perror(input_file_path);
		io_fd[0] = -1;
	}
	else
		io_fd[0] = open(input_file_path, O_RDONLY);
}

int	prepare_stdout(char *stdout_path)
{
	int	fd;

	fd = open(stdout_path, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd < 0)
		strerror_exit("pipex: open", 0);
	return (fd);
}

void	prepare_pipes(int pipes[BUFFER_SIZE][2], int pipe_count)
{
	int	i;

	i = 0;
	while (i < pipe_count)
	{
		if (pipe(pipes[i]) == -1)
			strerror_exit("pipex", 0);
		i++;
	}
}

void	set_fds(t_fd_info fd_info)
{
	if (fd_info.stdin_fd > 2)
	{
		dup2(fd_info.stdin_fd, STDIN_FILENO);
		close(fd_info.stdin_fd);
	}
	if (fd_info.stdout_fd > 2)
	{
		dup2(fd_info.stdout_fd, STDOUT_FILENO);
		close(fd_info.stdout_fd);
	}
}

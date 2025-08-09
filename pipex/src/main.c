/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:54:22 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/05 14:01:09 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	print_strerror(char *program_name)
{
	perror(program_name);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	char	*program_path;
	int		execve_result;
	int		pipes[3][2];
	int		fd_tmp;
	int		redirect_fd;
	ssize_t	read_size;
	char	*buffer;
	char	**cmd_args;
	pid_t	pid[2];

	if (argc <= 1)
		return (EXIT_FAILURE);
	redirect_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (access(argv[1], R_OK) == -1)
	{
		write(2, "bash: ", 6);
		perror(argv[1]);
		fd_tmp = -1;
	}
	else
		fd_tmp = 0;
	if (pipe(pipes[0]) == -1)
		return (print_strerror(argv[0]));
	if (pipe(pipes[1]) == -1)
	{
		close(pipes[0][0]);
		close(pipes[0][1]);
		return (print_strerror(argv[0]));
	}
	buffer = malloc(sizeof(char) * (size_t)BUFFER_SIZE);
	if (!buffer)
		return print_strerror(argv[0]);
	pid[0] = fork();
	cmd_args = NULL;
	if (pid[0] < 0)
		return (print_strerror(argv[0]));
	else if (pid[0] == 0)
	{
		close(pipes[0][1]);
		close(pipes[1][0]);
		cmd_args = ft_split(argv[2], ' ');
		if (!cmd_args)
			return (print_strerror(argv[0]));
		if (cmd_args[0][0] == '.' || cmd_args[0][0] == '/')
			program_path = ft_strdup(cmd_args[0]);
		else
			program_path = find_path_in_envp(cmd_args[0], envp);
		dup2(pipes[0][0], STDIN_FILENO);
		dup2(pipes[1][1], STDOUT_FILENO);
		close(pipes[0][0]);
		close(pipes[1][1]);
		execve_result = execve(program_path, cmd_args, envp);
		if (execve_result == -1)
		{
			free(program_path);
			return (print_strerror(cmd_args[0]));
		}
	}
	else
	{
		if (fd_tmp != -1)
		{
			fd_tmp = open(argv[1], O_RDONLY);
			if (fd_tmp < 0)
				perror(argv[1]);
			else
			{
				read_size = read(fd_tmp, buffer, (size_t)BUFFER_SIZE);
				while (read_size > 0)
				{
					write(pipes[0][1], buffer, read_size);
					read_size = read(fd_tmp, buffer, (size_t)BUFFER_SIZE);
				}
			}
		}
		close(pipes[0][0]);
		close(pipes[0][1]);
	}
	pipe(pipes[2]);
	pid[1] = fork();
	if (pid[1] < 0)
	{
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
	else if (pid[1] == 0)
	{
		close(pipes[1][1]);
		close(pipes[2][0]);
		close(pipes[2][1]);
		free(cmd_args);
		cmd_args = ft_split(argv[3], ' ');
		if (!cmd_args)
			exit(EXIT_FAILURE);
		program_path = find_path_in_envp(cmd_args[0], envp);
		dup2(pipes[1][0], STDIN_FILENO);
		dup2(redirect_fd, STDOUT_FILENO);
		close(pipes[1][0]);
		close(redirect_fd);
		execve_result = execve(program_path, cmd_args, envp);
		if (execve_result == -1)
		{
			perror(cmd_args[0]);
			free(program_path);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		close(pipes[1][0]);
		close(pipes[1][1]);
		close(pipes[2][1]);
		close(pipes[2][0]);
		close(redirect_fd);
	}
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	// read_size = read(pipes[2][0], buffer, BUFFER_SIZE);
	// while (read_size > 0)
	// {
	// 	write(redirect_fd, buffer, read_size);
	// 	read_size = read(pipes[2][0], buffer, BUFFER_SIZE);
	// }
	// close(pipes[2][0]);
	// close(redirect_fd);
	free(buffer);
	return (EXIT_SUCCESS);
}

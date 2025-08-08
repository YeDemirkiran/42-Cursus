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

int	main(int argc, char **argv, char **envp)
{
	char	*program_path;
	int		execve_result;
	int		pipes[3][2];
	int		fd_tmp;
	size_t	read_size;
	char	*buffer;
	char	**cmd_args;
	pid_t	pid[2];

	if (argc <= 1)
		return (EXIT_FAILURE);
	if (access(argv[1], R_OK) == -1)
	{
		write(2, "bash: ", 6);
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, ": ", 2);
		perror(NULL);
	}
	if (pipe(pipes[0]) == -1)
		return (EXIT_FAILURE);
	if (pipe(pipes[1]) == -1)
	{
		close(pipes[0][0]);
		close(pipes[0][1]);
		return (EXIT_FAILURE);
	}
	pid[0] = fork();
	cmd_args = NULL;
	if (pid[0] < 0)
	{
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
	else if (pid[0] == 0)
	{
		cmd_args = ft_split(argv[2], ' ');
		if (!cmd_args)
			exit(EXIT_FAILURE);
		if (cmd_args[0][0] == '.' || cmd_args[0][0] == '/')
			program_path = ft_strdup(cmd_args[0]);
		else
			program_path = find_path_in_envp(cmd_args[0], envp);
		dup2(pipes[0][0], STDIN_FILENO);
		dup2(pipes[1][1], STDOUT_FILENO);
		close(pipes[0][0]);
		close(pipes[0][1]);
		close(pipes[1][0]);
		close(pipes[1][1]);
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
		close(pipes[0][0]);
		fd_tmp = open(argv[1], O_RDONLY);
		buffer = malloc(sizeof(char) * (size_t)BUFFER_SIZE);
		if (fd_tmp < 0 || !buffer)
			exit (EXIT_FAILURE);
		read_size = read(fd_tmp, buffer, (size_t)BUFFER_SIZE);
		while (read_size > 0)
		{
			write(pipes[0][1], buffer, read_size);
			read_size = read(fd_tmp, buffer, (size_t)BUFFER_SIZE);
		}
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
		free(cmd_args);
		cmd_args = ft_split(argv[3], ' ');
		if (!cmd_args)
			exit(EXIT_FAILURE);
		program_path = find_path_in_envp(cmd_args[0], envp);
		dup2(pipes[1][0], STDIN_FILENO);
		dup2(pipes[2][1], STDOUT_FILENO);
		close(pipes[1][0]);
		close(pipes[1][1]);
		close(pipes[2][0]);
		close(pipes[2][1]);
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
	}
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	fd_tmp = open(argv[4], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	read_size = read(pipes[2][0], buffer, BUFFER_SIZE);
	while (read_size > 0)
	{
		write(fd_tmp, buffer, read_size);
		read_size = read(pipes[2][0], buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (EXIT_SUCCESS);
}

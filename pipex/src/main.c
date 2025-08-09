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

static void	strerror_exit(char *perror_str)
{
	perror(perror_str);
	exit(EXIT_FAILURE);
}

static void prepare_vars(char ***cmd_args, char **buffer)
{
	*cmd_args = NULL;
	*buffer = malloc(sizeof(char) * (size_t)BUFFER_SIZE);
	if (!*buffer)
		strerror_exit("pipex");
}

static void	prepare_files(char *input_file_path, char *output_file_path, int *io_fd)
{
	if (access(input_file_path, R_OK) < 0)
	{
		write(2, "bash: ", 6);
		perror(output_file_path);
		io_fd[0] = -1;
	}
	else
	{
		io_fd[0] = open(input_file_path, O_RDONLY);
		dup2(io_fd[0], STDIN_FILENO);
		close(io_fd[0]);
	}
	io_fd[1] = open(output_file_path, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (io_fd[1] < 0)
		strerror_exit("pipex: open");
}

int	main(int argc, char **argv, char **envp)
{
	char	*program_path;
	int		execve_result;
	int		pipes[3][2];
	int		io_fd[2];
	char	*buffer;
	char	**cmd_args;
	pid_t	pid[2];

	if (argc <= 1)
		return (EXIT_FAILURE);
	prepare_vars(&cmd_args, &buffer);
	prepare_files(argv[1], argv[4], io_fd);
	if (pipe(pipes[0]) == -1)
		return (print_strerror(argv[0]));
	pid[0] = fork();
	if (pid[0] < 0)
		return (print_strerror(argv[0]));
	else if (pid[0] == 0)
	{
		close(pipes[0][0]);
		cmd_args = ft_split(argv[2], ' ');
		if (!cmd_args)
			strerror_exit(cmd_args[0]);
		program_path = parse_program_path(cmd_args[0], envp);
		dup2(pipes[0][1], STDOUT_FILENO);
		close(pipes[0][1]);
		execve_result = execve(program_path, cmd_args, envp);
		if (execve_result == -1)
		{
			free(program_path);
			strerror_exit(cmd_args[0]);
		}
	}
	else
		close(pipes[0][1]);
	pid[1] = fork();
	if (pid[1] < 0)
	{
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
	else if (pid[1] == 0)
	{
		cmd_args = ft_split(argv[3], ' ');
		if (!cmd_args)
			strerror_exit(cmd_args[0]);
		program_path = parse_program_path(cmd_args[0], envp);
		dup2(pipes[0][0], STDIN_FILENO);
		dup2(io_fd[1], STDOUT_FILENO);
		close(pipes[0][0]);
		close(io_fd[1]);
		execve_result = execve(program_path, cmd_args, envp);
		if (execve_result == -1)
		{
			free(program_path);
			strerror_exit(cmd_args[0]);
		}
	}
	else
	{
		close(pipes[0][0]);
		close(io_fd[1]);
	}
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	free(buffer);
	return (EXIT_SUCCESS);
}

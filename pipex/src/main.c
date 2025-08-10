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

static void	strerror_exit(char *perror_str, int free_str)
{
	perror(perror_str);
	if (free_str)
		free(perror_str);
	exit(EXIT_FAILURE);
}

static void	prepare_files(char *input_file_path, char *output_file_path,
		int *io_fd)
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
		strerror_exit("pipex: open", 0);
}

static void	set_fds(t_fd_info fd_info)
{
	int	i;

	i = 0;
	while (fd_info.fds_to_close_immediately
		&& fd_info.fds_to_close_immediately[i] != -1)
		close(fd_info.fds_to_close_immediately[i++]);
	if (fd_info.stdin_fd >= 0)
	{
		dup2(fd_info.stdin_fd, STDIN_FILENO);
		close(fd_info.stdin_fd);
	}
	if (fd_info.stdout_fd >= 0)
	{
		dup2(fd_info.stdout_fd, STDOUT_FILENO);
		close(fd_info.stdout_fd);
	}
}

static void	free_string_array(char **arr)
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

static pid_t	create_child_process(char *program_name, char *program_args,
		char **envp, t_fd_info fd_info)
{
	int		pid;
	char	**cmd_args;
	char	*program_path;

	pid = fork();
	if (pid < 0)
		strerror_exit(program_name, 0);
	else if (pid == 0)
	{
		cmd_args = ft_split(program_args, ' ');
		if (!cmd_args)
			strerror_exit(program_name, 0);
		program_path = parse_program_path(cmd_args[0], envp);
		if (!program_path)
		{
			write(2, cmd_args[0], ft_strlen(cmd_args[0]));
			write(2, ": command not found\n", 20);
			free_string_array(cmd_args);
			exit(EXIT_FAILURE);
		}
		set_fds(fd_info);
		execve(program_path, cmd_args, envp);
		free(program_path);
		free_string_array(cmd_args);
		strerror_exit(program_name, 0);
	}
	return (pid);
}

int	main(int argc, char **argv, char **envp)
{
	int			pipes[3][2];
	int			io_fd[2];
	pid_t		pid[2];
	t_fd_info	fd_info;

	if (argc <= 1)
		return (EXIT_FAILURE);
	prepare_files(argv[1], argv[4], io_fd);
	if (pipe(pipes[0]) == -1)
		strerror_exit(argv[0], 0);
	fd_info.fds_to_close_immediately = malloc(sizeof(int) * 2);
	fd_info.fds_to_close_immediately[0] = pipes[0][0];
	fd_info.fds_to_close_immediately[1] = -1;
	fd_info.stdin_fd = -1;
	fd_info.stdout_fd = pipes[0][1];
	pid[0] = create_child_process(argv[0], argv[2], envp, fd_info);
	close(pipes[0][1]);
	free(fd_info.fds_to_close_immediately);
	fd_info.fds_to_close_immediately = NULL;
	fd_info.stdin_fd = pipes[0][0];
	fd_info.stdout_fd = io_fd[1];
	pid[1] = create_child_process(argv[0], argv[3], envp, fd_info);
	close(pipes[0][0]);
	close(io_fd[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	return (EXIT_SUCCESS);
}

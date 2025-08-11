/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:54:22 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/11 12:46:11 by yademirk         ###   ########.fr       */
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
		io_fd[0] = 0;
	}
	else
	{
		io_fd[0] = open(input_file_path, O_RDONLY);
	}
	io_fd[1] = open(output_file_path, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (io_fd[1] < 0)
		strerror_exit("pipex: open", 0);
}

static int	**prepare_pipes(int pipe_count)
{
	int	i;
	int	**pipes;

	i = 0;
	pipes = malloc(sizeof(int *) * pipe_count);
	if (!pipes)
		strerror_exit("pipex", 0);
	while (i < pipe_count)
	{
		pipes[i] = malloc(sizeof(int) * 2);
		if (!pipes[i])
			strerror_exit("pipex", 0);
		if (pipe(pipes[i]) == -1)
			strerror_exit("pipex", 0);
		i++;
	}
	return (pipes);
}

static void	clear_pipes(int **pipes, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(pipes[i]);
		i++;
	}
	free(pipes);
}

static void	set_fds(t_fd_info fd_info)
{
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

static void create_child_process(char *main_name, char *program_args,
		char **envp, t_fd_info fd_info)
{
	char		**cmd_args;
	char		*program_path;

	cmd_args = ft_split(program_args, ' ');
	if (!cmd_args)
		strerror_exit(main_name, 0);
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
	strerror_exit(main_name, 0);
}

static pid_t	create_first_process(t_proc_info proc_info,
	int *pipe, int stdin_fd)
{
	pid_t		pid;
	t_fd_info	fd_info;

	pid = fork();
	if (pid < 0)
		strerror_exit(proc_info.main_name, 0);
	else if (pid == 0)
	{
		close(pipe[0]);
		fd_info.stdin_fd = stdin_fd;
		fd_info.stdout_fd = pipe[1];
		create_child_process(proc_info.main_name, proc_info.cmd_args, proc_info.envp, fd_info);
	}
	close(stdin_fd);
	close(pipe[1]);
	return (pid);
}

static pid_t	create_normal_process(t_proc_info proc_info,
	int *in_pipe, int *out_pipe)
{
	pid_t		pid;
	t_fd_info	fd_info;

	pid = fork();
	if (pid < 0)
		strerror_exit(proc_info.main_name, 0);
	else if (pid == 0)
	{
		close(out_pipe[0]);
		fd_info.stdin_fd = in_pipe[0];
		fd_info.stdout_fd = out_pipe[1];
		create_child_process(proc_info.main_name, proc_info.cmd_args, proc_info.envp, fd_info);
	}
	close(in_pipe[0]);
	close(out_pipe[1]);
	return (pid);
}

static pid_t	create_last_process(t_proc_info proc_info,
	int *pipe, int stdout_fd)
{
	pid_t		pid;
	t_fd_info	fd_info;

	pid = fork();
	if (pid < 0)
		strerror_exit(proc_info.main_name, 0);
	else if (pid == 0)
	{
		fd_info.stdin_fd = pipe[0];
		fd_info.stdout_fd = stdout_fd;
		create_child_process(proc_info.main_name, proc_info.cmd_args, proc_info.envp, fd_info);
	}
	close(pipe[0]);
	close(stdout_fd);
	return (pid);
}

static void	wait_all_processes(pid_t *pids)
{
	int	i;

	i = 0;
	while (pids[i] >= 0)
	{
		waitpid(pids[i], NULL, 0);
		i++;
	}
	free(pids);
}


int	main(int argc, char **argv, char **envp)
{
	int			**pipes;
	int			io_fd[2];
	pid_t		*pids;
	int			i;
	t_proc_info	proc_info;

	if (argc <= 4)
	{
		write(2,
			"usage: pipex [infile] [cmd1] [cmd2] ...[cmd n] [outfile]\n", 58);
		return (EXIT_FAILURE);
	}
	prepare_files(argv[1], argv[argc - 1], io_fd);
	pipes = prepare_pipes(argc - 4);
	pids = malloc(sizeof(pid_t) * argc - 2);
	pids[argc - 3] = -1;
	proc_info.main_name = argv[0];
	proc_info.envp = envp;
	proc_info.cmd_args = argv[2];
	pids[0] = create_first_process(proc_info, pipes[0], io_fd[0]);
	i = 1;
	while (i < argc - 4)
	{
		proc_info.cmd_args = argv[i + 2];
		pids[i] = create_normal_process(proc_info, pipes[i - 1], pipes[i]);
		i++;
	}
	proc_info.cmd_args = argv[i + 2];
	pids[argc - 4] = create_last_process(proc_info, pipes[i - 1], io_fd[1]);
	wait_all_processes(pids);
	clear_pipes(pipes, 1);
	return (EXIT_SUCCESS);
}

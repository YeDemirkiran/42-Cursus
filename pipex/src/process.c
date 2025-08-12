/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:04:11 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/11 17:18:14 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_cmd_not_found(char *cmd_name)
{
	if (cmd_name)
		write(2, cmd_name, ft_strlen(cmd_name));
	write(2, ": command not found\n", 20);
}

void	create_child_process(char *main_name, char *program_args,
		char **envp, t_fd_info fd_info)
{
	char		**cmd_args;
	char		*program_path;

	if (program_args == NULL || ft_strlen(program_args) == 0)
		print_cmd_not_found(" ");
	cmd_args = ft_split(program_args, ' ');
	if (!cmd_args || cmd_args[0] == NULL)
	{
		if (cmd_args)
			free_string_array(cmd_args);
		print_cmd_not_found(program_args);
		exit(EXIT_FAILURE);
	}
	program_path = parse_program_path(cmd_args[0], envp);
	if (!program_path)
	{
		print_cmd_not_found(cmd_args[0]);
		free_string_array(cmd_args);
		exit(EXIT_FAILURE);
	}
	set_fds(fd_info);
	execve(program_path, cmd_args, envp);
	free(program_path);
	free_string_array(cmd_args);
	strerror_exit(main_name, 0);
}

pid_t	create_first_process(t_proc_info proc_info,
	int *pipe, int stdin_fd)
{
	pid_t		pid;
	t_fd_info	fd_info;

	if (stdin_fd < 0)
	{
		close(pipe[1]);
		return (-1);
	}
	pid = fork();
	if (pid < 0)
		strerror_exit(proc_info.main_name, 0);
	else if (pid == 0)
	{
		close(pipe[0]);
		fd_info.stdin_fd = stdin_fd;
		fd_info.stdout_fd = pipe[1];
		create_child_process(proc_info.main_name, proc_info.cmd_args,
			proc_info.envp, fd_info);
	}
	if (stdin_fd > 2)
		close(stdin_fd);
	close(pipe[1]);
	return (pid);
}

pid_t	create_normal_process(t_proc_info proc_info,
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
		create_child_process(proc_info.main_name, proc_info.cmd_args,
			proc_info.envp, fd_info);
	}
	close(in_pipe[0]);
	close(out_pipe[1]);
	return (pid);
}

pid_t	create_last_process(t_proc_info proc_info,
	int *pipe, char *stdout_path, int is_heredoc)
{
	pid_t		pid;
	t_fd_info	fd_info;

	pid = fork();
	if (pid < 0)
		strerror_exit(proc_info.main_name, 0);
	else if (pid == 0)
	{
		fd_info.stdin_fd = pipe[0];
		fd_info.stdout_fd = prepare_stdout(stdout_path, is_heredoc);
		create_child_process(proc_info.main_name, proc_info.cmd_args,
			proc_info.envp, fd_info);
	}
	close(pipe[0]);
	return (pid);
}

int	wait_all_processes(pid_t *pids)
{
	int	i;
	int	stat;

	i = 0;
	stat = 0;
	while (pids[i] != -2)
	{
		if (pids[i] == -1)
		{
			i++;
			continue ;
		}
		if (pids[i + 1] < 0)
			waitpid(pids[i], &stat, 0);
		else
			waitpid(pids[i], NULL, 0);
		i++;
	}
	return (stat);
}

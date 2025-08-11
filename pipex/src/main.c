/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:54:22 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/11 15:07:35 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int			pipes[BUFFER_SIZE][2];
	int			io_fd[2];
	pid_t		pids[BUFFER_SIZE];
	int			i;
	t_proc_info	proc_info;

	if (argc <= 4)
	{
		write(2,
			"usage: pipex [infile] [cmd1] [cmd2] ...[cmd n] [outfile]\n", 58);
		return (EXIT_FAILURE);
	}
	prepare_files(argv[1], argv[argc - 1], io_fd);
	prepare_pipes(pipes, argc - 4);
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
	return (EXIT_SUCCESS);
}

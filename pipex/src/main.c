/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:54:22 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/11 17:18:24 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	on_wrong_usage(char **argv, int argc)
{
	if (argc < 5 || (ft_strncmp(argv[1], "here_doc", 9) == 0 && argc < 6))
	{
		write(2,
			"usage: pipex { here_doc delimiter | infile } cmd1 cmd2"
			" [cmd3 ... cmd n] outfile\n", 80);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int			pipes[BUFFER_SIZE][2];
	int			io_fd[2];
	pid_t		pids[BUFFER_SIZE];
	int			i;
	t_proc_info	proc_info;

	on_wrong_usage(argv, argc);
	io_fd[1] = prepare_stdin(argv[1], io_fd, argv[2]);
	//printf("Pipe count: %i\n", argc - 4 - io_fd[1]);
	prepare_pipes(pipes, argc - 4 - io_fd[1]);
	pids[argc - 3 - io_fd[1]] = -2;
	proc_info.main_name = argv[0];
	proc_info.envp = envp;
	proc_info.cmd_args = argv[2 + io_fd[1]];
	pids[0] = create_first_process(proc_info, pipes[0], io_fd[0]);
	i = 1 + io_fd[1];
	while (i < argc - 4)
	{
		//printf("Normal proc %i\n", i);
		proc_info.cmd_args = argv[i + 2];
		pids[i] = create_normal_process(proc_info, pipes[i - 1 - io_fd[1]], pipes[i - io_fd[1]]);
		i++;
	}
	proc_info.cmd_args = argv[i + 2];
	pids[argc - 4 - io_fd[1]] = create_last_process(proc_info, pipes[i - 1 - io_fd[1]],
			argv[argc - 1], io_fd[1]);
	i = wait_all_processes(pids);
	unlink(TMP_FILE_PATH);
	return ((((i) & 0xff00) >> 8));
}

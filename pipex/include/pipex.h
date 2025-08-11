/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:54:41 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/11 16:13:58 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include "stdlib.h"
# include "fcntl.h"
# include "unistd.h"
# include "stdio.h"
# include "string.h"
# include "sys/wait.h"
# include "sys/stat.h"

# include "ft_string.h"

typedef struct s_proc_info
{
	char	*main_name;
	char	*cmd_args;
	char	**envp;
}				t_proc_info;

typedef struct s_fd_info
{
	int	stdin_fd;
	int	stdout_fd;
}				t_fd_info;

char	*parse_program_path(char *path, char **envp);

void	prepare_stdin(char *input_file_path,
			int *io_fd);
int		prepare_stdout(char *stdout_path);
void	prepare_pipes(int pipes[BUFFER_SIZE][2], int pipe_count);
void	set_fds(t_fd_info fd_info);

void	free_string_array(char **arr);
void	strerror_exit(char *perror_str, int free_str);

void	create_child_process(char *main_name, char *program_args,
			char **envp, t_fd_info fd_info);
pid_t	create_first_process(t_proc_info proc_info,
			int *pipe, int stdin_fd);
pid_t	create_normal_process(t_proc_info proc_info,
			int *in_pipe, int *out_pipe);
pid_t	create_last_process(t_proc_info proc_info,
			int *pipe, char *stdout_path);
int		wait_all_processes(pid_t *pids);

#endif
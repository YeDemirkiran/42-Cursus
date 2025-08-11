/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:54:41 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/11 12:33:43 by yademirk         ###   ########.fr       */
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

char	*parse_program_path(char *path, char **envp);

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

#endif
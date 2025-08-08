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

char	*find_path_in_envp(char *program, char **envp)
{
	int		i;
	int		j;
	int		a;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (envp[i] != NULL)
	{
		j = 0;
		tmp = ft_strdup("PATH");
		if (!tmp)
			return (NULL);
		while (envp[i][j] == tmp[j])
			j++;
		if (envp[i][j] == '=')
		{
			free(tmp);
			a = j;
			while (envp[i][j])
			{
				j = ++a;
				while (envp[i][a] && envp[i][a] != ':')
					a++;
				tmp = ft_substr(envp[i] + j, (size_t)0, (size_t)(a - j) + 1);
				if (!tmp)
					return (NULL);
				tmp[a - j] = '/';
				tmp2 = ft_strjoin(tmp, program);
				free(tmp);
				if (!tmp2)
					return (NULL);
				if (access(tmp2, F_OK) == 0)
					return (tmp2);
				free(tmp2);
				j = a;
			}
		}
		i++;
	}
	return (NULL);
}

// char	**get_args(char *str)
// {
// 	char	**args;


// }

int	main(int argc, char **argv, char **envp)
{
	char	*program_path;
	int		execve_result;
	int		pipe_1[2];
	int		pipe_2[2];
	int		fd_tmp;
	size_t	read_size;
	char	*buffer;
	char	**cmd_args;
	pid_t	pid[2];

	if (argc <= 1)
		return (EXIT_FAILURE);
	if (access(argv[1], R_OK) == -1)
		return (EXIT_FAILURE);
	if (pipe(pipe_1) == -1)
		return (EXIT_FAILURE);
	if (pipe(pipe_2) == -1)
	{
		close(pipe_1[0]);
		close(pipe_1[1]);
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
		close(pipe_1[1]);
		close(pipe_2[0]);
		cmd_args = ft_split(argv[2], ' ');
		if (!cmd_args)
			exit(EXIT_FAILURE);
		if (cmd_args[0][0] == '.' || cmd_args[0][0] == '/')
			program_path = ft_strdup(cmd_args[0]);
		else
			program_path = find_path_in_envp(cmd_args[0], envp);
		dup2(pipe_1[0], STDIN_FILENO);
		dup2(pipe_2[1], STDOUT_FILENO);
		close(pipe_1[0]);
		close(pipe_2[1]);
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
		close(pipe_1[0]);
		fd_tmp = open(argv[1], O_RDONLY);
		buffer = malloc(sizeof(char) * (size_t)BUFFER_SIZE);
		if (fd_tmp < 0 || !buffer)
			exit (EXIT_FAILURE);
		read_size = read(fd_tmp, buffer, (size_t)BUFFER_SIZE);
		while (read_size > 0)
		{
			write(pipe_1[1], buffer, read_size);
			read_size = read(fd_tmp, buffer, (size_t)BUFFER_SIZE);
		}
		close(pipe_1[1]);
		free(buffer);
	}
	pid[1] = fork();
	if (pid[1] < 0)
	{
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
	else if (pid[1] == 0)
	{
		close(pipe_2[1]);
		free(cmd_args);
		cmd_args = ft_split(argv[3], ' ');
		if (!cmd_args)
			exit(EXIT_FAILURE);
		program_path = find_path_in_envp(cmd_args[0], envp);
		dup2(pipe_2[0], STDIN_FILENO);
		close(pipe_2[0]);
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
		close(pipe_2[0]);
		close(pipe_2[1]);
	}
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	return (EXIT_SUCCESS);
}

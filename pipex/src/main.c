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
	char	**cmd_args;
	pid_t	pid[2];

	if (argc <= 1)
		return (EXIT_FAILURE);
		
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
		//printf("CMD: %s\n", cmd_args[0]);
		if (cmd_args[0][0] == '.' || cmd_args[0][0] == '/')
			program_path = ft_strdup(cmd_args[0]);
		else
			program_path = find_path_in_envp(cmd_args[0], envp);
		//printf("PROGRAM: %s\n", program_path);
		//printf("ARG 1: %s\n", *(cmd_args + 1));
		execve_result = execve(program_path, cmd_args, envp);
		if (execve_result == -1)
		{
			perror(cmd_args[0]);
			free(program_path);
			exit(EXIT_FAILURE);
		}
	}
	// pid[1] = fork();
	// if (pid < 0)
	// {
	// 	perror(argv[1]);
	// 	exit(EXIT_FAILURE);
	// }
	// else if (pid[1] == 0)
	// {
	// 	free(cmd_args);
	// 	cmd_args = ft_split(argv[3], ' ');
	// 	if (!cmd_args)
	// 		exit(EXIT_FAILURE);
	// 	program_path = find_path_in_envp(cmd_args[0], envp);
	// 	execve_result = execve(program_path, cmd_args + 1, envp);
	// 	if (execve_result == -1)
	// 	{
	// 		perror(cmd_args[0]);
	// 		free(program_path);
	// 		exit(EXIT_FAILURE);
	// 	}
	// }
	waitpid(pid[0], NULL, 0);
	//waitpid(pid[1], NULL, 0);
	return (EXIT_SUCCESS);
}

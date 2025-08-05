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

int	main(int argc, char **argv, char **envp)
{
	char	*program_path;
	int		execve_result;
	pid_t	pid;

	if (argc < 1)
		return (EXIT_FAILURE);
	pid = fork();
	if (pid < 0)
	{
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		program_path = find_path_in_envp(argv[1], envp);
		execve_result = execve(program_path, argv + 1, envp);
		if (execve_result == -1)
		{
			perror(argv[1]);
			free(program_path);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);
	return (EXIT_SUCCESS);
}

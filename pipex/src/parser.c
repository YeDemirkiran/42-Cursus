#include "pipex.h"

static char	*find_path_variable(char **envp)
{
	const char	*str = "PATH";
	int			i;
	int			j;

	i = 0;
	while (envp[i] != NULL)
	{
		j = 0;
		while (envp[i][j] == str[j])
			j++;
		if (envp[i][j] == '=')
			return (envp[i] + j + 1);
		i++;
	}
	return (NULL);
}

static char	*ft_append(char *s1, char *s2, int free_1, int free_2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = ft_strjoin(s1, s2);
	if (!str)
		return (NULL);
	if (free_1)
		free(s1);
	if (free_2)
		free(s2);
	return (str);
}

static char	*create_program_path(char *program_name, char *start, size_t len)
{
	char	*path;

	path = ft_substr(start, (size_t)0, len);
	if (!path)
		return (NULL);
	path[len - 1] = '/';
	path = ft_append(path, program_name, 1, 0);
	return (path);
}

static char	*find_path_in_envp(char *program, char **envp)
{
	int		i;
	int		a;
	char	*path_var;
	char	*program_path;

	path_var = find_path_variable(envp);
	if (!path_var)
		return (NULL);
	a = 0;
	while (path_var[a])
	{
		i = a;
		while (path_var[a] && path_var[a] != ':')
			a++;
		program_path = create_program_path(program, path_var + i, a - i + 1);
		if (!program_path)
			return (NULL);
		if (access(program_path, F_OK) == 0)
			return (program_path);
		free(program_path);
		if (path_var[a] == ':')
			a++;
	}
	return (NULL);
}

char	*parse_program_path(char *path, char **envp)
{
	char	*program_path;

	if ((path[0] == '.' && path[1] == '/') || path[0] == '/')
		program_path = ft_strdup(path);
	else
		program_path = find_path_in_envp(path, envp);
	return (program_path);
}

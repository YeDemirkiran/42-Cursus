#include "libft.h"

static size_t ft_strcnt(const char *s, char c);

char	**ft_split(const char *s, char c)
{
	char	**str_arr;
	size_t	words;
	size_t	i;

	words = ft_strcnt(s, c) + 1;
	str_arr = malloc((words + 1) * sizeof(char *));
	if (!str_arr)
		return (NULL);
	str_arr[words] = NULL;
	while (*s)
	{
		i = 0;
		while (s[i] && s[i++] != c);
		*str_arr = malloc(i);
		ft_strlcpy(*(str_arr++), s, i);
		s += i;
	}
	return (str_arr - words);
}

static size_t ft_strcnt(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*(s++) == c)
			count++;
	}
	return (count);
}

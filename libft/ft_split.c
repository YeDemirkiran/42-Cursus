/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:49:56 by yademirk          #+#    #+#             */
/*   Updated: 2025/06/12 17:49:56 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *s, char c);

char	**ft_split(const char *s, char c)
{
	char	**str_arr;
	size_t	words;
	size_t	i;

	words = word_count(s, c);
	str_arr = malloc((words + 1) * sizeof(char *));
	if (!str_arr)
		return (NULL);
	str_arr[words] = NULL;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == 0)
			break ;
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		i++;
		*str_arr = malloc(i);
		ft_strlcpy(*str_arr, s, i);
		s += i;
		str_arr++;
	}
	return (str_arr - words);
}

static size_t	word_count(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (i && ((s[i] == c && s[i - 1] != c)
				|| (s[i] != c && !s[i + 1])))
			count++;
		i++;
	}
	return (count);
}

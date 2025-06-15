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
static void		*clear_alloc(char **s, size_t j);

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	size_t	len;
	size_t	j;

	str_arr = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!str_arr)
		return (NULL);
	j = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		str_arr[j] = malloc(len + 1);
		if (!str_arr[j])
			return (clear_alloc(str_arr, j));
		ft_strlcpy(str_arr[j++], s, len + 1);
		s += len;
	}
	str_arr[j] = NULL;
	return (str_arr);
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

static void	*clear_alloc(char **s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		free(s[i++]);
	free(s);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:22:10 by yademirk          #+#    #+#             */
/*   Updated: 2025/06/21 11:22:11 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*char_rep(char c, size_t len)
{
	char	*str;

	if (!len)
		return (NULL);
	str = ft_calloc(len + 1, sizeof(char));
	if (str)
	{
		while (len-- > 0)
			str[len] = c;
	}
	return (str);
}

static char	*ft_strapp(char *str1, char *str2)
{
	char	*str;

	if (!str1 || !str2)
		return (NULL);
	str = ft_strjoin(str1, str2);
	if (str)
	{
		free(str1);
		free(str2);
	}
	return (str);
}

void	str_pad_char(char **str, char c, size_t amount)
{
	char	*tmp;

	tmp = char_rep(c, amount);
	*str = ft_strapp(tmp, *str);
}

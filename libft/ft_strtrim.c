/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:50:18 by yademirk          #+#    #+#             */
/*   Updated: 2025/06/12 18:22:30 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	ft_in_str(const char *str, char c);

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	len;
	char	*str;
	size_t	start_index;
	size_t	end_index;

	len = ft_strlen(s1);
	start_index = 0;
	while (s1[start_index] && ft_strchr(set, s1[start_index]))
		start_index++;
	end_index = len - 1;
	while (ft_strchr(set, s1[end_index]) && end_index > 0)
		end_index--;
	if (end_index > start_index)
		len = end_index - start_index + 1;
	else
		len = 0;
	str = ft_substr(s1, start_index, len);
	if (str == NULL)
		return (NULL);
	return (str);
}

// static int	ft_in_str(const char *str, char c)
// {
// 	if (ft_strchr(str, c) != NULL)
// 		return (1);
// 	return (0);
// }

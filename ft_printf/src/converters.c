/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:22:21 by yademirk          #+#    #+#             */
/*   Updated: 2025/06/25 13:37:39 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_char(char c)
{
	char	*str;

	str = ft_calloc(2, sizeof(char));
	if (!str)
		return (NULL);
	*str = c;
	return (str);
}

char	*convert_string(char *str, t_conv_rule rule)
{
	char	*new;
	size_t	len;

	if (!str)
	{
		if (rule.max_width <= 0 || rule.max_width >= 6)
			new = ft_strdup("(null)");
		else
			new = NULL;
	}
	else if (rule.max_width > 0)
	{
		len = ft_smaller((size_t)rule.max_width, ft_strlen(str)) + 1;
		new = malloc(len);
		ft_strlcpy(new, str, len);
	}
	else if (rule.max_width == 0)
		new = NULL;
	else
		new = ft_strdup(str);
	return (new);
}

char	*convert_int(int num, t_conv_rule rule)
{
	char	*str;
	size_t	len;
	int		extra;

	if (rule.max_width == 0 && !num)
		return (NULL);
	str = ft_utoa(ft_abs(num));
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	extra = (num < 0 || rule.format & (F_PLUS | F_SPACE));
	if ((int)len < rule.max_width)
		str_pad_char(&str, '0', rule.max_width - len);
	else if (rule.format & F_ZERO && ((int)len) + extra < rule.min_width
		&& 0 > rule.max_width)
		str_pad_char(&str, '0', rule.min_width - len - extra);
	if (num >= 0 && rule.format & F_PLUS)
		str_pad_char(&str, '+', 1);
	else if (num >= 0 && rule.format & F_SPACE)
		str_pad_char(&str, ' ', 1);
	else if (num < 0)
		str_pad_char(&str, '-', 1);
	return (str);
}

char	*convert_uint(unsigned int num, t_conv_rule rule)
{
	char	*str;
	size_t	len;

	if (rule.max_width == 0 && !num)
		return (NULL);
	str = ft_utoa(num);
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if ((int)len < rule.max_width)
		str_pad_char(&str, '0', rule.max_width - len);
	else if (rule.format & F_ZERO && (int)len < rule.min_width
		&& 0 > rule.max_width)
		str_pad_char(&str, '0', rule.min_width - len);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:24:00 by yademirk          #+#    #+#             */
/*   Updated: 2025/06/25 13:37:24 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include "stdarg.h"

enum e_formats
{
	NONE = 0,
	F_PLUS = 1,
	F_MINUS = 2,
	F_ZERO = 4,
	F_SPACE = 8,
	F_HASH = 16,
	C_HEX_UP = 32,
	C_HEX_LOW = 64,
	C_UINT = 128,
	C_INT = 256,
	C_CHAR = 512,
	C_STR = 1024,
	C_POINTER = 2048,
	C_PERCENT = 4096
};

typedef struct s_conv_rule
{
	enum e_formats	format;
	int				format_len;
	int				min_width;
	int				max_width;
}				t_conv_rule;

int		is_flag(const char c);
int		is_formspec(const char c);

char	*ft_strapp(char *str1, char *str2);
void	str_pad_char(char **str, char c, size_t amount);

char	*convert_char(char c);
char	*convert_string(char *str, t_conv_rule rule);
char	*convert_int(int num, t_conv_rule rule);
char	*convert_uint(unsigned int num, t_conv_rule rule);
char	*convert_hex(unsigned int num, t_conv_rule rule);
char	*convert_pointer(void *p, t_conv_rule rule);

void	str_pad_char(char **str, char c, size_t amount);
int		ft_printf(const char *format, ...);

#endif
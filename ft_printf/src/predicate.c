#include "libftprintf.h"

int	is_flag(const char c)
{
	int	flag;

	flag = 0;
	if (c == '+')
		flag = F_PLUS;
	else if (c == '-')
		flag = F_MINUS;
	else if (c == '0')
		flag = F_ZERO;
	else if (c == ' ')
		flag = F_SPACE;
	else if (c == '#')
		flag = F_HASH;
	return (flag);
}

int	is_formspec(const char c)
{
	int	flag;

	flag = 0;
	if (c == 'c')
		flag = C_CHAR;
	else if (c == 's')
		flag = C_STR;
	else if (c == 'p')
		flag = C_POINTER;
	else if (c == 'd' || c == 'i')
		flag = C_INT;
	else if (c == 'u')
		flag = C_UINT;
	else if (c == 'x')
		flag = C_HEX_LOW;
	else if (c == 'X')
		flag = C_HEX_UP;
	else if (c == '%')
		flag = C_PERCENT;
	return (flag);
}

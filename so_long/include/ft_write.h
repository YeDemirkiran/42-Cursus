#ifndef FT_WRITE_H
# define FT_WRITE_H

# include "unistd.h"
# include "ft_string.h"

void	ft_putchar_fd(char c, int fd);
void	ft_putchar(char c);
void	ft_putstr_fd(char *str, int fd);
void	ft_putstr(char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr(int n);

#endif
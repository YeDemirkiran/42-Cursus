#ifndef WRITE_H
# define WRITE_H

# include "dependencies.h"
# include "ft_string.h"

void	ft_putchar_fd(char c, int fd);
void	ft_putchar(char c);
void	ft_putstr_fd(char *str, int fd);
void	ft_putstr(char *str);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 16:12:35 by yademirk          #+#    #+#             */
/*   Updated: 2025/07/01 17:16:28 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "stdlib.h"
# include "unistd.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

void	gnl_strlcpy(char *dst, const char *src, size_t size);
char	*gnl_substr(char const *s, size_t start, size_t len);
char	*gnl_strjoin(char *s1, char *s2, int free_1, int free_2);
int		gnl_alloc_buffer(char ***buffer, int fd);
int		gnl_expand_buffer(int fd, char ***buffer, ssize_t i);

char	*get_next_line(int fd);

#endif
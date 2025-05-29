/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 12:07:51 by yademirk          #+#    #+#             */
/*   Updated: 2025/05/29 14:41:09 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	tmp_src[10000];

	ft_memcpy(tmp_src, (unsigned char *)src, n);
	ft_memcpy((unsigned char *)dest, tmp_src, n);
	return (dest);
}

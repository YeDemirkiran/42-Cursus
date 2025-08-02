/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:56:34 by yademirk          #+#    #+#             */
/*   Updated: 2025/08/02 11:56:38 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

int	*dup_int_array(const int *src, size_t len)
{
	int	*dup;

	dup = malloc(len * sizeof(int));
	if (!dup)
		return (NULL);
	while (len--)
		dup[len] = src[len];
	return (dup);
}

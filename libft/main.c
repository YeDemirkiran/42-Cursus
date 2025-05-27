/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:47:35 by yademirk          #+#    #+#             */
/*   Updated: 2025/05/27 13:18:01 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

void	test_ft_isalpha(void)
{
	printf("Testing 'ft_isalpha'...\n\n");
	printf("'A', isalpha: %i, ft_isalpha:%i\n", isalpha('A'), ft_isalpha('A'));
	printf("'a', isalpha: %i, ft_isalpha:%i\n", isalpha('a'), ft_isalpha('a'));
	printf("'Z', isalpha: %i, ft_isalpha:%i\n", isalpha('Z'), ft_isalpha('Z'));
	printf("'z', isalpha: %i, ft_isalpha:%i\n", isalpha('z'), ft_isalpha('z'));
	printf("'.', isalpha: %i, ft_isalpha:%i\n", isalpha('.'), ft_isalpha('.'));
	printf("',', isalpha: %i, ft_isalpha:%i\n", isalpha(','), ft_isalpha(','));
	printf("'4', isalpha: %i, ft_isalpha:%i\n", isalpha('4'), ft_isalpha('4'));
	printf("NULL, isalpha: %i, ft_isalpha:%i\n", isalpha(0), ft_isalpha(0));
}

void	test_ft_isdigit(void)
{
	printf("Testing 'ft_isdigit'...\n\n");
	printf("'0', isalpha: %i, ft_isalpha:%i\n", isdigit('0'), ft_isdigit('0'));
	printf("'9', isalpha: %i, ft_isalpha:%i\n", isdigit('9'), ft_isdigit('9'));
	printf("'Z', isalpha: %i, ft_isalpha:%i\n", isdigit('Z'), ft_isdigit('Z'));
	printf("'z', isalpha: %i, ft_isalpha:%i\n", isdigit('z'), ft_isdigit('z'));
	printf("'.', isalpha: %i, ft_isalpha:%i\n", isdigit('.'), ft_isdigit('.'));
	printf("',', isalpha: %i, ft_isalpha:%i\n", isdigit(','), ft_isdigit(','));
	printf("'4', isalpha: %i, ft_isalpha:%i\n", isdigit('4'), ft_isdigit('4'));
	printf("NULL, isalpha: %i, ft_isalpha:%i\n", isalpha(0), ft_isdigit(0));
	printf("\n");
}

int	main(void)
{
	test_ft_isdigit();
	return (0);
}

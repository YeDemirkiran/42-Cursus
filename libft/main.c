/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:47:35 by yademirk          #+#    #+#             */
/*   Updated: 2025/05/27 15:09:49 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void	test_ft_isalpha(void)
{
	char *ft_func = "ft_isalpha"; 
	char *func = "isalpha";
	int tests[] = {'A', 'a', 'Z', 'z', '.', ',', '4', 0};

	printf("\nTesting '%s'...\n\n", ft_func);

	int i = 0;

	while (tests[i] != 0)
	{
		printf("'%c', %s: %i, %s: %i\n", tests[i], func, isalpha(tests[i]), ft_func, ft_isalpha(tests[i]));
		i++;
	}

	printf("NULL, %s: %i, %s: %i\n\n", func, isalpha(0), ft_func, ft_isalpha(0));
	
	printf("\n");
}

void	test_ft_isdigit(void)
{
	char *ft_func = "ft_isdigit"; 
	char *func = "isdigit";
	int tests[] = {'0', '9', 'Z', 'z', '.', ',', '4', 0};

	printf("\nTesting '%s'...\n\n", ft_func);

	int i = 0;

	while (tests[i] != 0)
	{
		printf("'%c', %s: %i, %s: %i\n", tests[i], func, isdigit(tests[i]), ft_func, ft_isdigit(tests[i]));
		i++;
	}

	printf("NULL, %s: %i, %s: %i\n\n", func, isdigit(0), ft_func, ft_isdigit(0));
	
	printf("\n");
}

void	test_ft_isalnum(void)
{
	char *ft_func = "ft_isalnum"; 
	char *func = "isalnum";
	int tests[] = {'0', '9', 'A', 'a', 'Z', 'z', '.', ',', '4', 0};

	printf("\nTesting '%s'...\n\n", ft_func);

	int i = 0;

	while (tests[i] != 0)
	{
		printf("'%c', %s: %i, %s: %i\n", tests[i], func, isalnum(tests[i]), ft_func, ft_isalnum(tests[i]));
		i++;
	}

	printf("NULL, %s: %i, %s: %i\n\n", func, isalnum(0), ft_func, ft_isalnum(0));
	
	printf("\n");
}

void	test_ft_isascii(void)
{
	char *ft_func = "ft_isascii"; 
	char *func = "isascii";
	int tests[] = {'0', '9', 'A', 'a', 'Z', 'z', '.', ',', '4', 128, 255, 0};

	printf("\nTesting '%s'...\n\n", ft_func);

	int i = 0;

	while (tests[i] != 0)
	{
		printf("'%c', %s: %i, %s: %i\n", tests[i], func, __isascii(tests[i]), ft_func, ft_isascii(tests[i]));
		i++;
	}

	printf("NULL, %s: %i, %s: %i\n\n", func, __isascii(0), ft_func, ft_isascii(0));
	
	printf("\n");
}

void	test_ft_isprint(void)
{
	char *ft_func = "ft_isprint"; 
	char *func = "isprint";
	int tests[] = {'0', '9', 'A', 'a', 'Z', 'z', '.', ',', '4', 126, 127, 31, 255, 0};

	printf("\nTesting '%s'...\n\n", ft_func);

	int i = 0;

	while (tests[i] != 0)
	{
		printf("'%c', %s: %i, %s: %i\n", tests[i], func, isprint(tests[i]), ft_func, ft_isprint(tests[i]));
		i++;
	}

	printf("NULL, %s: %i, %s: %i\n\n", func, isprint(0), ft_func, ft_isprint(0));
	
	printf("\n");
}

void	test_ft_strlen(void)
{
	char *ft_func = "ft_strlen"; 
	char *func = "strlen";
	char *tests[] = {"test", "test 2", "LOOOOOONG", "short", " ", "", 0};

	printf("\nTesting '%s'...\n\n", ft_func);

	int i = 0;

	while (tests[i] != 0)
	{
		printf("'%s', %s: %zu, %s: %zu\n", tests[i], func, strlen(tests[i]), ft_func, ft_strlen(tests[i]));
		i++;
	}
	
	printf("\n");
}

int	main(int count, char **args)
{
	if (count == 2)
	{
		if (strcmp(args[1], "isalpha") == 0)
			test_ft_isalpha();
		else if (strcmp(args[1], "isdigit") == 0)
			test_ft_isdigit();
		else if (strcmp(args[1], "isalnum") == 0)
			test_ft_isalnum();
		else if (strcmp(args[1], "isascii") == 0)
			test_ft_isascii();
		else if (strcmp(args[1], "isprint") == 0)
			test_ft_isprint();
		else if (strcmp(args[1], "strlen") == 0)
			test_ft_strlen();
	}
	else
	{
		printf("\nPlease provide only one argument!\n\n");
	}
	
	return (0);
}

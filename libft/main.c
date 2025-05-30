/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:47:35 by yademirk          #+#    #+#             */
/*   Updated: 2025/05/29 14:52:42 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <strings.h>

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
	char *tests[] = {"test", "test 2", "LOOOOOONG", "short", " ", "", 
		"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.",
		0};

	printf("\nTesting '%s'...\n\n", ft_func);

	int i = 0;

	while (*tests[i] != 0)
	{
		printf("'%s', %s: %zu, %s: %zu\n", tests[i], func, strlen(tests[i]), ft_func, ft_strlen(tests[i]));
		i++;
	}
	
	printf("\n");
}

void	test_ft_memset(void)
{
	char *ft_func = "ft_memset"; 
	char *func = "memset";

	printf("\nTesting '%s'...\n\n", ft_func);

	int sizes[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20};
	char chars[] = {'a', 'b', 'c', 'd', '&', '(', '7', 'Z', 'A', 'g', 'y', 'e'};
	int size = 12;
	int i = 0;

	while (i < size)
	{
		char a[] = "01234567891";
		char b[] = "01234567891";

		printf("'%s', %s(%c, %i): ", a, func, chars[i], sizes[i]);

		memset(a, chars[i], sizes[i]);

		printf("%s, %s(%c, %i): ", a, ft_func, chars[i], sizes[i]);

		ft_memset(b, chars[i], sizes[i]);

		printf("%s\n", b);

		i++;
	}

	printf("\n");
}

void	test_ft_bzero(void)
{
	char *ft_func = "ft_bzero"; 
	char *func = "bzero";

	printf("\nTesting '%s'...\n\n", ft_func);

	size_t sizes[] = {0, sizeof(int), 2 * sizeof(int), 3 * sizeof(int), 4 * sizeof(int), 5 * sizeof(int), 6 * sizeof(int), 7 * sizeof(int), 8 * sizeof(int), 9 * sizeof(int), 10 * sizeof(int)};
	int size = 11;
	int i = 0;

	while (i < size)
	{
		int a[] = {31, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		int b[] = {31, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		int test_size = 10;

		printf("(");

		int j = 0;

		while (j < test_size)
		{
			printf("%i ", a[j++]);
		}

		printf("), %s(%zu): ", func, sizes[i]);

		bzero(a, sizes[i]);

		printf("(");

		j = 0;

		while (j < test_size)
		{
			printf("%i ", a[j++]);
		}

		printf("), %s(%zu): ", ft_func, sizes[i]);

		ft_bzero(b, sizes[i]);

		printf("(");

		j = 0;

		while (j < test_size)
		{
			printf("%i ", a[j++]);
		}

		printf(")\n");

		i++;
	}

	printf("\n");
}

void	test_ft_memcpy(void)
{
	char *ft_func = "ft_memcpy"; 
	char *func = "memcpy";

	printf("\nTesting '%s'...\n\n", ft_func);

	printf("Normal test...\n\n");

	char a[] = "ABCDEFGH";
	char b[] = "abcdefgh";

	printf("Before %s: a: %s, b: %s\n", func, a, b);
	printf("After %s: a: %s, b: %s\n\n", func, (char *)memcpy(a, b, sizeof(char) * 4), b);

	memcpy(a, "ABCDEFGH", 9);

	printf("Before %s: a: %s, b: %s\n", ft_func, a, b);
	printf("After %s: a: %s, b: %s\n\n", ft_func, (char *)ft_memcpy(a, b, sizeof(char) * 4), b);

	// printf("Overlapping test...\n\n");

	// memcpy(a, "ABCDEFGH", 9);

	// printf("Before %s: a: %s, b: %s\n", func, a + 2, a);
	// printf("After %s: a: %s, b: %s\n\n", func, (char *)memcpy(a + 2, a, sizeof(char) * 4), a);

	// memcpy(a, "ABCDEFGH", 9);

	// printf("Before %s: a: %s, b: %s\n", func, a + 2, a);
	// printf("After %s: a: %s, b: %s\n\n", func, (char *)ft_memcpy(a + 2, a, sizeof(char) * 4), a);
}

void	test_ft_memmove(void)
{
	char *ft_func = "ft_memcpy"; 
	char *func = "memcpy";

	printf("\nTesting '%s'...\n\n", ft_func);

	printf("Normal test...\n\n");

	char a[] = "ABCDEFGH";
	char b[] = "abcdefgh";

	printf("Before %s: a: %s, b: %s\n", func, a, b);
	printf("After %s: a: %s, b: %s\n\n", func, (char *)memmove(a, b, sizeof(char) * 4), b);

	memcpy(a, "ABCDEFGH", 9);

	printf("Before %s: a: %s, b: %s\n", ft_func, a, b);
	printf("After %s: a: %s, b: %s\n\n", ft_func, (char *)ft_memmove(a, b, sizeof(char) * 4), b);

	printf("Overlapping test...\n\n");

	memcpy(a, "ABCDEFGH", 9);

	printf("Before %s: a: %s, b: %s\n", func, a + 2, a);
	printf("After %s: a: %s, b: %s\n\n", func, (char *)memmove(a + 2, a, sizeof(char) * 4), a);

	memcpy(a, "ABCDEFGH", 9);

	printf("Before %s: a: %s, b: %s\n", func, a + 2, a);
	printf("After %s: a: %s, b: %s\n\n", func, (char *)ft_memmove(a + 2, a, sizeof(char) * 4), a);
}

void	test_ft_toupper()
{
	char low = 'a';
	char tmp;
	char tmp2;

	printf("\nTesting toupper()...\n");

	while (low <= 'z')
	{
		tmp = toupper(low);
		tmp2 = ft_toupper(low);

		printf("\ntoupper() before: %c, char: %c, int: %i\n", low, tmp, (int)tmp);
		printf("ft_toupper() before: %c, char: %c, int: %i\n\n", low, tmp2, (int)tmp2);

		low++;
	}
}

void	test_ft_tolower()
{
	char up = 'A';
	char tmp;
	char tmp2;

	printf("\nTesting tolower()...\n");

	while (up <= 'Z')
	{
		tmp = tolower(up);
		tmp2 = ft_tolower(up);

		printf("\ntolower() before: %c, char: %c, int: %i\n", up, tmp, (int)tmp);
		printf("ft_tolower() before: %c, char: %c, int: %i\n\n", up, tmp2, (int)tmp2);

		up++;
	}
}

void	test_ft_strchr()
{
	char *s = "ABCDEFGH";
	char c = 0;

	printf("\nTesting strchr()...\n");

	printf("\nstrchr() string: %s, target: %c, col: %lu, pointer: %p", s, c, strchr(s, c) - s + 1, strchr(s, c));
	printf("\nft_strchr() string: %s, target: %c, col: %lu, pointer: %p\n\n", s, c, ft_strchr(s, c) - s + 1, ft_strchr(s, c));
}

void	test_ft_strrchr()
{
	char s[1024];
	char c;

	printf("\nTesting strrchr()...\n");

	printf(">>> Target string: ");
	scanf("%s", s);
	scanf("%c", &c);
	printf("\n>>> Target char: ");
	scanf("%c", &c);

	printf("\n\nstrrchr() string: %s, target: %c, col: %lu, pointer: %p", s, c, strrchr(s, c) - s + 1, strrchr(s, c));
	printf("\nft_strrchr() string: %s, target: %c, col: %lu, pointer: %p\n\n", s, c, ft_strrchr(s, c) - s + 1, ft_strrchr(s, c));
}

void	test_ft_strncmp()
{
	char s1[1024];
	char s2[1024];
	int		comp_byte;

	printf("\nTesting strnchr()...\n");

	printf(">>> Target string 1: ");
	scanf("%s", s1);
	printf("\n>>> Target string 2: ");
	scanf("%s", s2);
	printf("\n>>> Compare number: ");
	scanf("%i", &comp_byte);

	printf("\n\nstrncmp() string 1: %s, string 2: %s, compare bytes: %i, result: %i", s1, s2, comp_byte, strncmp(s1, s2, comp_byte));
	printf("\n\nft_strncmp() string 1: %s, string 2: %s, compare bytes: %i, result: %i\n\n", s1, s2, comp_byte, ft_strncmp(s1, s2, comp_byte));
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
		else if (strcmp(args[1], "memset") == 0)
			test_ft_memset();
		else if (strcmp(args[1], "bzero") == 0)
			test_ft_bzero();
		else if (strcmp(args[1], "memcpy") == 0)
			test_ft_memcpy();
		else if (strcmp(args[1], "memmove") == 0)
			test_ft_memmove();
		else if (strcmp(args[1], "toupper") == 0)
			test_ft_toupper();
		else if (strcmp(args[1], "tolower") == 0)
			test_ft_tolower();
		else if (strcmp(args[1], "strchr") == 0)
			test_ft_strchr();
		else if (strcmp(args[1], "strrchr") == 0)
			test_ft_strrchr();
		else if (strcmp(args[1], "strncmp") == 0)
			test_ft_strncmp();
	}
	else
	{
		printf("\nPlease provide only one argument!\n\n");
	}
	
	return (0);
}

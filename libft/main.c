/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:47:35 by yademirk          #+#    #+#             */
/*   Updated: 2025/06/02 13:00:55 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <bsd/string.h>
#include <errno.h>

int	ft_isnulterm(const char *s, size_t len)
{
	return (s[len - 1] == 0);
}

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

void	test_ft_memcmp()
{
	char s1[1024];
	char s2[1024];
	int		comp_byte;

	printf("\nTesting memcmp()...\n");

	printf(">>> Target string 1: ");
	scanf("%s", s1);
	printf("\n>>> Target string 2: ");
	scanf("%s", s2);
	printf("\n>>> Compare number: ");
	scanf("%i", &comp_byte);

	printf("\n\nmemcmp() string 1: %s, string 2: %s, compare bytes: %i, result: %i", s1, s2, comp_byte, memcmp(s1, s2, comp_byte));
	printf("\n\nft_memcmp() string 1: %s, string 2: %s, compare bytes: %i, result: %i\n\n", s1, s2, comp_byte, ft_memcmp(s1, s2, comp_byte));
}

void	test_ft_memchr()
{
	// int test[] = {0, 1, 2, 3, 4, 5};
	// int c = 2;

	// printf("\n\nmemchr() target: %i, col: %lu, pointer: %p", c, (int *)memchr(test, c, 5) - test + 1, memchr(test, c, 5));
	// printf("\nft_memchr() target: %i, col: %lu, pointer: %p\n\n", c, (int *)ft_memchr(test, c, 5) - test + 1, ft_memchr(test, c, 5));
	char s[1024];
	char c;
	int bytes;

	printf("\nTesting memchr()...\n");

	printf(">>> Target string: ");
	scanf("%s", s);
	
	scanf("%c", &c);
	printf("\n>>> Target char: ");
	scanf("%c", &c);
	printf("\n>>> Target compare bytes: ");
	scanf("%i", &bytes);

	printf("\n\nmemchr() target: %c, bytes: %i, col: %lu, pointer: %p", c, bytes, memchr(s, c, bytes) - (void *)s + 1, memchr(s, c, bytes));
	printf("\nft_memchr() target: %c, bytes: %i, col: %lu, pointer: %p\n\n", c, bytes, ft_memchr(s, c, bytes) - (void *)s + 1, ft_memchr(s, c, bytes));
}

void	test_ft_strnstr()
{
	char s1[1024];
	char s2[1024];
	int		comp_byte;

	printf("\nTesting strnstr()...\n");

	printf(">>> Target string 1: ");
	scanf("%s", s1);
	printf("\n>>> Target string 2: ");
	scanf("%s", s2);
	printf("\n>>> Compare number: ");
	scanf("%i", &comp_byte);

	printf("\n\nstrnstr() string 1: %s, string 2: %s, compare bytes: %i, result: %s, pointer: %p", s1, s2, comp_byte, strnstr(s1, s2, comp_byte), strnstr(s1, s2, comp_byte));
	printf("\n\nft_strnstr() string 1: %s, string 2: %s, compare bytes: %i, result: %s, pointer: %p\n\n", s1, s2, comp_byte, ft_strnstr(s1, s2, comp_byte), ft_strnstr(s1, s2, comp_byte));
}


void	test_ft_atoi()
{
	char s1[1024];

	printf("\n\nTesting ft_atoi()...\n\n");

	printf(">>> Target string: ");
	scanf("%s", s1);

	printf("\n\natoi() string: %s, result: %i", s1, atoi(s1));
	printf("\n\natoi() string: %s, result: %i\n\n", s1, ft_atoi(s1));
}

void	test_ft_strlcpy()
{
	char s1[21];
	char s2[21];
	int bytes;

	printf("\nTesting strlcpy()...\n");

	printf(">>> Target string (max 20 chars): ");
	scanf("%s", s1);

	printf("\n\n>>> Target string size (null terminator included): ");
	scanf("%i", &bytes);

	printf("\nstrlcpy() target string: %s, bytes: %i, result string: %s, result string length: %lu, returned int: %lu\n", s1, bytes, s2, ft_strlen(s2), strlcpy(s2, s1, bytes));

	ft_bzero(s2, 21);

	printf("\nft_strlcpy() target string: %s, bytes: %i, result string: %s, result string length: %lu, returned int: %lu\n\n", s1, bytes, s2, ft_strlen(s2), ft_strlcpy(s2, s1, bytes));
}

void	test_ft_strlcat()
{
	char s1[1024];
	char s2[1024];
	char s3[2048];
	size_t cat_size;

	printf("\nTesting strlcat()...\n");

	printf(">>> String 1: ");
	fgets(s1, 1024, stdin);
	*(ft_strrchr(s1, '\n')) = 0;

	printf(">>> String 2: ");
	fgets(s2, 1024, stdin);
	*(ft_strrchr(s2, '\n')) = 0;

	printf(">>> strlcat size: ");
	scanf("%lu", &cat_size);

	ft_strlcpy(s3, s1, ft_strlen(s1) + 1);

	size_t res = strlcat(s3, s2, cat_size);

	printf("\nstrlcat() String 1: %s, String 2: %s, strlcat size: %lu, result string: %s, result string length: %lu, returned size: %lu, result nul terminated: %i\n", s1, s2, cat_size, s3, ft_strlen(s3), res, ft_isnulterm(s3, cat_size));

	ft_bzero(s3, 2048);

	ft_strlcpy(s3, s1, ft_strlen(s1) + 1);
	res = ft_strlcat(s3, s2, cat_size);

	printf("\nft_strlcat() String 1: %s, String 2: %s, strlcat size: %lu, result string: %s, result string length: %lu, returned size: %lu, result nul terminated: %i\n", s1, s2, cat_size, s3, ft_strlen(s3), res, ft_isnulterm(s3, cat_size));
}

void	test_ft_strdup()
{
	char s1[1024];
	char *s2;

	printf("\nTesting strdup()...\n");

	printf(">>> Target string (max 1024 chars): ");
	fgets(s1, 1024, stdin);
	*ft_strrchr(s1, '\n') = 0;

	s2 = strdup(s1);

	printf("\nstrdup() target string: %s, target string length: %lu, result string: %s, result string length: %lu\n", s1, ft_strlen(s1), s2, ft_strlen(s2));
	printf("Attempting free() for strdup()...\n");
	free(s2);
	printf("No errors, which means free() was successful.\n");

	s2 = ft_strdup(s1);
	printf("\nft_strdup() target string: %s, target string length: %lu, result string: %s, result string length: %lu\n", s1, ft_strlen(s1), s2, ft_strlen(s2));
	printf("Attempting free() for ft_strdup()...\n");
	free(s2);
	printf("No errors, which means free() was successful.\n");
}

void	ft_printf_array(void *arr, char *seperator, size_t size)
{
	while (size-- > 0)
	{
		printf("%i", *(int *)(arr++));

		if (size != 0)
			printf("%s", seperator);
	}
}

void	test_ft_calloc()
{
	int	*array;
	size_t array_size;
	size_t s;

	printf("\nTesting ft_calloc()...");

	printf("\n\nTest 1: Integer Array");
	printf("\nSet a fixed array size. The array will be populated with random integers.");
	printf("\n\n>>> Array size: ");
	scanf("%lu", &array_size);

	printf("\nTESTING calloc()...");
	printf("\nAllocating an array using calloc() with %lu members...", array_size);
	array = (int *)calloc(array_size, sizeof(int));
	
	if (!array || array_size <= 0 || errno != 0)
	{
		printf("\ncalloc() returned an arror, allocation was unsuccessful.");
		printf("\nReason: %s, errno: %i", strerror(errno), errno);
		printf("\nNote that errno might be wrong if the array_size is 0.");
		free(array);
	}
	else
	{
		printf("\nAllocation successful. Current array: \n");
		ft_printf_array(array, ", ", array_size);

		printf("\nGenerating random int data...");

		s = array_size - 1;

		while (s-- > 0)
		{
			array[s] = rand();
		}

		printf("\nGenerated random data. Current array: \n");
		ft_printf_array(array, ", ", array_size);

		printf("\nAttempting to free() the calloc() array...");
		free(array);
		printf("\nNo error, which means free() was successful.");
	}

	errno = 0;

	printf("\n\nTESTING ft_calloc()...");
	printf("\nAllocating an array using ft_calloc() with %lu members...", array_size);

	array = (int *)ft_calloc(array_size, sizeof(int));
	
	if (!array || array_size <= 0)
	{
		printf("\nft_calloc() returned an arror, allocation was unsuccessful.");
		printf("\nReason: %s, errno: %i", strerror(errno), errno);
		printf("\nNote that errno might be wrong if the array_size is 0. Aborting test.\n\n");
		free(array);
	}
	else
	{
		printf("\nAllocation successful. Current array: \n");
		ft_printf_array(array, ", ", array_size);

		printf("\nGenerating random int data...");

		s = array_size - 1;

		while (s-- > 0)
		{
			array[s] = rand();
		}
		
		printf("\nGenerated random data. Current array: \n");
		ft_printf_array(array, ", ", array_size);

		printf("\nAttempting to free() the ft_calloc() array...");
		free(array);
		printf("\nNo error, which means free() was successful.\n\n");
	}
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
		else if (strcmp(args[1], "memchr") == 0)
			test_ft_memchr();
		else if (strcmp(args[1], "memcmp") == 0)
			test_ft_memcmp();
		else if (strcmp(args[1], "strnstr") == 0)
			test_ft_strnstr();
		else if (strcmp(args[1], "atoi") == 0)
			test_ft_atoi();
		else if (strcmp(args[1], "strlcpy") == 0)
			test_ft_strlcpy();
		else if (strcmp(args[1], "strlcat") == 0)
			test_ft_strlcat();
		else if (strcmp(args[1], "strdup") == 0)
			test_ft_strdup();
		else if (strcmp(args[1], "calloc") == 0)
			test_ft_calloc();
		else
		{
			printf("\nFunction '%s' doesn't exist!\n\n", args[1]);
		}
	}
	else
	{
		printf("\nPlease provide only one argument!\n\n");
	}
	
	return (0);
}

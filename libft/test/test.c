/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:47:35 by yademirk          #+#    #+#             */
/*   Updated: 2025/06/14 17:01:16 by yademirk         ###   ########.fr       */
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

void	ft_printf_array(void *arr, char *seperator, size_t size, char *print_mode)
{
	int	*tmp_arr;

	tmp_arr = (int *)arr;
	while (size-- > 0)
	{
		printf(print_mode, *(tmp_arr++));

		if (size != 0)
			printf("%s", seperator);
	}
}

void	print_array_char(void *arr, char *seperator, size_t size)
{
	unsigned char	*tmp_arr;

	tmp_arr = (unsigned char *)arr;
	while (size-- > 0)
	{
		printf("%u", *(tmp_arr++));

		if (size != 0)
			printf("%s", seperator);
	}
}

void	strip_newline(char *s, int c)
{	
	*ft_strrchr(s, '\n') = c;
}

void	test_ft_atoi()
{
	char s1[1024];

	ft_putendl_fd("\n\nTesting ft_atoi()...\n", 1);

	// ft_putendl_fd("Test 1: NULL Test\n", 1);

	// ft_putstr_fd("atoi(NULL): (segfault)", 1);
	// ft_putnbr_fd(atoi(NULL), 1); // Doesn't compile with -Wall -Wextra -Werror, gives segfault without those flags
	// ft_putstr_fd("\nft_atoi(NULL): ", 1);
	// ft_putnbr_fd(ft_atoi(NULL), 1); // Gives segfault

	//ft_putendl_fd("\nTest 2: Manual Test\n", 1);
	ft_putendl_fd("\nManual Test\n", 1);

	while (1)
	{
		ft_putstr_fd(">>> Target string: ", 1);
		fgets(s1, 1024, stdin);
		
		if (ft_strncmp(s1, "exit", 4) == 0)
			break;

		strip_newline(s1, 0);

		printf("\nString: %s%%", s1);
		printf("\natoi() result: %i", atoi(s1));
		printf("\nft_atoi() result: %i\n\n", ft_atoi(s1));
	}
}

void	test_ft_bzero(void)
{
	int	arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int	arr2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	//ft_memset(arr1, 1, 10 * sizeof(int));
	//ft_memset(arr2, 2, 10 * sizeof(int));

	printf("\n\n");
	printf("Testing ft_bzero()...");
	printf("\n\n");
	printf("Array 1 before bzero(): ");
	ft_printf_array(arr1, ", ", 10, "%i");
	printf("\n");
	printf("Array 2 before ft_bzero(): ");
	ft_printf_array(arr2, ", ", 10, "%i");

	bzero(arr1, 5 * sizeof(int));
	ft_bzero(arr2, 5 * sizeof(int));

	printf("\n\n");
	printf("Array 1 after bzero(): ");
	ft_printf_array(arr1, ", ", 10, "%i");
	printf("\n");
	printf("Array 2 after ft_bzero(): ");
	ft_printf_array(arr2, ", ", 10, "%i");

	printf("\n\n");
}

void	test_ft_calloc()
{
	unsigned char	*array;
	size_t array_size;
	size_t member_size;
	size_t s;

	printf("\nTesting ft_calloc()...");

	printf("\n\nTest 1: Integer Array");
	printf("\nSet a fixed array size. The array will be populated with random integers.");
	printf("\n\n>>> Array size: ");
	scanf("%lu", &array_size);
	printf("\n>>> Member size: ");
	scanf("%lu", &member_size);

	printf("\nTESTING calloc()...");
	printf("\nAllocating an array using calloc() with %lu members of %lu size...", array_size, member_size);
	array = calloc(array_size, member_size);
	
	if (!array || errno != 0)
	{
		printf("\ncalloc() returned an arror, allocation was unsuccessful.");
		printf("\nReason: %s, errno: %i", strerror(errno), errno);
		printf("\nNote that errno might be wrong if the array_size is 0.");
		free(array);
	}
	else
	{
		printf("\nAllocation successful. Current array: \n");
		print_array_char(array, ", ", array_size);

		printf("\nGenerating random int data...");

		s = array_size;

		while (s-- > 0)
		{
			array[s] = (unsigned char)(rand() % 128);
		}

		printf("\nGenerated random data. Current array: \n");
		print_array_char(array, ", ", array_size);

		printf("\nAttempting to free() the calloc() array...");
		free(array);
		printf("\nNo error, which means free() was successful.");
	}

	errno = 0;

	printf("\n\nTESTING ft_calloc()...");
	printf("\nAllocating an array using ft_calloc() with %lu members of %lu size...", array_size, member_size);

	array = ft_calloc(array_size, member_size);
	
	if (!array)
	{
		printf("\nft_calloc() returned an arror, allocation was unsuccessful.");
		printf("\nReason: %s, errno: %i", strerror(errno), errno);
		printf("\nNote that errno might be wrong if the array_size is 0. Aborting test.\n\n");
		free(array);
	}
	else
	{
		printf("\nAllocation successful. Current array: \n");
		print_array_char(array, ", ", array_size);

		printf("\nGenerating random int data...");

		s = array_size;

		while (s-- > 0)
		{
			array[s] = (unsigned char)(rand() % 128);
		}
		
		printf("\nGenerated random data. Current array: \n");
		print_array_char(array, ", ", array_size);

		printf("\nAttempting to free() the ft_calloc() array...");
		free(array);
		printf("\nNo error, which means free() was successful.\n\n");
	}
}

void	test_ft_isalnum(void)
{
	char *tests;
	int i = 0;

	printf("\nTesting ft_isalnum()...\n\n");

	tests = ft_calloc(128, sizeof(char));
	while (i < 128)
	{
		tests[i] = i;
		i++;
	}	
	
	i = 0;

	while (i < 128)
	{
		printf("Char: '%c' (int: %i), isalnum(): %i, ft_isalnum(): %i\n", tests[i], tests[i], isalnum(tests[i]), ft_isalnum(tests[i]));
		i++;
	}
	
	printf("\n");
	free(tests);
}

void	test_ft_isalpha(void)
{
	char *tests;
	int i = 0;

	printf("\nTesting ft_isalpha()...\n\n");

	tests = ft_calloc(128, sizeof(char));
	while (i < 128)
	{
		tests[i] = i;
		i++;
	}	
	
	i = 0;

	while (i < 128)
	{
		printf("Char: '%c' (int: %i), isalpha(): %i, ft_isalpha(): %i\n", tests[i], tests[i], isalpha(tests[i]), ft_isalpha(tests[i]));
		i++;
	}
	
	printf("\n");
	free(tests);
}

void	test_ft_isascii(void)
{
	unsigned char *tests;
	int i = 0;

	printf("\nTesting ft_isascii()...\n\n");

	tests = ft_calloc(256, sizeof(char));
	while (i < 256)
	{
		tests[i] = i;
		i++;
	}	
	
	i = 0;

	while (i < 256)
	{
		printf("Char: '%c' (int: %i), isascii(): %i, ft_isascii(): %i\n", tests[i], tests[i], __isascii(tests[i]), ft_isascii(tests[i]));
		i++;
	}
	
	printf("\n");
	free(tests);
}

void	test_ft_isdigit(void)
{
	char *tests;
	int i = 0;

	printf("\nTesting ft_isdigit()...\n\n");

	tests = ft_calloc(128, sizeof(char));
	while (i < 128)
	{
		tests[i] = i;
		i++;
	}	
	
	i = 0;

	while (i < 128)
	{
		printf("Char: '%c' (int: %i), isdigit(): %i, ft_isdigit(): %i\n", tests[i], tests[i], isdigit(tests[i]), ft_isdigit(tests[i]));
		i++;
	}
	
	printf("\n");
	free(tests);
}

void	test_ft_isprint(void)
{
	char *tests;
	int i = 0;

	printf("\nTesting ft_isprint()...\n\n");

	tests = ft_calloc(128, sizeof(char));
	while (i < 128)
	{
		tests[i] = i;
		i++;
	}	
	
	i = 0;

	while (i < 128)
	{
		printf("Char: '%c' (int: %i), isprint(): %i, ft_isprint(): %i\n", tests[i], tests[i], isprint(tests[i]), ft_isprint(tests[i]));
		i++;
	}
	
	printf("\n");
	free(tests);
}

void	test_ft_memchr()
{
	int	i = 0x00FF0000;
	int target = 255;

	void	*res1 = memchr(&i, target, 3);
	void	*res2 = ft_memchr(&i, target, 3);

	printf("\nTesting ft_memchr()...\n");
	printf("\n   memchr(): Searched int: %i (address %p), target int: %i, result: %p (col: %lu)\n", i, &i, target, res1, ((char *)res1 - (char *)&i));
	printf("\nft_memchr(): Searched int: %i (address %p), target int: %i, result: %p (col: %lu)\n", i, &i, target, res2, ((char *)res2 - (char *)&i));
}

void	test_ft_memcmp()
{
	int		a;
	int		b;
	size_t	comp_bytes;

	printf("\nTesting memcmp()...\n");

	printf("\nEnter first integer: ");
	scanf("%i", &a);
	printf("Enter second integer: ");
	scanf("%i", &b);

	printf("\nFirst int: %i, Second int: %i\n", a, b);

	printf("\n>>> Enter number of bytes to compare (max %lu): ", sizeof(int));
	scanf("%lu", &comp_bytes);

	printf("\n\n   memcmp(%i, %i) compare bytes: %lu, result: %i", a, b, comp_bytes, memcmp(&a, &b, comp_bytes));
	printf("\n\nft_memcmp(%i, %i) compare bytes: %lu, result: %i\n\n", a, b, comp_bytes, ft_memcmp(&a, &b, comp_bytes));
}

void	test_ft_memcpy(void)
{
	printf("\nTesting ft_memcpy()...\n\n");

	printf("INTEGER TEST\n");
	int int1_org = 0x7FFFFF;
	int int2_org = 0x7000FF;
	int	int1 = int1_org;
	int	int2 = int2_org;
	size_t	i_size = 4;

	printf("\nBefore memcpy(): a: %i (hex: %#010X), b: %i (hex: %#010X)\n", int1, int1, int2, int2);
	memcpy(&int1, &int2, i_size);
	printf("After memcpy(): a: %i (hex: %#010X), b: %i (hex: %#010X)\n", int1, int1, int2, int2);

	int1 = int1_org;
	int2 = int2_org;

	printf("\nBefore ft_memcpy(): a: %i (hex: %#010X), b: %i (hex: %#010X)\n", int1, int1, int2, int2);
	ft_memcpy(&int1, &int2, i_size);
	printf("After ft_memcpy(): a: %i (hex: %#010X), b: %i (hex: %#010X)\n", int1, int1, int2, int2);

	int arr_org[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int arr1[10];
	ft_memcpy(arr1, arr_org, 10 * sizeof(int));
	size_t	a_size = 4 * (sizeof(int));

	printf("\nOVERLAPPING TEST\n");

	printf("\nBefore memcpy():\na: ");
	ft_printf_array(arr1 + 3, ", ", 7, "%i");
	printf("\nb: ");
	ft_printf_array(arr1, ", ", 10, "%i");

	memcpy(arr1 + 3, arr1, a_size);

	printf("\nAfter memcpy():\na: ");
	ft_printf_array(arr1 + 3, ", ", 7, "%i");
	printf("\nb: ");
	ft_printf_array(arr1, ", ", 10, "%i");

	ft_memcpy(arr1, arr_org, 10 * sizeof(int));

	printf("\n\nBefore ft_memcpy():\na: ");
	ft_printf_array(arr1 + 3, ", ", 7, "%i");
	printf("\nb: ");
	ft_printf_array(arr1, ", ", 10, "%i");

	ft_memcpy(arr1 + 3, arr1, a_size);

	printf("\nAfter ft_memcpy():\na: ");
	ft_printf_array(arr1 + 3, ", ", 7, "%i");
	printf("\nb: ");
	ft_printf_array(arr1, ", ", 10, "%i");

	printf("\n\nSTRING TEST\n");

	char str1[] = "ABCDEFGH";
	char str2[] = "abcdefgh";
	size_t s_size = 4;

	printf("Before memcpy(): a: %s, b: %s\n", str1, str2);
	memcpy(str1, str2, s_size);
	printf("After memcpy(): a: %s, b: %s\n\n", str1, str2);

	ft_strlcpy(str1, "ABCDEFGH", 9);

	printf("Before ft_memcpy(): a: %s, b: %s\n", str1, str2);
	ft_memcpy(str1, str2, s_size);
	printf("After ft_memcpy(): a: %s, b: %s\n\n", str1, str2);
}

void	test_ft_memmove(void)
{
	char *ft_func = "ft_memcpy()"; 
	char *func = "memcpy()";

	printf("\nTesting %s...\n\n", ft_func);

	printf("Normal test...\n\n");

	char a[] = "ABCDEFGH";
	char b[] = "abcdefgh";

	printf("Before %s: a: %s, b: %s\n", func, a, b);
	printf("After %s: a: %s, b: %s\n\n", func, (char *)memmove(a, b, sizeof(char) * 5), b);

	ft_memcpy(a, "ABCDEFGH", 9);

	printf("Before %s: a: %s, b: %s\n", ft_func, a, b);
	printf("After %s: a: %s, b: %s\n\n", ft_func, (char *)ft_memmove(a, b, sizeof(char) * 5), b);

	printf("Overlapping test...\n\n");

	ft_memcpy(a, "ABCDEFGH", 9);

	printf("Before %s: a: %s, b: %s\n", func, a + 2, a);
	printf("After %s: a: %s, b: %s\n\n", func, (char *)memmove(a + 2, a, sizeof(char) * 5), a);

	ft_memcpy(a, "ABCDEFGH", 9);

	printf("Before %s: a: %s, b: %s\n", ft_func, a + 2, a);
	printf("After %s: a: %s, b: %s\n\n", ft_func, (char *)ft_memmove(a + 2, a, sizeof(char) * 5), a);
}

void	test_ft_memset(void)
{
	char	s1[1024];
	char	s2[1024];
	int		start;
	int		end;
	char	c;
	char	answer;

	printf("\n\n");
	printf("Testing ft_memset()...");

	answer = 'n';
	while (1)
	{
		printf("\n\n");
		if (answer != 'y')
		{
			ft_bzero(s1, 1024 * sizeof(char));
			ft_bzero(s2, 1024 * sizeof(char));
			printf(">>> Target string: ");
			fgets(s1, 1024, stdin);
			if (ft_strncmp(s1, "exit", 4) == 0)
				break;
			strip_newline(s1, 0);
			printf("\n");
		}

		printf(">>> Start: ");
		scanf("%i", &start);
		printf("\n");

		printf(">>> Length: ");
		scanf("%i", &end);
		printf("\n");

		scanf("%c", &c); // Repeat
		printf(">>> Char: ");
		scanf("%c", &c);
		printf("\n\n");

		ft_strlcpy(s2, s1, ft_strlen(s1) + 1);

		memset(s1 + start, c, end);
		printf("   memset() result: %s\n", s1);

		ft_memset(s2 + start, c, end);
		printf("ft_memset() result: %s", s2);

		scanf("%c", &c);

		printf("\n\n");
		printf("Keep the current string? (y/n): ");
		scanf("%c", &answer);
		getchar();
	}
}

void	test_ft_strchr()
{
	char *s = "ABCDEFGH";
	char c = 'C';

	printf("\nTesting strchr()...\n");

	printf("\nstrchr() string: %s, target: %c, col: %lu, pointer: %p", s, c, strchr(s, c) - s + 1, strchr(s, c));
	printf("\nft_strchr() string: %s, target: %c, col: %lu, pointer: %p\n\n", s, c, ft_strchr(s, c) - s + 1, ft_strchr(s, c));
}

void	test_ft_strdup()
{
	char s1[1024];
	char *s2;

	printf("\nTesting strdup()...\n");

	printf(">>> Target string (max 1024 chars): ");
	fgets(s1, 1024, stdin);
	strip_newline(s1, 0);

	s2 = strdup(s1);

	printf("\nstrdup() target string: %s, target string length: %lu, result string: %s (address: %p), result string length: %lu\n", s1, ft_strlen(s1), s2, s2, ft_strlen(s2));
	printf("Attempting free() for strdup()...\n");
	free(s2);
	printf("No errors, which means free() was successful.\n");

	s2 = ft_strdup(s1);
	printf("\nft_strdup() target string: %s, target string length: %lu, result string: %s (address: %p), result string length: %lu\n", s1, ft_strlen(s1), s2, s2, ft_strlen(s2));
	printf("Attempting free() for ft_strdup()...\n");
	free(s2);
	printf("No errors, which means free() was successful.\n");
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
	strip_newline(s1, 0);

	printf(">>> String 2: ");
	fgets(s2, 1024, stdin);
	strip_newline(s2, 0);

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

void	test_ft_strlcpy()
{
	char s1[21];
	char s2[21] = "test";
	int bytes;
	size_t	res;

	ft_putstr_fd("\nTesting strlcpy()...\n", 1);

	ft_putstr_fd(">>> Target string (max 20 chars): ", 1);
	fgets(s1, 21, stdin);
	strip_newline(s1, 0);

	ft_putstr_fd("\n\n>>> Target string size (null terminator included): ", 1);
	scanf("%i", &bytes);

	ft_putstr_fd("Running strlcpy() on string: ", 1);
	ft_putstr_fd(s2, 1);
	res = strlcpy(s2, s1, bytes);
	printf("\nstrlcpy() target string: %s, bytes: %i, result string: %s, result string length: %lu, returned int: %lu\n", s1, bytes, s2, ft_strlen(s2), res);

	ft_strlcpy(s2, "test", 5);

	ft_putendl_fd("\nRunning ft_strlcpy()...", 1);
	res = ft_strlcpy(s2, s1, bytes);
	printf("ft_strlcpy() target string: %s, bytes: %i, result string: %s, result string length: %lu, returned int: %lu\n\n", s1, bytes, s2, ft_strlen(s2), res);
}

void	test_ft_strlen(void)
{
	char *tests[] = {"test", "test 2", "LOOOOOONG", "short", " ", "", 
		"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.",
		0};

	printf("\nTesting ft_strlen()...\n\n");

	int i = 0;

	while (tests[i])
	{
		printf("'%s', strlen(): %zu, ft_strlen(): %zu\n", tests[i], strlen(tests[i]), ft_strlen(tests[i]));
		i++;
	}
	
	// printf("'NULL', strlen(): %zu, ft_strlen(): %zu\n", strlen(tests[i]), ft_strlen(tests[i]));
	printf("\n");
}

void	test_ft_strncmp()
{
	char s1[1024];
	char s2[1024];
	int		comp_byte;

	printf("\nTesting strnchr()...\n");

	printf(">>> Target string 1: ");
	fgets(s1, 1024, stdin);
	strip_newline(s1, 0);
	
	printf("\n>>> Target string 2: ");
	fgets(s2, 1024, stdin);
	strip_newline(s2, 0);

	printf("\n>>> Compare number: ");
	scanf("%i", &comp_byte);

	printf("\n\nstrncmp() string 1: %s, string 2: %s, compare bytes: %i, result: %i", s1, s2, comp_byte, strncmp(s1, s2, comp_byte));
	printf("\n\nft_strncmp() string 1: %s, string 2: %s, compare bytes: %i, result: %i\n\n", s1, s2, comp_byte, ft_strncmp(s1, s2, comp_byte));
}

void	test_ft_strnstr()
{
	char s1[1024];
	char s2[1024];
	int		comp_byte;

	printf("\nTesting ft_strnstr()...\n");

	printf(">>> Big string: ");
	fgets(s1, 1024, stdin);
	strip_newline(s1, 0);

	printf("\n>>> Little string: ");
	fgets(s2, 1024, stdin);
	strip_newline(s2, 0);

	printf("\n>>> Compare bytes: ");
	scanf("%i", &comp_byte);

	char	*res1 = strnstr(s1, s2, comp_byte);
	char	*res2 = ft_strnstr(s1, s2, comp_byte);

	printf("\n\n   strnstr() big string: %s, little string: %s, compare bytes: %i, result: %s, pointer: %p", s1, s2, comp_byte, res1, res1);

	printf("\n\nft_strnstr() big string: %s, little string: %s, compare bytes: %i, result: %s, pointer: %p\n\n", s1, s2, comp_byte, res2, res2);
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

void	test_ft_tolower()
{
	unsigned char up = 0;
	unsigned char tmp;
	unsigned char tmp2;

	printf("\nTesting tolower()...\n");

	while (up < 255)
	{
		tmp = tolower(up);
		tmp2 = ft_tolower(up);

		printf("\ntolower() before: %c (int: %i), char: %c, int: %i\n", up, (int)up, tmp, (int)tmp);
		printf("ft_tolower() before: %c (int: %i), char: %c, int: %i\n\n", up, (int)up, tmp2, (int)tmp2);

		up++;
	}
}

void	test_ft_toupper()
{
	unsigned char low = 0;
	unsigned char tmp;
	unsigned char tmp2;

	printf("\nTesting toupper()...\n");

	while (low < 255)
	{
		tmp = toupper(low);
		tmp2 = ft_toupper(low);

		printf("\ntolower() before: %c (int: %i), char: %c, int: %i\n", low, (int)low, tmp, (int)tmp);
		printf("ft_tolower() before: %c (int: %i), char: %c, int: %i\n\n", low, (int)low, tmp2, (int)tmp2);

		low++;
	}
}

#include <fcntl.h>

void	test_ft_putchar_fd()
{
	char	buffer[1024];
	int		fd;
	char	c;

	ft_putstr_fd("\nTesting ft_putchar_fd()...\n\n", 1);

	ft_putstr_fd(">>> Enter file path to write: ", 1);
	scanf("%s", buffer);
	fd = open(buffer, O_WRONLY | O_APPEND);

	if (fd == -1)
	{
		ft_putstr_fd("\n\nNo file exists. Aborted.\n", 1);
		return;
	}
	ft_putstr_fd("\nFile descriptor: ", 1);
	ft_putchar_fd(fd + 48, 1);
	ft_putstr_fd("\nEnter a char to write to the file, or type 'exit' to leave.", 1);
	
	while (getchar() != '\n');
	while (1)
	{
		ft_putstr_fd("\n>>> Char: ", 1);
		fgets(buffer, 1024, stdin);

		if (ft_strncmp(buffer, "exit", 4) == 0)
			break;
		c = buffer[0];

		ft_putstr_fd("Writing '", 1);
		ft_putchar_fd(c, 1);
		ft_putstr_fd("' to the file", 1);
		ft_putchar_fd(c, fd);
	}

	close(fd);
}

void	test_ft_putstr_fd()
{
	char	buffer[1024];
	int		fd;

	ft_putstr_fd("\nTesting ft_putstr_fd()...\n\n", 1);

	ft_putstr_fd(">>> Enter file path to write: ", 1);
	scanf("%s", buffer);
	fd = open(buffer, O_WRONLY | O_APPEND);

	if (fd == -1)
	{
		ft_putstr_fd("\n\nNo file exists. Aborted.\n", 1);
		return;
	}
	ft_putstr_fd("\nFile descriptor: ", 1);
	ft_putchar_fd(fd + 48, 1);
	ft_putstr_fd("\nEnter a string to write to the file, or type '/exit' to leave.", 1);
	
	while (getchar() != '\n');
	while (1)
	{
		ft_putstr_fd("\n>>> Line: ", 1);
		fgets(buffer, 1024, stdin);

		if (ft_strncmp(buffer, "/exit", 5) == 0)
			break;

		// ft_putstr_fd("Writing '", 1);
		// ft_putchar_fd(c, 1);
		// ft_putstr_fd("' to the file", 1);
		ft_putstr_fd(buffer, fd);
	}

	close(fd);
}

void	test_ft_putendl_fd()
{
	ft_putendl_fd("Testing ft_putendl_fd()...", 1);

	ft_putendl_fd("lalaallala", 1);
	ft_putendl_fd("lkololoplol", 1);
	ft_putendl_fd("heheheheh", 1);
	ft_putendl_fd("	", 1);
	ft_putendl_fd("", 1);
	ft_putendl_fd(NULL, 1);

}

void	test_ft_putnbr_fd()
{
	char	buffer[1024];
	int		fd;
	int		nbr;

	ft_putstr_fd("\nTesting ft_putnbr_fd()...\n\n", 1);

	ft_putstr_fd(">>> Enter file path to write: ", 1);
	scanf("%s", buffer);
	fd = open(buffer, O_WRONLY | O_APPEND);

	if (fd == -1)
	{
		ft_putstr_fd("\n\nNo file exists. Aborted.\n", 1);
		return;
	}
	ft_putstr_fd("\nFile descriptor: ", 1);
	ft_putchar_fd(fd + 48, 1);
	ft_putstr_fd("\nEnter a number to write to the file", 1);
	
	while (getchar() != '\n');
	while (1)
	{
		ft_putstr_fd("\n>>> Number: ", 1);
		scanf("%i", &nbr);

		// ft_putstr_fd("Writing '", 1);
		// ft_putchar_fd(c, 1);
		// ft_putstr_fd("' to the file", 1);
		ft_putnbr_fd(nbr, fd);
		ft_putchar_fd('\n', fd);
	}

	close(fd);
}

void	test_ft_itoa()
{
	int		num;
	char	*str;
	ft_putstr_fd("\nTesting ft_itoa()...\n", 1);

	ft_putstr_fd(">>> Number: ", 1);
	scanf("%i", &num);

	ft_putstr_fd("\nTrying number: ", 1);
	ft_putnbr_fd(num, 1);

	str = ft_itoa(num);

	if (str == NULL)
	{
		ft_putstr_fd("\nMemory allocation failed.\n", 1);
		return;
	}

	ft_putstr_fd("\nNumber: ", 1);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	
	free(str);
}

void	test_ft_substr()
{
	char			buffer[1024];
	unsigned int	start;
	size_t 			len;
	char			*str;

	ft_putstr_fd("\nTesting ft_substr()...\n", 1);

	ft_putstr_fd(">>> String: ", 1);
	fgets(buffer, 1024, stdin);
	strip_newline(buffer, 0);

	ft_putstr_fd("\n>>> Start: ", 1);
	scanf("%u", &start);
	ft_putstr_fd("\n>>> Length: ", 1);
	scanf("%lu", &len);

	str = ft_substr(buffer, start, len);

	if (str == NULL)
	{
		ft_putstr_fd("\nMemory allocation failed.\n", 1);
		return;
	}

	ft_putstr_fd("\nSubstring: ", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\nStrlen: ", 1);
	ft_putnbr_fd(ft_strlen(str), 1);
	ft_putchar_fd('\n', 1);
	
	free(str);
}

void	test_ft_strjoin()
{
	char			buffer1[1024];
	char			buffer2[1024];
	char			*str;

	ft_putstr_fd("\nTesting ft_strjoin()...\n", 1);

	ft_putstr_fd(">>> String 1: ", 1);
	fgets(buffer1, 1024, stdin);
	strip_newline(buffer1, 0);

	ft_putstr_fd("\n>>> String 2: ", 1);
	fgets(buffer2, 1024, stdin);
	strip_newline(buffer2, 0);

	str = ft_strjoin(buffer1, buffer2);

	if (str == NULL)
	{
		ft_putstr_fd("\nMemory allocation failed.\n", 1);
		return;
	}

	ft_putstr_fd("\nResult: ", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\nStrlen: ", 1);
	ft_putnbr_fd(ft_strlen(str), 1);
	ft_putchar_fd('\n', 1);
	
	free(str);
}

void	test_ft_strtrim()
{
	char			buffer1[1024];
	char			buffer2[1024];
	char			*str;

	ft_putstr_fd("\nTesting ft_strtrim()...\n", 1);

	ft_putstr_fd(">>> String: ", 1);
	fgets(buffer1, 1024, stdin);
	strip_newline(buffer1, 0);

	ft_putstr_fd("\n>>> Charset: ", 1);
	fgets(buffer2, 1024, stdin);
	strip_newline(buffer2, 0);

	str = ft_strtrim(buffer1, buffer2);

	if (str == NULL)
	{
		ft_putstr_fd("\nMemory allocation failed.\n", 1);
		return;
	}

	ft_putstr_fd("\nResult: '", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("'\nStrlen: ", 1);
	ft_putnbr_fd(ft_strlen(str), 1);
	ft_putchar_fd('\n', 1);
	
	free(str);
}

void	test_ft_split()
{
	char	buffer1[1024];
	char	c;
	char	**str_arr;

	ft_putstr_fd("\nTesting ft_split()...\n", 1);

	ft_putstr_fd(">>> String: ", 1);
	fgets(buffer1, 1024, stdin);
	strip_newline(buffer1, 0);

	ft_putstr_fd("\n>>> Delimiter: ", 1);
	c = fgetc(stdin);

	str_arr = ft_split(buffer1, c);

	if (str_arr == NULL)
	{
		ft_putstr_fd("\nMemory allocation failed.\n", 1);
		return;
	}

	ft_putstr_fd("\nDelimiter int value: ", 1);
	ft_putnbr_fd((int)c, 1);
	ft_putstr_fd("\nResult: \n", 1);
	size_t i = 0;
	while (str_arr[i])
	{
		ft_putstr_fd("Index: ", 1);
		ft_putnbr_fd((int)i, 1);
		ft_putstr_fd(", ", 1);
		ft_putchar_fd('\'', 1);
		ft_putstr_fd(str_arr[i], 1);
		ft_putchar_fd('\'', 1);
		if (str_arr[i + 1] != NULL)
			ft_putstr_fd("\n", 1);
		free(str_arr[i]);
		i++;
	}
	ft_putchar_fd('\n', 1);
	
	free(str_arr[i]);
	free(str_arr);
}

static	char	ft_toupper_wrapper(unsigned int i, char c)
{
	(void)i;
	return (char)ft_toupper((char)c);
}

static	char	ft_tolower_wrapper(unsigned int i, char c)
{
	(void)i;
	return (char)ft_tolower((char)c);
}

void	test_ft_strmapi()
{
	char	buffer[1024];
	char	*str;
	ft_putstr_fd("Testing ft_strmapi()...\n", 1);
	
	ft_putstr_fd("\nTest 1: ft_toupper()", 1);
	ft_putstr_fd("\n>>> Enter a string: ", 1);
	fgets(buffer, 1024, stdin);
	strip_newline(buffer, 0);

	str = ft_strmapi(buffer, &ft_toupper_wrapper);
	ft_putstr_fd("\nResult: '", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("'\n", 1);
	free(str);

	ft_putstr_fd("\nTest 2: ft_tolower()", 1);
	ft_putstr_fd("\n>>> Enter a string: ", 1);
	fgets(buffer, 1024, stdin);
	strip_newline(buffer, 0);

	str = ft_strmapi(buffer, &ft_tolower_wrapper);
	ft_putstr_fd("\nResult: '", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("'\n", 1);
	free(str);

	ft_putchar_fd('\n', 1);
}

static void	ft_rot(unsigned int i, char *c)
{
	(void)i;
	*c += 1;
}

void	test_ft_striteri()
{
	char	buffer[1024];
	ft_putstr_fd("Testing ft_striteri()...\n", 1);
	
	ft_putstr_fd("\nTest 1: ft_rot()", 1);
	ft_putstr_fd("\n>>> Enter a string: ", 1);
	fgets(buffer, 1024, stdin);
	strip_newline(buffer, 0);

	ft_striteri(buffer, &ft_rot);
	ft_putstr_fd("\nResult: '", 1);
	ft_putstr_fd(buffer, 1);
	ft_putstr_fd("'\n", 1);

	ft_putchar_fd('\n', 1);
}

static void num_square(void *num)
{
	int *n;

	n = (int *)num;
	*n *= *n;
}

static void *num_cube(void *num)
{
	int n;
	int	*res;

	n = *(int *)num;
	n = n * n * n;
	res = malloc(sizeof(int));
	*res = n;
	return (res);
}

void	test_ft_bonus()
{
	t_list *lst;
	t_list *tmp;
	t_list *tmp2;
	int	content;
	int	content2;

	ft_putendl_fd("Testing bonus functions...", 1);

	ft_putendl_fd("\n1 - ft_lstnew()\n", 1);

	ft_putendl_fd("Creating list item...", 1);
	content = 5;
	tmp = ft_lstnew(&content);
	ft_putstr_fd("Created new item with int content: ", 1);
	ft_putnbr_fd(*(int *)tmp->content, 1);
	ft_putendl_fd("", 1);

	ft_putendl_fd("\n2 - ft_lstadd_front()\n", 1);

	ft_putendl_fd("Creating another list item. The new is null so this should create a new list with one item.", 1);
	content2 = 10;
	lst = ft_lstnew(&content2);
	ft_putstr_fd("Created new item with int content: ", 1);
	ft_putnbr_fd(*(int *)lst->content, 1);
	ft_putendl_fd("", 1);
	ft_putendl_fd("Now, setting the previous item as the first item... ", 1);
	ft_lstadd_front(&lst, tmp);
	ft_putstr_fd("Done. Content of the first item is now: ", 1);
	ft_putnbr_fd(*(int *)lst->content, 1);
	ft_putendl_fd("", 1);

	ft_putendl_fd("\n3 - ft_lstsize()\n", 1);
	ft_putendl_fd("Adding 3 new items to the list...", 1);
	ft_lstadd_front(&lst, ft_lstnew(&(int){42}));
	ft_lstadd_front(&lst, ft_lstnew(&(int){42}));
	ft_lstadd_front(&lst, ft_lstnew(&(int){42}));
	ft_putstr_fd("Done. Now, the size of the list is: ", 1);
	ft_putnbr_fd(ft_lstsize(lst), 1);
	ft_putstr_fd("\nTrying null list size: ", 1);
	ft_putnbr_fd(ft_lstsize(NULL), 1);
	ft_putendl_fd("", 1);

	ft_putendl_fd("\n4 - ft_lstlast()\n", 1);
	ft_putstr_fd("Last item on the list's content: ", 1);
	ft_putnbr_fd(*(int *)(ft_lstlast(lst)->content), 1);
	ft_putendl_fd("", 1);

	ft_putendl_fd("\n5 - ft_lstadd_back()\n", 1);
	ft_putstr_fd("Last item on the list's content: ", 1);
	ft_putnbr_fd(*(int *)(ft_lstlast(lst)->content), 1);
	ft_putstr_fd("\nAdding a new item with content: ", 1);
	ft_putnbr_fd(100, 1);
	ft_lstadd_back(&lst, ft_lstnew(&(int){100}));
	ft_putstr_fd("\nDone. Last item is now: ", 1);
	ft_putnbr_fd(*(int *)(ft_lstlast(lst)->content), 1);
	ft_putendl_fd("", 1);

	ft_putendl_fd("\n6 - ft_lstdelone()\n", 1);
	ft_putstr_fd("Attemtping ft_lstdelone on the first item with the content: ", 1);
	*(int *)lst->content = 999;
	ft_putnbr_fd(*(int *)lst->content, 1);
	tmp = lst->next;
	ft_lstdelone(lst, NULL);
	lst = tmp;
	ft_putstr_fd("\nDone. First item's content now: ", 1);
	ft_putnbr_fd(*(int *)lst->content, 1);
	ft_putstr_fd("\nList size now: ", 1);
	ft_putnbr_fd(ft_lstsize(lst), 1);
	ft_putendl_fd("", 1);

	ft_putendl_fd("\n7 - ft_lstiter()\n", 1);
	ft_putstr_fd("The list content is: \n", 1);
	tmp = lst;
	while (tmp)
	{
		ft_putnbr_fd(*(int *)tmp->content, 1);
		if (tmp->next)
			ft_putstr_fd(", ", 1);
		tmp = tmp->next;
	}
	ft_putstr_fd("\nNow, running ft_lstiter()...\n", 1);
	ft_lstiter(lst, &num_square);
	ft_putstr_fd("Done. The list content is now: \n", 1);
	tmp = lst;
	while (tmp)
	{
		ft_putnbr_fd(*(int *)tmp->content, 1);
		if (tmp->next)
			ft_putstr_fd(", ", 1);
		tmp = tmp->next;
	}
	ft_putendl_fd("", 1);

	ft_putendl_fd("\n8 - ft_lstmap()\n", 1);
	ft_putstr_fd("Our aim is to create a new list without modifying the original one. The original list content is: \n", 1);
	tmp = lst;
	while (tmp)
	{
		ft_putnbr_fd(*(int *)tmp->content, 1);
		if (tmp->next)
			ft_putstr_fd(", ", 1);
		tmp = tmp->next;
	}
	ft_putstr_fd("\nNow, running ft_lstmap() with num_cube()...\n", 1);
	tmp = ft_lstmap(lst, &num_cube, &free);
	if (tmp)
		ft_putstr_fd("Done. The new list content is now: \n", 1);
	else
	{
		ft_putstr_fd("TMP is null.\n", 1);
	}
	tmp2 = tmp;
	while (tmp2)
	{
		ft_putnbr_fd(*(int *)tmp2->content, 1);
		if (tmp2->next)
			ft_putstr_fd(", ", 1);
		tmp2 = tmp2->next;
	}
	ft_putstr_fd("\nAnd the original list content is now: \n", 1);
	tmp2 = lst;
	while (tmp2)
	{
		ft_putnbr_fd(*(int *)tmp2->content, 1);
		if (tmp2->next)
			ft_putstr_fd(", ", 1);
		tmp2 = tmp2->next;
	}
	ft_putendl_fd("", 1);
	
	ft_putendl_fd("\n9 - ft_lstclear()\n", 1);
	ft_putstr_fd("We have two lists now. Attemtping ft_lstclear() on both of them...\n", 1);
	ft_lstclear(&lst, NULL);
	ft_lstclear(&tmp, &free);
	ft_putstr_fd("Original list size now: ", 1);
	ft_putnbr_fd(ft_lstsize(lst), 1);
	ft_putstr_fd("\nIs the original list now NULL: ", 1);
	ft_putnbr_fd(lst == NULL, 1);
	ft_putstr_fd("Second list size now: ", 1);
	ft_putnbr_fd(ft_lstsize(tmp), 1);
	ft_putstr_fd("\nIs the second list now NULL: ", 1);
	ft_putnbr_fd(tmp == NULL, 1);

	ft_putstr_fd("\n\nBonus testing is done. Use valgrind to check for memory leaks.", 1);
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
		else if (strcmp(args[1], "putchr") == 0)
			test_ft_putchar_fd();
		else if (strcmp(args[1], "putstr") == 0)
			test_ft_putstr_fd();
		else if (strcmp(args[1], "putnbr") == 0)
			test_ft_putnbr_fd();
		else if (strcmp(args[1], "itoa") == 0)
			test_ft_itoa();
		else if (strcmp(args[1], "substr") == 0)
			test_ft_substr();
		else if (strcmp(args[1], "strjoin") == 0)
			test_ft_strjoin();
		else if (strcmp(args[1], "strtrim") == 0)
			test_ft_strtrim();
		else if (strcmp(args[1], "split") == 0)
			test_ft_split();
		else if (strcmp(args[1], "strmapi") == 0)
			test_ft_strmapi();
		else if (strcmp(args[1], "striteri") == 0)
			test_ft_striteri();
		else if (strcmp(args[1], "putendl") == 0)
			test_ft_putendl_fd();
		else if (strcmp(args[1], "bonus") == 0)
			test_ft_bonus();
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

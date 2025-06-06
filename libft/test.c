/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:47:35 by yademirk          #+#    #+#             */
/*   Updated: 2025/06/02 13:23:47 by yademirk         ###   ########.fr       */
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

void	strip_newline(char *s, int c)
{	
	*ft_strrchr(s, '\n') = c;
}

void	test_ft_atoi()
{
	char s1[1024];

	printf("\n\nTesting ft_atoi()...\n\n");

	while (1)
	{
		printf(">>> Target string: ");
		fgets(s1, 1024, stdin);
		
		if (ft_strncmp(s1, "exit", 4) == 0)
			break;

		strip_newline(s1, 0);

		printf("\nString: %s%%", s1);
		printf("\natoi() result: %i",atoi(s1));
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
	int	*array;
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
		ft_printf_array(array, ", ", array_size, "%i");

		printf("\nGenerating random int data...");

		s = array_size;

		while (s-- > 0)
		{
			array[s] = rand() % 128;
		}

		printf("\nGenerated random data. Current array: \n");
		ft_printf_array(array, ", ", array_size, "%c");

		printf("\nAttempting to free() the calloc() array...");
		free(array);
		printf("\nNo error, which means free() was successful.");
	}

	errno = 0;

	printf("\n\nTESTING ft_calloc()...");
	printf("\nAllocating an array using ft_calloc() with %lu members of %lu size...", array_size, member_size);

	array = ft_calloc(array_size, member_size);
	
	if (!array || errno != 0)
	{
		printf("\nft_calloc() returned an arror, allocation was unsuccessful.");
		printf("\nReason: %s, errno: %i", strerror(errno), errno);
		printf("\nNote that errno might be wrong if the array_size is 0. Aborting test.\n\n");
		free(array);
	}
	else
	{
		printf("\nAllocation successful. Current array: \n");
		ft_printf_array(array, ", ", array_size, "%i");

		printf("\nGenerating random int data...");

		s = array_size;

		while (s-- > 0)
		{
			array[s] = rand() % 128;
		}
		
		printf("\nGenerated random data. Current array: \n");
		ft_printf_array(array, ", ", array_size, "%c");

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
	char s[1024];
	char s2[1024];
	char c;
	int bytes;
	void	*result;
	void	*ft_result;

	printf("\nTesting memchr()...\n");

	printf(">>> Target string: ");
	fgets(s, 1024, stdin);
	strip_newline(s, 0);
	
	printf("\n>>> Target char: ");
	fgets(s2, 1024, stdin);
	if (ft_strncmp(s2, "null", 4) == 0)
		c = 0;
	else
		c = s2[0];
	printf("\n>>> Target compare bytes: ");
	scanf("%i", &bytes);

	result = memchr(s, c, bytes);
	ft_result = ft_memchr(s, c, bytes);

	printf("\n\nmemchr() string: %s, target: %c, bytes: %i, col: %lu, pointer: %p", s, c, bytes,  result - (void *)s + 1, result);
	printf("\nft_memchr() string: %s, target: %c, bytes: %i, col: %lu, pointer: %p\n\n", s, c, bytes, ft_result - (void *)s + 1, ft_result);
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

	printf("\n\nmemcmp() compare bytes: %lu, result: %i", comp_bytes, memcmp(&a, &b, comp_bytes));
	printf("\n\nft_memcmp() compare bytes: %lu, result: %i\n\n", comp_bytes, ft_memcmp(&a, &b, comp_bytes));
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
		ft_memset(s1 + start, c, end * sizeof(char));
		ft_memset(s2 + start, c, end * sizeof(char));

		scanf("%c", &c);

		printf("memset() result: %s", s1);
		printf("\n");
		printf("ft_memset() result: %s", s1);

		printf("\n\n");
		printf("Keep the current string? (y/n): ");
		scanf("%c", &answer);
		getchar();
	}
}

void	test_ft_strchr()
{
	char *s = "ABCDEFGH";
	char c = 'A';

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

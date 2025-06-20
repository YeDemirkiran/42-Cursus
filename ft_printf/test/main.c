#include "main.h"


int	main(void)
{
	int	res;
	res = printf("%-20.15u", -21);
	printf(" (returned: %i)\n", res);
	res = ft_printf("%-20.15u", -21);
	printf(" (returned: %i)\n", res);

	return (0);
}


// int	main(void)
// {
// 	int	res;
// 	printf("ft_printf() Test Programı (by yademirk)");

// 	printf("\n\nADIM 1: printf() işlevleri\n\n");

// 	printf("Adım 1.1: Gerekli printf() işlevleri\n");
// 	res = printf("%%c: %c ", 'a');
// 	printf("(returned: %i)\n", res);
// 	res = printf("%%s: %s ", "Test");
// 	printf("(returned: %i)\n", res);
// 	res = printf("%%p: %p ", "Test");
// 	printf("(returned: %i)\n", res);
// 	res = printf("%%d: %d ", 100);
// 	printf("(returned: %i)\n", res);
// 	res = printf("%%d: %d ", -100);
// 	printf("(returned: %i)\n", res);
// 	res = printf("%%i: %i ", 100);
// 	printf("(returned: %i)\n", res);
// 	res = printf("%%i: %i ", -100);
// 	printf("(returned: %i)\n", res);
// 	res = printf("%%u: %u ", -1);
// 	printf("(returned: %i)\n", res);
// 	res = printf("%%x: %x ", 0xa1b2c3d4);
// 	printf("(returned: %i)\n", res);
// 	res = printf("%%X: %X ", 0xa1b2c3d4);
// 	printf("(returned: %i)\n", res);
// 	res = printf("%%%%: %% ");
// 	printf("(returned: %i)\n", res);

// 	printf("\nAdım 1.2: Bonus işlevler\n");

// 	printf("\n1.2.1) Field Width öncesi flag'ler\n");

// 	printf("\n1.2.1.1) '#' flag'i:\n");
// 	res = printf(" %%#x: %#x ", 0xa1b2c3d4);
// 	printf("(returned: %i)\n", res);
// 	res = printf(" %%#X: %#X ", 0xa1b2c3d4);
// 	printf("(returned: %i)\n", res);
// 	// printf(" %%#x: %#12x\n", 0xa1b2c3d4);
// 	// printf(" %%#X: %#12X\n", 0xa1b2c3d4);

// 	printf("\n1.2.1.2) '0' flag'i:\n");
// 	res = printf(" %%0x: %010x ", 0xa1b2c3d4);
// 	printf("(returned: %i)\n", res);
// 	res = printf(" %%0X: %010X ", 0xa1b2c3d4);
// 	printf("(returned: %i)\n", res);
// 	res = printf(" %%0#x: %0#10x ", 0xffffffff);
// 	printf("(returned: %i)\n", res);
// 	res = printf(" %%0#X: %0#12X ", 0xa1b2c3d4);
// 	printf("(returned: %i)\n", res);
// 	res = printf(" %%#0x: %#012x ", 0xa1b2c3d4);
// 	printf("(returned: %i)\n", res);
// 	res = printf(" %%#0X: %#012X ", 0xa1b2c3d4);
// 	printf("(returned: %i)\n", res);

// 	printf("\n1.2.1.3) '-' flag'i:\n");
// 	printf(" %%-x: %-10xtest\n", 0xa1b2c3d4);
// 	printf(" %%-X: %-10Xtest\n", 0xa1b2c3d4);
// 	printf(" %%-#x: %-#12xtest\n", 0xa1b2c3d4);
// 	printf(" %%-#X: %-#12Xtest\n", 0xa1b2c3d4);
// 	printf(" %%#-x: %#-12xtest\n", 0xa1b2c3d4);
// 	printf(" %%#-X: %#-12Xtest\n", 0xa1b2c3d4);

// 	printf(" %%#-X: %.10s\n", "aabbccddffeegghh");

// 	printf("\n\nADIM 2: ft_printf() Testi ve Karşılaştırmaları\n\n");

// 	printf("Adım 2.1: Gerekli ft_printf() İşlevleri\n\n");

// 	res = printf("   printf(): Sade bir yazı ");
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(): Sade bir yazı ");
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%): %% ");
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%): %% ");
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%c): %c ", 'c');
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%c): %c ", 'c');
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%s): %s ", "hello");
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%s): %s ", "hello");
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%p): %p ", "hello");
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%p): %p ", "hello");
// 	printf("(returned: %i)\n\n", res);
// 	// printf("printf(%%p): %p\n", NULL);
// 	// ft_printf("ft_printf(%%p): %p\n\n", NULL);

// 	res = printf("   printf(%%d): %d ", 1234567890);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%d): %d ", 1234567890);
// 	printf("(returned: %i)\n", res);
// 	res = printf("   printf(%%d): %d ", -1234567890);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%d): %d ", -1234567890);
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%i): %i ", 1234567890);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%i): %i ", 1234567890);
// 	printf("(returned: %i)\n", res);
// 	res = printf("   printf(%%i): %i ", -1234567890);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%i): %i ", -1234567890);
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%u): %u ", -1);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%u): %u ", -1);
// 	printf("(returned: %i)\n\n", res);
	
// 	res = printf("   printf(%%x): %x ", 0x1A2B3C4D);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%x): %x ", 0x1A2B3C4D);
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%X): %X ", 0x1A2B3C4D);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%X): %X ", 0x1A2B3C4D);
// 	printf("(returned: %i)\n\n", res);

// 	printf("Adım 2.2: Bonus İşlevler ve Karşılaştırmalar\n\n");

// 	printf("\n2.2.1) Field Width öncesi flag'ler\n");

// 	printf("\n2.2.1.1) '#' flag'i:\n");
// 	res = printf("   printf(%%#x): %#x ", 0xa1b2c3d4);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%#x): %#x ", 0xa1b2c3d4);
// 	ft_printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%#X) %#X ", 0xa1b2c3d4);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%#X) %#X ", 0xa1b2c3d4);
// 	ft_printf("(returned: %i)\n\n", res);

// 	printf("\n2.2.1.2) '0' flag'i:\n");
// 	res = printf("   printf(%%010x): %010x ", 0xa1b2c3d4);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%010x): %010x ", 0xa1b2c3d4);
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%010X) %010X ", 0xa1b2c3d4);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%010X) %010X ", 0xa1b2c3d4);
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%0#10x): %0#10x ", 0xffffffff);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%0#10x): %0#10x ", 0xffffffff);
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%0#12X): %0#12X ", 0xa1b2c3d4);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%0#12X): %0#12X ", 0xa1b2c3d4);
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%#012x): %#012x ", 0xa1b2c3d4);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%#012x): %#012x ", 0xa1b2c3d4);
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%#012X): %#012X ", 0xa1b2c3d4);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%#012X): %#012X ", 0xa1b2c3d4);
// 	printf("(returned: %i)\n\n", res);

// 	printf("\n2.2.1.3) '-' flag'i:\n");
// 	res = printf("   printf(%%-10x): %-10x", 0xa1b2c3d4);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%-10x): %-10x", 0xa1b2c3d4);
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%-10X): %-10X", 0xa1b2c3d4);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%-10X): %-10X", 0xa1b2c3d4);
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%-12x): %-12s", "\"Test\"");
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%-12s): %-12s", "\"Test\"");
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%-20i): %-20i", 987654321);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%-20i): %-20i", 987654321);
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%#-12x): %#-12x", 0xa1b2c3d4);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%#-12x): %#-12x", 0xa1b2c3d4);
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%#-12X): %#-12X", 0xa1b2c3d4);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%#-12X): %#-12X", 0xa1b2c3d4);
// 	printf("(returned: %i)\n\n", res);

// 	printf("\n2.2.2) Flag Kombinasyonları\n");
	
// 	res = printf("   printf(%%-10x): %-10x", 0xa1b2c3d4);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%-10x): %-10x", 0xa1b2c3d4);
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%-10X): %-10X", 0xa1b2c3d4);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%-10X): %-10X", 0xa1b2c3d4);
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%-12x): %-12s", "\"Test\"");
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%-12s): %-12s", "\"Test\"");
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%-20i): %-20i", 987654321);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%-20i): %-20i", 987654321);
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%#-12x): %#-12x", 0xa1b2c3d4);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%#-12x): %#-12x", 0xa1b2c3d4);
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%#-12X): %#-12X", 0xa1b2c3d4);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%#-12X): %#-12X", 0xa1b2c3d4);
// 	printf("(returned: %i)\n\n", res);


// 	printf("Adım 2.3: Hata Testleri ve Sakat Durumlar\n\n");
// 	printf("Adım 2.3.1: NULL testi\n\n");

// 	printf("   printf(NULL): ");
// 	res = printf(NULL);
// 	printf("(returned: %i)\n", res);
// 	printf("ft_printf(NULL): ");
// 	res = ft_printf(NULL);
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%c): %c", NULL);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%c): %c", NULL);
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%s): %s", NULL);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%s): %s", NULL);
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%p): %p", NULL);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%p): %p", NULL);
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%d): %d", NULL);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%d): %d", NULL);
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%i): %i", NULL);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%i): %i", NULL);
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%u): %u", NULL);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%u): %u", NULL);
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%x): %x", NULL);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%x): %x", NULL);
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%X): %X", NULL);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%X): %X", NULL);
// 	printf("(returned: %i)\n\n", res);

// 	res = printf("   printf(%%05.10i): %05.10i", 10);
// 	printf("(returned: %i)\n", res);
// 	res = ft_printf("ft_printf(%%05.10i): %05.10i", 10);
// 	printf("(returned: %i)\n\n", res);
	
// 	return (0);
// }

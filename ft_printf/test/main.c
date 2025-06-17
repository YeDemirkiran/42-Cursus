#include "main.h"

int	main(void)
{
	printf("ft_printf() Test Programı (by yademirk)");

	printf("\n\nADIM 1: printf() işlevleri\n\n");

	printf("Adım 1.1: Gerekli printf() işlevleri\n");
	printf("%%c: %c\n", 'a');
	printf("%%s: %s\n", "Test");
	printf("%%p: %p\n", (void *)"Test");
	printf("%%d: %d\n", 100);
	printf("%%i: %i\n", (int)0x80000000);
	printf("%%u: %u\n", 0xFFFFFFFF);
	printf("%%x: %x\n", 0xAAbbCCdd);
	printf("%%X: %X\n", 0xa1b2c3d4);
	printf("%%%%: %%\n");
	printf("heheehe%d%c%s %+010\n", 10, 'c', "a", 10);

	printf("\nAdım 1.2: Bonus işlevler\n");

	printf("\n1.2.1) Field Width öncesi flag'ler\n");

	printf("\n1.2.1.1) '#' flag'i:\n");
	//printf("%%#o: %#o %#o %#o\n", 0, 100, -100);
	printf(" %%#x: %#x\n", 0xa1b2c3d4);
	printf(" %%#X: %#X\n", 0xa1b2c3d4);

	printf("\n1.2.1.2) '0' flag'i:\n");
	printf(" %%0x: %010x\n", 0xa1b2c3d4);
	printf(" %%0X: %010X\n", 0xa1b2c3d4);
	printf(" %%0#x: %0#12x\n", 0xa1b2c3d4);
	printf(" %%0#X: %0#12X\n", 0xa1b2c3d4);
	printf(" %%#0x: %#012x\n", 0xa1b2c3d4);
	printf(" %%#0X: %#012X\n", 0xa1b2c3d4);

	printf("\n1.2.1.3) '-' flag'i:\n");
	printf(" %%-x: %-10xtest\n", 0xa1b2c3d4);
	printf(" %%-X: %-10Xtest\n", 0xa1b2c3d4);
	printf(" %%-#x: %-#12xtest\n", 0xa1b2c3d4);
	printf(" %%-#X: %-#12Xtest\n", 0xa1b2c3d4);
	printf(" %%#-x: %#-12xtest\n", 0xa1b2c3d4);
	printf(" %%#-X: %#-12Xtest\n", 0xa1b2c3d4);

	printf("\n\nADIM 2: ft_printf() testi\n\n");
	
	return (0);
}

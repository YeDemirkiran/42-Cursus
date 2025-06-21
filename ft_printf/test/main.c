#include "main.h"


int	main(void)
{
	int	res;

	res = printf("");
	printf(" (res: %i)\n", res);
	res = ft_printf("");
	printf(" (res: %i)\n", res);

	res = printf(NULL);
	printf(" (res: %i)\n", res);
	res = ft_printf(NULL);
	printf(" (res: %i)\n", res);

	res = printf("Test 11241242141");
	printf(" (res: %i)\n", res);
	res = ft_printf("Test 11241242141");
	printf(" (res: %i)\n", res);

	res = printf("Test \0 11241242141");
	printf(" (res: %i)\n", res);
	res = ft_printf("Test \0 11241242141");
	printf(" (res: %i)\n", res);

	res = printf("Test a%ca", NULL);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%ca", NULL);
	printf(" (res: %i)\n", res);

	res = printf("Test a%ca", 0);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%ca", 0);
	printf(" (res: %i)\n", res);

	res = printf("Test a%ca", 1);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%ca", 1);
	printf(" (res: %i)\n", res);

	res = printf("Test a%ca", '%');
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%ca", '%');
	printf(" (res: %i)\n", res);

	// res = printf("Test a%sa");
	// printf(" (res: %i)\n", res);
	// res = ft_printf("Test a%sa");
	// printf(" (res: %i)\n", res);

	res = printf("Test a%sa", NULL);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%sa", NULL);
	printf(" (res: %i)\n", res);

	res = printf("Test a%sa", "");
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%sa", "");
	printf(" (res: %i)\n", res);

	res = printf("Test a%sa", "föwmwplgwe%sdlödsd\0saddsad");
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%sa", "föwmwplgwe%sdlödsd\0sddsa");
	printf(" (res: %i)\n", res);

	res = printf("Test a%pa", NULL);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%pa", NULL);
	printf(" (res: %i)\n", res);

	res = printf("Test a%pa", &res);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%pa", &res);
	printf(" (res: %i)\n", res);

	res = printf("Test a%ia", NULL);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%ia", NULL);
	printf(" (res: %i)\n", res);

	res = printf("Test a%ia", 0);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%ia", 0);
	printf(" (res: %i)\n", res);

	res = printf("Test a%ia", 987654321);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%ia", 987654321);
	printf(" (res: %i)\n", res);

	res = printf("Test a%ia", -987654321);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%ia", -987654321);
	printf(" (res: %i)\n", res);

	res = printf("Test a%ia", 9876543210);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%ia", 9876543210);
	printf(" (res: %i)\n", res);

	res = printf("Test a%ia", -9876543210);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%ia", -9876543210);
	printf(" (res: %i)\n", res);

	res = printf("Test a%da", NULL);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%da", NULL);
	printf(" (res: %i)\n", res);

	res = printf("Test a%da", 0);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%da", 0);
	printf(" (res: %i)\n", res);

	res = printf("Test a%da", 987654321);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%da", 987654321);
	printf(" (res: %i)\n", res);

	res = printf("Test a%da", -987654321);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%da", -987654321);
	printf(" (res: %i)\n", res);

	res = printf("Test a%da", 9876543210);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%da", 9876543210);
	printf(" (res: %i)\n", res);

	res = printf("Test a%da", -9876543210);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%da", -9876543210);
	printf(" (res: %i)\n", res);

	res = printf("Test a%ua", NULL);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%ua", NULL);
	printf(" (res: %i)\n", res);

	res = printf("Test a%ua", 0);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%ua", 0);
	printf(" (res: %i)\n", res);

	res = printf("Test a%ua", 987654321);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%ua", 987654321);
	printf(" (res: %i)\n", res);

	res = printf("Test a%ua", -1);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%ua", -1);
	printf(" (res: %i)\n", res);

	res = printf("Test a%ua", -987654321);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%ua", -987654321);
	printf(" (res: %i)\n", res);

	res = printf("Test a%ua", 9876543210);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%ua", 9876543210);
	printf(" (res: %i)\n", res);

	res = printf("Test a%ua", -9876543210);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%ua", -9876543210);
	printf(" (res: %i)\n", res);

	res = printf("Test a%xa", NULL);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%xa", NULL);
	printf(" (res: %i)\n", res);

	res = printf("Test a%xa", 0xa1b2c3d4);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%xa", 0xa1b2c3d4);
	printf(" (res: %i)\n", res);

	res = printf("Test a%xa", 0xFFFFFFFF);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%xa", 0xFFFFFFFF);
	printf(" (res: %i)\n", res);

	res = printf("Test a%xa", 0xFFFFFFFFDD);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%xa", 0xFFFFFFFFDD);
	printf(" (res: %i)\n", res);

	res = printf("Test a%xa", 0x0);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%xa", 0x0);
	printf(" (res: %i)\n", res);

	res = printf("Test a%Xa", NULL);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%Xa", NULL);
	printf(" (res: %i)\n", res);

	res = printf("Test a%Xa", 0xa1b2c3d4);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%Xa", 0xa1b2c3d4);
	printf(" (res: %i)\n", res);

	res = printf("Test a%Xa", 0xFFFFFFFF);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%Xa", 0xFFFFFFFF);
	printf(" (res: %i)\n", res);

	res = printf("Test a%Xa", 0xFFFFFFFFDD);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%Xa", 0xFFFFFFFFDD);
	printf(" (res: %i)\n", res);

	res = printf("Test a%Xa", 0x0);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%Xa", 0x0);
	printf(" (res: %i)\n", res);

	res = printf("Test a%%a", 0x0);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%%a", 0x0);
	printf(" (res: %i)\n", res);

	res = printf("Test a%%%%%%%%%%a", 0x0);
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%%%%%%%%%%a", 0x0);
	printf(" (res: %i)\n", res);

	res = printf("Test a%%%%%%%%%%a");
	printf(" (res: %i)\n", res);
	res = ft_printf("Test a%%%%%%%%%%a");
	printf(" (res: %i)\n", res);

	return (0);
}

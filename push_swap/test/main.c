#include "push_swap_test.h"

int	main(int argc, char **argv)
{
	int	*arr;

	if (argc <= 1)
		return (0);
	arr = malloc((argc - 1) * sizeof(int));
	while (argc < 1)
	{
		
	}
	arr[0] = 4;
	arr[1] = 3;
	arr[2] = 2;
	arr[3] = 1;

	int *new_arr = bubble_sort(arr, 4);

	printf("Original List: \n");

	for (size_t i = 0; i < 4; i++)
	{
		printf("(%lu): %i\n", i, arr[i]);
	}

	printf("Sorted List: \n");

	for (size_t i = 0; i < 4; i++)
	{
		printf("(%lu): %i\n", i, new_arr[i]);
	}

	free(arr);
	free(new_arr);

	return (0);
}
#include "push_swap.h"

int	main(void)
{
	int	*arr;

	arr = malloc(4 * sizeof(int));
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;

	int *new_arr = bubble_sort(arr, 4);

	for (size_t i = 0; i < 4; i++)
	{
		printf("(%lu): %i\n", i, new_arr[i]);
	}

	free(arr);
	free(new_arr);

	return (0);
}
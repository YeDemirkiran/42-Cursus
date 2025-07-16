#include "sorting.h"

void	copy_array(const int *src, int **target, size_t len)
{
	*target = malloc(len * sizeof(int));
	while (len--)
		(*target)[len] = src[len];		
}

int	*bubble_sort(const int *arr, size_t len)
{
	int	*new_arr;

	copy_array(arr, &new_arr, len);

	return (new_arr);
}

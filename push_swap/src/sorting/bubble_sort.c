#include "sorting.h"

void	copy_array(const int *src, int **target, size_t len)
{
	*target = malloc(len * sizeof(int));
	while (len--)
		(*target)[len] = src[len];		
}

int	*bubble_sort(const int *arr, size_t len)
{
	int		*new_arr;
	int		tmp;
	size_t	i;

	copy_array(arr, &new_arr, len);
	i = 1;
	while (i < len)
	{
		if (new_arr[i] < new_arr[i - 1])
		{
			tmp = new_arr[i];
			new_arr[i] = new_arr[i - 1];
			new_arr[i - 1] = tmp;
			i = 1;
			continue;
		}
		i++;
	}
	return (new_arr);
}

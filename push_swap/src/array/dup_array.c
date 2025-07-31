#include "array.h"

int	*dup_int_array(const int *src, size_t len)
{
	int	*dup;

	dup = malloc(len * sizeof(int));
	if (!dup)
		return (NULL);
	while (len--)
		dup[len] = src[len];
	return (dup);	
}

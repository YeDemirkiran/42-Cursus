#ifndef SORTING_H
# define SORTING_H

# include "dependencies.h"
# include "stack.h"
# include "array.h"

int	*bubble_sort(const int *arr, size_t len);
void bubble_sort_ps(t_stack *stack, int size, int *instructions);

#endif
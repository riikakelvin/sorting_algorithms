#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  via selection sort algorithm.
 * @array: An array of integers.
 * @size: Size of the array.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t k, j;

	if (array == NULL || size < 2)
		return;

	for (k = 0; k < size - 1; k++)
	{
		min = array + k;
		for (j = k + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + k) != min)
		{
			swap_ints(array + k, min);
			print_array(array, size);
		}
	}
}

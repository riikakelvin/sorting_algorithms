#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * shell_sort - Sorts an array of integers in ascending order
 * @array: An array of integers.
 * @size: Size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, k, t;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (k = gap; k < size; k++)
		{
			t = k;
			while (t >= gap && array[t - gap] > array[t])
			{
				swap_ints(array + t, array + (t - gap));
				t -= gap;
			}
		}
		print_array(array, size);
	}
}


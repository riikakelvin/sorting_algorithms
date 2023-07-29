#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Sort a subarray of integers.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: Buffer that stores the sorted subarray.
 * @front: Front index of the array.
 * @mid: Mid-index of the array.
 * @back: Back index of the array.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t e, l, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (e = front, l = mid; e < mid && l < back; k++)
		buff[k] = (subarr[e] < subarr[j]) ? subarr[e++] : subarr[l++];
	for (; e < mid; e++)
		buff[k++] = subarr[e];
	for (; l < back; l++)
		buff[k++] = subarr[l];
	for (e = front, k = 0; e < back; e++)
		subarr[e] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Implements the merge sort algorithm through recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: buffer to store sorted result.
 * @front: Front index of the subarray.
 * @back: Back index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending order (A-Z)
 * @array: An array of integers.
 * @size: Size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}


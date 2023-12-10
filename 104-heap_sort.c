#include "sort.h"

/**
 * swap - swaps position of values in array
 * @array: array to be changed
 * @first: first index
 * @second: second index
 */
void swap(int **array, int first, int second)
{
	int hlder;

	hlder = (*array)[first];
	(*array)[first] = (*array)[second];
	(*array)[second] = hlder;
}

/**
 * build_Max_Heap - builds a heap from an array
 * @array: array to be changed to heap array
 * @end_index: end index as array is partitioned
 * @start_index: starting point index as array is sorted
 * @a_size: array size unchanged
 */
void build_Max_Heap(int *array, int end_index, int start_index, int a_size)
{
	int biggest, left, right;

	biggest = start_index;
	left = (start_index * 2) + 1;
	right = (start_index * 2) + 2;

	if (left < end_index && array[left] > array[biggest])
		biggest = left;

	if (right < end_index && array[right] > array[biggest])
		biggest = right;

	if (biggest != start_index)
	{
		swap(&array, start_index, biggest);
		print_array(array, a_size);
		build_Max_Heap(array, end_index, biggest, a_size);
	}
}

/**
 * heap_sort - sorts an array using the heap sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int start_index, i;

	if (!array || size < 2)
		return;

	start_index = ((int) size - 1) / 2;

	for (i = start_index; i >= 0; i--)
	{
		build_Max_Heap(array, size, i, size);
	}

	for (i = size - 1; i > 0; i--)
	{
		swap(&array, 0, i);
		print_array(array, size);
		build_Max_Heap(array, i, 0, size);
	}
}

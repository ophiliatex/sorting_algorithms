#include "sort.h"

/**
 * bubble_sort - A function that sorts an array of integers in ascending order
 * using Bubble sort.
 *
 * @array: Array to be sorted.
 * @size: Number of elements in the array to be sorted.
 */
void bubble_sort(int *array, size_t size)
{
	int    tmp;
	size_t i, j;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp	     = array[j];
				array[j]     = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}

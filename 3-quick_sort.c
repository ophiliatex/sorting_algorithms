#include "sort.h"


/**
 * swap_post - swaps the position of the elements
 * in an array
 *
 * @array: array to be changed
 * @first: first index
 * @second: second index
*/

void swap_post(int **array, size_t first, size_t second)
{
	int hlder;

	hlder = (*array)[first];
	(*array)[first] = (*array)[second];
	(*array)[second] = hlder;
}

/**
 * split - splits the array into two parts and returns the index
 * of the array
 *
 * @array: array to be sorted
 * @lower: lower boundary
 * @higher: higher boundary
 * @size: number of elements in the array
 *
 * Return: index of the array
*/
size_t split(int **array, size_t lower, size_t higher, size_t size)
{
	size_t bfor, aft, pivot;

	pivot = higher;
	bfor = lower;

	for (aft = bfor; aft < higher; aft++)
	{
		if ((*array)[aft] <= (*array)[pivot])
		{
			if (bfor != aft)
			{
				swap_post(array, bfor, aft);
				print_array(*array, size);
			}
			bfor += 1;
		}
	}

	if (bfor != aft)
	{
		swap_post(array, bfor, aft);
		print_array(*array, size);
	}
	return (bfor);
}

/**
 * sort - Sorts an array in a recursive manner
 * @array: The array to be sorted
 * @low: lowest boundary
 * @higher: highest boundary
 * @size: number of elements in the array
*/

void sort(int **array, size_t low, size_t higher, size_t size)
{
	size_t sorted_index;

	if (low < higher && *array)
	{
		sorted_index = split(array, low, higher, size);

		if (sorted_index - low > 1)
			sort(array, low, sorted_index - 1, size);

		if (higher - sorted_index > 1)
			sort(array, sorted_index + 1, higher, size);
	}
}
/**
 * quick_sort - A function that sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: Array to be sorted
 * @size: Size of element to be sorted
*/

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	sorter(&array, 0, size - 1, size);
}

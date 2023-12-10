#include "sort.h"

/**
 * arr_zero_init - initialize the array by zero
 * @array: array to be initialized
 * @size: size of the array
 */
void arr_zero_init(int *array, int size)
{
	int i;

	for (i = 0; i < size; i++)
		array[i] = 0;
}

/**
 * get_big - gets the bigest value in the array
 * @array: array to get big value from
 * @size: size of the array
 *
 * Return: bigest value in the array
 */
int get_big(int *array, size_t size)
{
	int big;
	size_t i;

	if (size < 2)
		return (0);

	big = array[0];

	for (i = 1; i < size; i++)
	{
		if (big < array[i])
			big = array[i];
	}

	return (big);
}

/**
 * counting_sort - sorts an array using the counting sort algorithm
 * @array: initial array
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int k = get_big(array, size), j, *index, *sumindex, *sorted;
	size_t i;

	if (k == 0)
		return;

	index = malloc(sizeof(int) * (k + 1));
	if (!index)
		return;
	arr_zero_init(index, k + 1);

	for (i = 0; i < size; i++)
		index[array[i]] += 1;

	sumindex = malloc(sizeof(int) * (k + 1));
	if (!sumindex)
		return;
	arr_zero_init(sumindex, k + 1);
	sumindex[0] = index[0];

	for (j = 1; j < (k + 1); j++)
		sumindex[j] = index[j] + sumindex[j - 1];

	free(index), print_array(sumindex, k + 1);

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return;
	arr_zero_init(sorted, size);

	for (i = 0; i < size; i++)
	{
		sumindex[array[i]] -= 1;
		sorted[sumindex[array[i]]] = array[i];
	}
	free(sumindex);

	for (i = 0; i < size; i++)
		array[i] = sorted[i];
	free(sorted);
}

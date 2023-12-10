#include "sort.h"

/**
 * nodes_swap - Swaps two nodes in a doubly linked list
 *
 * @list: A double pointer to the head of the list.
 * @first: A pointer to the first node to be swapped.
 * @second: A pointer to the second node to be swapped.
 */

void nodes_swap(listint_t **list, listint_t *first, listint_t *second)
{
	if (!first->prev)
		*list = second;
	else
		first->prev->next = second;

	second->prev = first->prev;

	if (second->next)
		second->next->prev = first;


	first->prev = second;
	first->next = second->next;
	second->next = first;
}


/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm.
 * @list: A double pointer to the head of the list.
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *end;
	int swapped = 1;

	if (!list || !(*list) || !(*list)->next)
		return;

	end = *list;
	while (swapped)
	{
		swapped = 0;
		while (end->next)
		{
			if (end->n > end->next->n)
			{
				nodes_swap(list, end, end->next);
				print_list(*list);
				swapped = 1;
				continue;
			}
			end = end->next;
		}

		if (!swapped)
			break;

		swapped = 0;
		while (end->prev)
		{
			if (end->n < end->prev->n)
			{
				nodes_swap(list, end->prev, end);
				print_list(*list);
				swapped = 1;
				continue;
			}
			end = end->prev;
		}
	}
}

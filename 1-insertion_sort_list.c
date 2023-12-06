#include "sort.h"

/**
 * insertion_sort_list - A function that sorts a doubly linked list of integers in ascending order
 * using the Insertion sort algorithm
 * 
 * @list: A pointer to the head of the list
*/

void insertion_sort_list(listint_t **list)
{
    listint_t *cur, *sortd, *tmp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
            return;

    cur = (*list)->next;

    while (cur)
    {
        sortd = cur->prev;
        while (sortd && sortd->n > cur->n)
        {
            tmp = sortd->prev;
        if (tmp)
        {
            tmp->next = cur;
        }
        else
                *list = cur;
        sortd->prev = cur;
        sortd->next = cur->next;
        cur->prev = tmp;
        if (cur->next)
        cur->next->prev = sortd;
        cur->next = sortd;
        print_list(*list);
        sortd = cur->prev;
        }
 
        
    }
     
}
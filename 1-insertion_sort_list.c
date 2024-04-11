#include "sort.h"
/**
 * insertion_sort_list - fct that sort ints in ascending order
 * using the insertion sort algorithm
 * @list: list to sort
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{

	if (*list == NULL || (*list)->next == NULL)
		return;

	listint_t *current = (*list)->next;

	while (current != NULL)
	{
		listint_t *previous = current->prev;

		while (previous != NULL && current->n < previous->n)
		{
			listint_t *next_node = current->next;
			listint_t *prev_node = previous->prev;

			previous->next = next_node;

			if (next_node != NULL)
				next_node->prev = previous;

			current->next = previous;
			current->prev = prev_node;
			previous->prev = current;

			if (prev_node == NULL)
				*list = current;
			else
				prev_node->next = current;

			previous = current->prev;

			print_list(*list);
		}
		current = current->next;
	}
}



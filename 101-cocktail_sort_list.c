#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list
 * @list: ptr to the head of a doubly-linked list of integers
 * @tail: ptr to the tail of the doubly-linked list
 * @shaker: A ptr to the current swapping node of the cocktail shaker algo.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *buffer = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = buffer;
	else
		*list = buffer;
	buffer->prev = (*shaker)->prev;
	(*shaker)->next = buffer->next;
	if (buffer->next != NULL)
		buffer->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = buffer;
	buffer->next = *shaker;
	*shaker = buffer;
}

/**
 * swap_node_behind - Swap a node behind in a listint_t doubly-linkedlist
 * @list: ptr to the head of a doubly-linked list of integers.
 * @tail: A ptr to the tail of the doubly-linked list
 * @shaker: A ptr to the current swapping node of the cocktail shaker algorithm
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *buffer = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = buffer;
	else
		*tail = buffer;
	buffer->next = (*shaker)->next;
	(*shaker)->prev = buffer->prev;
	if (buffer->prev != NULL)
		buffer->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = buffer;
	buffer->prev = *shaker;
	*shaker = buffer;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 * ascending order using the cocktail shaker algorithm
 * @list: A ptr to the head of a listint_t doubly-linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
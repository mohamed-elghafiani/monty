#include <stdlib.h>
#include "monty.h"

/**
 * free_stack - a function that frees the stack
 *
 * @head: a pointer to the first element in the stack
 * Return: Nothing
 */

void free_stack(stack_t *head)
{
	if (head == NULL)
	{
		return;
	}
	/* Go to the end of the list */
	while (head->next)
	{
		head = head->next;
	}
	/* Start freeing each node by going backwards */
	while (head->prev)
	{
		head = head->prev;
		free(head->next);
	}
	free(head);
}

#include <stdlib.h>
#include "monty.h"


/**
 * free_stack - a function thats fress the stack
 *
 * @head: a pointer to the first element in the stack
 * Return: Nothing
 */
void free_stack(stack_t *head)
{
	stack_t *tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		if (tmp->prev)
		{
			free(tmp->prev);
		}
		free(tmp);
	}
}

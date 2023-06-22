#include <stdio.h>
#include "monty.h"

/**
 * pall - a function prints all the values on the stack,
 *	starting from the top of the stack
 *
 * @head: a pointer to the first element in the stack
 * Return: Nothing
 */
void pall(stack_t *head)
{
	if (!head)
	{
		return;
	}
	while (head->next)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
	printf("%d\n", head->n);
}

#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pall - a function prints all the values on the stack,
 *	starting from the top of the stack
 *
 * @stack: a pointer to the first element in the stack
 * @line_number: the line number the opcode is written in the monty file
 * Return: Nothing
 */
void pall(stack_t **stack, int arg, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp;
	(void) arg;

	tmp = *stack;
	if (!tmp)
	{
		return;
	}
	while (tmp->next)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	printf("%d\n", tmp->n);
}

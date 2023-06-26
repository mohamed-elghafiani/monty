#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * pop - removes the top element of the stack
 *
 * @stack: a pointer to the first element in the stack
 * @line_number: the line number the opcode is written in the monty file
 * Return: Nothing
 */
void pop(stack_t **stack, int arg, unsigned int line_number)
{
	stack_t *current;
	(void) arg;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	*stack = (*stack)->next;
	free(current);
}

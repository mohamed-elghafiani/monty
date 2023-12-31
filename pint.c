#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 *
 * @stack: a pointer to the first element in the stack
 * @line_number: the line number the opcode is written in the monty file
 * Return: Nothing
 */
void pint(stack_t **stack, int arg, unsigned int line_number)
{
	(void) arg;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

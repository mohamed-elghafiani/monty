#include "monty.h"

/**
 * nop - an no operation opcode
 *
 * @stack: a double pointer to the head of the stack
 * @arg: the argument of the opcode
 * @line_number: the line number where the opcode lie in the monty file
 * Return: Nothing
 */
void nop(stack_t **stack, int arg, unsigned int line_number)
{
	(void) stack;
	(void) arg;
	(void) line_number;

	return;
}

#include <stdio.h>
#include "monty.h"

/**
 * pall - a function prints all the values on the stack,
 *	starting from the top of the stack
 *
 * @stack: a pointer to the first element in the stack
 * Return: Nothing
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	if (!*stack)
	{
		return;
	}
	while ((*stack)->next)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}
	printf("%d\n", (*stack)->n);
}

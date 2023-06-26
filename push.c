#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * push - a function that pushes an element to the stack.
 *
 * @stack: a pointer to the stack of the stack
 * @line_number: the line number the opcode is written in the monty file
 * Return: Nothing
 */
void push(stack_t **stack, int arg, __attribute__((unused)) unsigned int line_number)
{
	stack_t *new_node;

	/*if (node_integer == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}*/
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = arg;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

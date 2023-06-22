#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * push - a function that pushes an element to the stack.
 *
 * @head: a pointer to the head of the stack
 * @n: the value of the new node in the stack
 * Return: Nothing
 */
stack_t *push(stack_t **head, const int n)
{
	stack_t *new_elm;

	new_elm = malloc(sizeof(stack_t));
	if (new_elm == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_elm->n = n;
	new_elm->prev = NULL;
	if (*head == NULL)
	{
		return (new_elm);
	}
	new_elm->next = *head;
	*head = new_elm;
	return (*head);
}

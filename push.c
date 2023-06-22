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
void push(stack_t **head, const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}
	new_node->prev = NULL;
	new_node->next = *head;
	*head = new_node;
}

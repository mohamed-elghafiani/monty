#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
#define MAX_BUFFER_SIZE 256

int arg;

/**
 * main - main dunction of the program
 *
 * @argc: # of arguments passed
 * @argv: arguments vector
 * Return: Nothing
 */

int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	instruction_t instructions[] = {{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop}, {NULL, NULL}};
	char line[MAX_BUFFER_SIZE], *opcode;
	unsigned int i = 0, n = 1;
	int arg, m;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, MAX_BUFFER_SIZE, file) != NULL)
	{
		i = 0;
		if (line[0] == '\n')
		{
			n++;
			continue;
		}
		m = get_operation(line, &opcode, &arg);
		if (m == -1)
		{
			n++;
			continue;
		}
		if (m == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", n);
			exit(EXIT_FAILURE);
		}
		if (m == 2)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", n, opcode);
			free_stack(stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		while (instructions[i].opcode != NULL)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, arg, n);
				break;
			}
			i++;
		}
		n++;
	}
	free_stack(stack);
	fclose(file);
	return (0);
}

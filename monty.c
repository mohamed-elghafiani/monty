#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
#define BUFFER_SIZE 10

int node_integer;

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
	instruction_t instructions[] = {{"push", push}, {"pall", pall}, {NULL, NULL}};
	char line[BUFFER_SIZE], opcode[10], argument[100];
	int i = 0;
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
	while (fgets(line, 10, file))
	{
		sscanf(line, " %s %s", opcode, argument);
		node_integer = atoi(argument);

		while (instructions[i].opcode != NULL)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, __LINE__);
				break;
			}
			i++;
		}
		memset(opcode, 0, 10);
		i = 0;
	}
	free_stack(stack);
	fclose(file);
	return (0);
}

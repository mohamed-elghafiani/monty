#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
#define MAX_BUFFER_SIZE 256

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
	instruction_t instructions[] = {{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop}, {NULL, NULL}};
	char line[MAX_BUFFER_SIZE], opcode[10] = {0}, argument[10] = {0};
	unsigned int i = 0, inst_found = 0, scans = 0, n = 1;
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
	while (fgets(line, sizeof(line), file))
	{
		if (line[0] == '\n')
		{
			n++;
			continue;
		}
		scans = sscanf(line, " %s%*[ ]%s ", opcode, argument);
		if (strlen(argument) > 0)
		{

			node_integer = atoi(argument);
		}
		if (scans >= 1)
		{
			while (instructions[i].opcode != NULL)
			{
				if (strcmp("push", instructions[i].opcode) == 0 && scans == 1)
				{
					fprintf(stderr, "L%d: usage: push integer\n", n);
					exit(EXIT_FAILURE);
				}
				if (strcmp(opcode, instructions[i].opcode) == 0)
				{
					instructions[i].f(&stack, n);
					inst_found = 1;
					break;
				}
				i++;
			}
			if (inst_found == 0)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", n, opcode);
				free_stack(stack);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			memset(opcode, 0, 10);
			memset(argument, 0, 10);
			i = 0;
			inst_found = 0;
		}
		n++;
	}
	free_stack(stack);
	fclose(file);
	return (0);
}

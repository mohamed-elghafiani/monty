#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
#define BUFFER_SIZE 10

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
	int n = 10;
	char line[BUFFER_SIZE], *opcode;
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	while (fgets(line, 10, file))
	{
		opcode = strtok(line, " ");
		if (strcmp(opcode, "push") == 0)
		{
			n = atoi(strtok(NULL, " "));
			if (!n)
			{
				fprintf(stderr, "L%d: usage: push integer\n", __LINE__);
				exit(EXIT_FAILURE);
			}
			stack = push(&stack, n);
		}
		else if (strcmp(opcode, "pall"))
		{
			pall(stack);
		}
	}

	fclose(file);
	return (0);
}

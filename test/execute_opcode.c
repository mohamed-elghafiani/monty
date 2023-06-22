#include "monty.h"

/**
 *
 *
 *
 *
 *
 */
void execute_opcode()
{
	instruction_t *instructions = {
		"push", push,
		"pall", pall,
		NULL, NULL
	};

	char *opcode = strtok(line, " \t\n");
	if (opcode == NULL)
    		continue;

	int i;
	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(&stack, line_number);
			break;
		}
	}

	if (instructions[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}


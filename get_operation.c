#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * op_isvalid - a function that checks if an operation is valid
 *
 * @opcode: the operation code
 * @op_arr: an array of valid operation codes
 * Return: 1 if the operation is valid and 0 otherwise
 */
int op_isvalid(char *opcode, char **op_arr)
{
	int i = 0;

	while (op_arr[i])
	{
		if (strcmp(opcode, op_arr[i]) == 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}


/**
 * get_operation - a function to extract the operation to perform
 *
 * Description: this function will process each line and returns
 *	the operation intended as opecode and argument
 * @line: the line to process
 * @line_number: the line number where the operation appears in the monty file
 * @opcode: a double pointer where the opcode will be stored
 * @argument: a placeholder  for the argument of the opcode
 * Return: 0 on everything is okay and 1 if there is no arg for `push`
 * 	and 2 if the `opcode` doesn't exist
 */
int get_operation(char *line, char **opcode, int *argument)
{
	char *arg;
	char *ops[] = {"push", "pall", "pint", "pop", "swap", "add", "nop", NULL};

	*opcode = strtok(line, " \n");
	if (!*opcode)
	{
		return (-1);
	}
	arg = strtok(NULL, " \n");
	if (op_isvalid(*opcode, ops) == 0)
	{
		return (2);
	}
	if (isdigitstr(arg) == -1)
	{
		if (strcmp(*opcode, "push") == 0)
		{
			return (1);
		}
		arg = "0";
	}
	if (strlen(arg) == 1)
	{
		*argument = arg[0] - '0';
	}
	else
	{
		*argument = atoi(arg);
	}
	return (0);
}

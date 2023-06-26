#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - a test function
 *
 * Return: 0 always
 */
int main(int argc, char **argv)
{
	int isdigit;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: ./main stringi\n");
		exit(EXIT_FAILURE);
	}

	isdigit = isdigitstr(argv[1]);
	if (isdigit == -1)
	{
		printf("Ops try again! This is not a digit\n");
		exit(EXIT_FAILURE);
	}
	if (isdigit == 0)
	{
		printf("Great job!\n");
		exit(EXIT_SUCCESS);
	}
	return (0);
}

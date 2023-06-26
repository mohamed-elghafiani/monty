#include <ctype.h>
#include "main.h"

/**
 * isdigitstr - a function that checks is a string contains only digits
 *
 * @str: a string
 * Return: 0 (if the whole string is digits) and -1 otherwise
 */
int isdigitstr(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (!isdigit(str[i]))
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

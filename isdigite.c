#include "monty.h"
#include <ctype.h>
/**
 * is_arg_digit - check if a string is a valid integer
 * @arg: string to check
 *
 * Return: 0 if the string is a valid integer, 1 otherwise
 */
int is_arg_digit(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (!isdigit(arg[i]))
			return (1);
	}

	return (0);
}

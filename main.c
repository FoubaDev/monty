#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

/* define a global variable*/
global_t global;

/**
 *main - monty interpreter
 *@argc: number of argument
 *@argv: array of argument
 *Return: nothing
 */

int main(int argc, char *argv[])
{
	char line[MAX_LINE_LENGTH];
	stack_t *stack = NULL;
	FILE *file;
	unsigned int line_number = 0;

	global = init_global();

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
		line_number++;
		compile(line, &stack, line_number, file);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}

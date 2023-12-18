#include "monty.h"

/**
 * extract_op - get operator using instructions array
 * @op: operator to check
 * @stack: double pointer
 * @line_number: line number
 * Return: void
 */
void extract_op(char *op, stack_t **stack, unsigned int line_number)
{
	size_t i;
	instruction_t array_op[] = {
		{"push", push_element},
		{"pall", pall},
		{NULL, NULL}
	};

	for (i = 0; array_op[i].opcode != NULL; i++)
	{
		if (strcmp(array_op[i].opcode, op) == 0)
		{
			array_op[i].f(stack, line_number);
			return;
		}
	}

	fprintf(STDOUT_FILENO,
		"L%u: unknown instruction %s\n",
		line_number, op);
	exit(EXIT_FAILURE);
}

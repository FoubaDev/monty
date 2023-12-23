#include "monty.h"

/**
 * compile - executes the opcode
 * @stack: head of linked list - stack
 * @counter: line_counter
 * @file: pointer to file
 * @content: line content
 * Return: nothing
 */
int compile(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t array_instruction[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");

	if (op && op[0] == '#')
		return (0);
	global.arg = strtok(NULL, " \n\t");
	while (array_instruction[i].opcode && op)
		{
		if (strcmp(op, array_instruction[i].opcode) == 0)
		{
			array_instruction[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && array_instruction[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}


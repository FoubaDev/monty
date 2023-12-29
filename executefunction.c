#include "monty.h"

/**
 * compile - Executes the opcode
 * @content: Line content
 * @stack: Head of the linked list (stack)
 * @counter: Line counter
 * @file: Pointer to the file
 *
 * Return: 0 on success, 1 on failure
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

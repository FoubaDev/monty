#include "monty.h"

/**
 * push - Pushes a new element onto the stack
 * @stack: Pointer to the head of the stack
 * @line_number: Line number
 *
 * Return: No return value
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n, g = 0, flag = 0;

	if (!(global.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(global.file);
		free(global.content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (global.arg[0] == '-')
			g++;
		while (global.arg[g] != '\0')
		{
			if (global.arg[g] > '9' || global.arg[g] < '0')
			{
				flag = 1;
				break;
			}
			g++;
		}

		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(global.file);
			free(global.content);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(global.arg);

	if (global.flag == 0)
		add_new_node(stack, n);
	else
		addqueue(stack, n);
}

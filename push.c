#include "monty.h"

/**
 * push - push new element onto the stack
 * @stack: head stack
 * @line_number: line number
 * Return: no return
 */

void push(stack_t **stack, unsigned int line_number)
{
	int n, g = 0, flag = 0;
	/* call our global struct variable from  monty.h*/
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
		for (; global.arg[g] != '\0'; g++)
		{
			if (global.arg[g] > 57 || global.arg[g] < 48)
				flag = 1; }
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(global.file);
			free(global.content);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}
	/* convert global.arg variable to integer*/
	n = atoi(global.arg);
	if (global.flag == 0)
		add_new_node(stack, n);
	else
		addqueue(stack, n);
}

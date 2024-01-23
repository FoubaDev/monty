#include "monty.h"
/**
 * pall - print the stack from the beginning to the end
 * @stack: stack to be printed
 * @line_number: var not used.
 * Return: nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	size_t i = 0;
	stack_t *temp = *stack;

	(void)line_number;

	for (i = 0; temp != NULL; i++)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->next;
	}

}

#include "monty.h"

/**
 * pall - prints all values on the stack
 * @stack: pointer to the stack
 * @line_number: line number (unused)
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	/* ignore unused variable */
	(void)line_number;

	h = *stack;
	if (h == NULL)
		return;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

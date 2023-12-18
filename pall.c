#include "monty.h"

/**
 * f_pall - prints all value  on the stack
 * @stack: stack stack
 * @line_number: no used
 * Return: no return
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

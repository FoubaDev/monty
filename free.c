#include "monty.h"

/**
 * free_stack - free memory used by a stac
 * @head: head of the stack
 */
void free_stack(stack_t *head)
{
	stack_t *current;

	current = head;
	while (head)
	{
		current = head->next;
		free(head);
		head = current;
	}
}


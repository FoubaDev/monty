#include "monty.h"

/**
 * free_stack - Free memory used by a stack
 * @head: Head of the stack
 *
 * Description: This function frees the memory used by a stack.
 * It iterates through the stack, freeing each node, until the end.
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

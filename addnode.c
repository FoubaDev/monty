#include "monty.h"

/**
 * add_new_node - Add element to the head of the stack
 * @head: Pointer to the head of the stack
 * @n: Value of the new element
 *
 * Return: No return value
 */
void add_new_node(stack_t **head, int n)
{
	stack_t *new_node, *current;

	current = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (current != NULL)
		current->prev = new_node;

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

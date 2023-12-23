#include "monty.h"

/**
 * print_queue - Prints the top of the queue
 * @head: Pointer to the head of the queue
 * @line_number: Line number
 *
 * Return: Nothing
 */
void print_queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	global.flag = 1;
}

/**
 * addqueue - Adds an element to the tail of the queue
 * @n: New element
 * @head: Pointer to the head of the queue
 *
 * Return: Nothing
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *current;

	current = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (current)
	{
		while (current->next)
			current = current->next;
	}
	if (current)
	{
		current->next = new_node;
		new_node->prev = current;
	}
	else
	{
		*head = new_node;
		new_node->prev = NULL;
	}
}

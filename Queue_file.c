#include "monty.h"

/**
 * print_queue - prints the top
 * @head: stack head
 * @line_number: line_number
 * Return: nothing
 */
void print_queue(stack_t **head, unsigned int line_number)
{
        /* handle error of  unused variable */
	(void)head;
	(void)line_number;
	global.flag = 1;
}

/**
 * addqueue - add element to the tail
 * @n: new element
 * @head: head of the stack
 * Return: nothing
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

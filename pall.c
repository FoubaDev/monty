#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <sys/types.h>  


/**
 * pall - prints all the values on the stack, from the top of the stack.
 *@line_number - int value to push
 * Return: Nothing
 */

void pall(stack_t **stack, unsigned int line_number)
{
		
	stack_t *current = *stack;
	for (; current; current = current->next) 
	{
		printf("%d\n", current->n);
	}
	(void)line_number;
}

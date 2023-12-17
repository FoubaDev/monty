#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * push - Pushes a new element in the stack
 *@line_number - int value to push
 * Return: Nothing
 */
void push(stack_t **stack, unsigned int line_number)
{   
    stack_t *new_node;
    int value = 0;  /* integer to check */
    if (!value) 
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Create a new stack node and  its value */
    
    new_node = (stack_t *)malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = value;

    /* the next of the new_code will the new pointer stack */
    new_node->next = *stack;

   /* Then the current stack is the new_node created */
    *stack = new_node;
}

#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* define a struct that contains global variables*/
/**
 * struct global_s - define struct that contains our global variable
 * @arg: number of argument
 * @file: file to read
 * @content: content to read
 * @flag: integer to between last and next node;
 *
 */
typedef struct global_s
{
	char *arg;
	FILE *file;
	char *content;
	int flag;
} global_t;
extern global_t global;
/* prototyoes functions */
global_t init_global(void);
void push(stack_t **head, unsigned int number);
void pall(stack_t **head, unsigned int number);
int compile(char *content, stack_t **stack, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void print_queue(stack_t **head, unsigned int line_number);
void add_new_node(stack_t **head, int n);
void addqueue(stack_t **head, int n);
#endif

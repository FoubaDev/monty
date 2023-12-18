#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
global_t global = {NULL, NULL, NULL, 0};


int main(int argc, char *argv[])
{
    char line[MAX_LINE_LENGTH];
    stack_t *stack = NULL;
    FILE *file;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file))
    {
        line_number++;
        compile(line, &stack, line_number, file);
    }

    free_stack(stack);
    fclose(file);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

void readFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Failed to open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[256];
    unsigned int line_number = 0;

    stack_t* stack = createStackNode(0);

    while (fgets(line, sizeof(line), file)) {
        line_number++;

        char* opcode = strtok(line, " \n\t\r");
        if (opcode != NULL) {
            executeInstruction(NULL, &stack, opcode, line_number);
        }
    }

    fclose(file);

    // Free memory and clean up
    while (stack != NULL) {
        stack_t* temp = stack;
        stack = stack->next;
        free(temp);
    }
}

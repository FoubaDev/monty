#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"


stack_t* createStackNode(int data) {
    stack_t* newNode = (stack_t*)malloc(sizeof(stack_t));
    newNode->n = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

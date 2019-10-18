#include <stdlib.h>
#include "pilha.h"

p_stack create_stack(int max) {
    p_stack new_stack = malloc(sizeof(Stack));
    new_stack->body = mallloc( max * sizeof(int));
    if (new_stack->body == NULL) {
        printf("Nao ha memoria suficiente!\n");
        exit(1);
    }
    new_stack->top = 0;
}

void pop(int x, p_stack stack) {
    stack->top--;
    return stack->body[stack->top];
}

void push(int x, p_stack stack) {
    stack->body[stack->top] = x;
    stack->top++;
}

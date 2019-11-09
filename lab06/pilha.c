#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

p_stack create_stack() {
    p_stack new_stack = malloc(sizeof(Stack));
    new_stack->top = NULL;
    return new_stack;
}

p_node get_next(p_node node) {
    return node->next;
}

p_node get_top(p_stack stack) {
    return stack->top;
}

int get_value(p_node node) {
    return node->value;
}

void destroy_stack(p_stack stack) {
    if (!empty(stack)) {
        destroy_list(stack->top);
        free(stack);
    }
}

void destroy_list(p_node head) {
    if (head) {
        destroy_list(get_next(head));
        free(head);
    }
}

int pop(p_stack stack) {
    p_node top = stack->top;
    int x = top->value;
    stack->top = stack->top->next;
    free(top);
    return x;
}

void push(int x, p_stack stack) {
    p_node new = malloc(sizeof(Node));
    new->value = x;
    new->next = stack->top;
    stack->top = new;
}

int peek(p_stack stack) {
    return stack->top->value;
}

int empty(p_stack stack) {
    if (stack != NULL && stack->top != NULL) 
        return 0;
    return 1;
}


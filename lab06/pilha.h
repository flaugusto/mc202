#ifndef PILHA_H
#define PILHA_H

typedef struct Stack {
    int *body;
    int top;
} Stack;

typedef struct Stack* p_stack;

/**
 * Cria uma nova pilha vazia
 * */
p_stack create_stack();

/**
 * Libera a memória alocada para a pilha
 * */
void destroy_stack(p_stack stack);

/**
 * Empilha um novo elemento
*/
void push(int x, p_stack stack);

/**
 * Desempilha o último elemento inserido 
 */
void pop(int x, p_stack stack);

#endif

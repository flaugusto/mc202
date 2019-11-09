#ifndef PILHA_H
#define PILHA_H

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Node* p_node;

p_node get_next(p_node node);

int get_value(p_node node);

void destroy_list(p_node head);

typedef struct Stack {
    p_node top;
} Stack;

typedef struct Stack* p_stack;

p_node get_top(p_stack stack);
/**
 * Cria uma nova pilha vazia
 * */
p_stack create_stack();

/**
 * Libera a memória alocada para a pilha
 * 
 * @stack: ponteiro para uma pilha válida
 * */
void destroy_stack(p_stack stack);

/**
 * Empilha um novo elemento
 * @stack: ponteiro para uma pilha válida
*/
void push(int x, p_stack stack);

/**
 * Desempilha o último elemento inserido 
 * 
 */
int pop(p_stack stack);

/** 
 * Retorna o valor do topo da pilha
 * */
int peek(p_stack stack);

/** 
 * Retorna 1 se a pilha não tiver nenhum elemento
 * 0 caso contrário.
 * */
int empty(p_stack stack);




#endif

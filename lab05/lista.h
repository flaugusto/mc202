#ifndef LISTA_H
#define LISTA_H

typedef struct Node {
    Block data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Node* p_node;

/**
 * Cria uma nova lista vazia
 * */
p_node create_list();

/**
 * Insere um novo nó a partir da posição dada
 * x -> dados a serem inseridos no nó
 * list -> ponteiro para o primeiro nó da lista
 * Retorno: um ponteiro para o começo da lista com o novo nó inserido
 * */
p_node insert(Block x, p_node* pos, p_node list);

p_node* search_insertpos();

p_node remove(Block x, p_node pos);

/**
 *  Libera a memeória da lista
 * */
void destroy_list(p_node list);

/**
 * Imprime a lista na tela
 * */
void print(p_node list);

#endif

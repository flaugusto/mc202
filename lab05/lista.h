#ifndef LISTA_H
#define LISTA_H
#include "heap.h"

typedef struct Node {
    Block data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Node* p_node;

/**
 * Aloca um novo nó da lista
 * */
p_node create_node();

/**
 * Cria uma nova lista vazia
 * */
p_node create_list();

/**
 * Insere um novo nó ordenado com base na posição do bloco
 * x -> dados a serem inseridos no nó
 * head -> ponteiro para o primeiro nó da lista
 * Retorno: um ponteiro para o começo da lista com o novo nó inserido
 * */
p_node insert_sorted(Block x, p_node head);

p_node bestfit(Block x, p_node head);

p_node delete_sorted(Block x, p_node head);

/**
 *  Libera a memeória da lista
 * */
void destroy_list(p_node list);

/**
 * Imprime a lista na tela
 * */
void print(p_node list);

#endif

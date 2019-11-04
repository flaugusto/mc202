#ifndef HEAP_H
#define HEAP_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_LEN 5
/** Estrutura de define cada item do vetor do heap 
 * code: string que representa o código de cada caixa
*/
typedef struct Item{
    char code[MAX_LEN];
} Item;

/**
 * Retorna um novo Item do Heap
 * 
 * @code: uma string para ser armazenada no código do Item
 * */
Item create_item(char* code);

/**
 * Estrutura que define o heap
 * 
 * v: ponteiro para um vetor alocado, para guardar os itens do Heap
 * i: inteiro que controla o tamanho atual do Heap
 * size: inteiro que indica o tamanho máximo do Heap
 * */
typedef struct Heap {
    Item *v;
    int i, size;
} Heap;

typedef Heap* p_heap;

/**
 * Cria um novo heap
 * 
 * @size: tamanho máximo suportado pelo Heap
 * */
p_heap create_heap(int size);

/** 
 * Libera a memória alocada anteriormente para criação do Heap
 * 
 * @heap: ponteiro para um Heap válido a ser destruído
 * */
void destroy_heap(p_heap heap);

/**
 * Insere um novo Item no Heap
 * 
 * @heap: ponteiro para um Heap válido
 * @i: Item a ser inserido
 * @cmp: ponteiro para uma função de comparação
 * 
 * A organização do Heap se dá pelo retorno da função de comaparação: 
 * Deve retornar 1, se o param 1 tiver maior prioridade que o 2
 * Deve retornar 0, caso contrário.
 * */
void insert_heap(p_heap heap, Item i, int (*cmp)(char*, char*));

/**
 * Retorna o índice do vetor do Heap (tamanho atual)
 * 
 * @heap: ponteiro para um Heap válido
 * 
 * */
int get_index(p_heap heap);

/** 
 * Retorna o Item na raiz no Heap e o remove do mesmo
 * 
 * @heap: ponteiro para um Heap válido
 * @cmp: ponteiro para uma função de comparação
 * 
 * A organização do Heap se dá pelo retorno da função de comaparação: 
 * Deve retornar 1, se o param 1 tiver maior prioridade que o 2
 * Deve retornar 0, caso contrário.
 * */
Item extract_root(p_heap heap, int (*cmp)(char*, char*));

/**
 * Retorna o código do Item na raiz do Heap, sem removê-lo
 * 
 * @heap: ponteiro para um Heap válido
 * */
char* peek_root(p_heap heap);

/**
 * Organiza a prioridade dos nós do Heap, de baixo para cima
 * 
 * @heap: ponteiro para um Heap válido
 * @k: posição de início da subida
 * @cmp: ponteiro para uma função de comparação
 * 
 * A organização do Heap se dá pelo retorno da função de comaparação: 
 * Deve retornar 1, se o param 1 tiver maior prioridade que o 2
 * Deve retornar 0, caso contrário.
 * */
void risein_heap(p_heap heap, int k, int (*cmp)(char*, char*));

/**
 * Organiza a prioridade dos nós do Heap, de cima para baixo
 * 
 * @heap: ponteiro para um Heap válido
 * @k: posição de início da descida
 * @cmp: ponteiro para uma função de comparação
 * 
 * A organização do Heap se dá pelo retorno da função de comaparação: 
 * Deve retornar 1, se o param 1 tiver maior prioridade que o 2
 * Deve retornar 0, caso contrário.
 * */
void fallin_heap(p_heap heap, int k, int (*cmp)(char*, char*));

/**
 * Troca os valores de dois Item's
 * 
 * @a: Item 1
 * @b: Item 2
 * */
void swap(Item* a, Item* b);

#endif

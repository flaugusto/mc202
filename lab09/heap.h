#ifndef HEAP_H
#define HEAP_H

#define MAX_LEN 10

typedef struct {
    char code[MAX_LEN];
    int key;
} Item;

typedef struct {
    Item *v;
    int i, size;
} Heap;

typedef Heap* p_heap;

p_heap create_heap(int size, int* compare_function);

void insert(p_heap h, Item item);

Item extract_max(p_heap h);

int empty(p_heap h);

int full(p_heap h);

/**
 * Retorna 1 se o valor a é menor que b
 * 0 caso contrário.
 * */
int less_than(int a, int b);

/**
 * Retorna 1 se o valor a é maior que b
 * 0 caso contrário.
 * */
int greater_than(int a, int b);


#endif

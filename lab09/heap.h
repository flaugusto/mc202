#ifndef HEAP_H
#define HEAP_H

#define MAX_LEN 10

typedef struct {
    char code[MAX_LEN];
    int key;
} Item;

typedef struct {
    Item *v;
    int *pos;
    int i, size;
} Heap;

typedef Heap* p_heap;

p_heap create_heap(int size, int* compare_function);

void insert(p_heap h, Item item);

Item extract_root(p_heap h);

int empty(p_heap h);

int full(p_heap h);

void swap(int *a, int* b);

void rise()



#endif

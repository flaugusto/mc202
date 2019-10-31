#ifndef HEAP_H
#define HEAP_H

#define MAX_LEN 10

typedef struct {
    char code[MAX_LEN];
} Item;

Item create_item(char* code);

char* get_code(Item item);

void set_code(Item* item, char* code);

typedef struct {
    Item *v;
    int i, size;
} Heap;

typedef Heap* p_heap;

p_heap create_heap(int size, int* compare_function);

void insert_heap(p_heap h, Item item);

int get_size(p_heap h);

Item extract_root(p_heap h);

char* peek_root(p_heap h);

int empty(p_heap h);

int full(p_heap h);

void exchange(int *a, int* b);

void rise(p_heap h, int k);

void fall(p_heap h, int k);

#endif

#ifndef HEAP_H
#define HEAP_H

#define MAX_LEN 10

typedef struct Item{
    char code[MAX_LEN];
} Item;

Item create_item(char* code);

char* get_code(Item some);

typedef struct Heap {
    Item *v;
    int i, size;
} Heap;

typedef Heap* p_heap;

p_heap create_heap(int size);

void destroy_heap(p_heap h);

void insert_heap(p_heap h, Item i, int (*cmp)(char*, char*));

int get_index(p_heap h);

Item extract_root(p_heap h, int (*cmp)(char*, char*));

char* peek_root(p_heap h);

void risein_heap(p_heap h, int k, int (*cmp)(char*, char*));

void fallin_heap(p_heap h, int k, int (*cmp)(char*, char*));

#endif

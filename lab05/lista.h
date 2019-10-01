#ifndef LISTA_H
#define LISTA_H

typedef struct Block {
    int start;
    int size;
} Block;

Block create_block(int start, int size);

int get_size(Block block);

int get_start(Block block);

void set_size(int size, Block* block);

void set_start(int start, Block* block);

typedef struct Node {
    Block data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Node* p_node;

p_node create_list();

p_node push(Block x, p_node list);

p_node pop(Block x, p_node list);

void destroy_list(p_node list);

void print(p_node list);

#endif

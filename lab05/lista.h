#ifndef LISTA_H
#define LISTA_H

typedef struct Block {
    int start;
    int size;
} Block;

Block create_block(int start, int size);

int get_size(Block block);

int get_start(Block block);

void set_size(Block* block, int size);

void set_start(Block* block, int start);

typedef struct Node {
    Block data;
    struct Node* next;
} Node;

typedef struct Node* p_node;

p_node create_list();

p_node insert(p_node list, Block x);

void destroy_list(p_node list);

void print(p_node list);

#endif

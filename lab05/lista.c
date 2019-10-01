#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

Block create_block(int start, int size) {
    Block new_block;
    new_block.size = size;
    new_block.start = start;
    return new_block;
}

int get_size(Block block) {
    return block.size;
}

int get_start(Block block) {
    return block.start;
}

void set_size(int size, Block* block) {
    block->size = size;
}

void set_start(int start, Block* block) {
    block->start = start;
}

p_node create_list() {
    return NULL;
}

p_node push(Block x, p_node list) {
    p_node node;
    node = malloc(sizeof(Node));
    if (node == NULL) {
        printf("Nao ha memoria suficiente!\n");
        exit(1);
    }
    node->data = x;
    node->next = list;
    node->prev = NULL;
    list->prev = node;
    return node;
}

void destroy_list(p_node list) {
    if (list != NULL) {
        destroy_list(list->next);
        free(list);
    }
}

void print(p_node list) {
    if (list != NULL) {
        print(list->next);
        printf("%d ", get_start(list->data));
        printf("%d\n", get_size(list->data));
    }
}

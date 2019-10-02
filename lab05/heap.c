#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

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
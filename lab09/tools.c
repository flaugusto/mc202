#include <string.h>

#include "tools.h"

void swap(Item* a, Item* b) {
    Item tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap_nodes(p_heap min, p_heap max) {

}

int lt(char* a, char* b) {
    return strcmp(a, b) < 0 ? 1 : 0; 
}

int gt(char* a, char* b) {
    return strcmp(a, b) > 0 ? 1 : 0;
}
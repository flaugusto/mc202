#include <string.h>
#include <stdlib.h>
#include "heap.h"

/**
 * Em relação a posição i de um nó do heap, seguem:
 * */
#define FTR(i) ((i-1)/2) // Pai
#define L_SON(i) (2*i+1) // Filho esquerdo
#define R_SON(i) (2*i+2) // Filho direito

Item create_item(char* code) {
    Item new;
    strcpy(new.code, code);
    return new;
}

char* get_code(Item item) {
    return item.code;
}

p_heap create_heap(int size) {
    p_heap new = malloc(sizeof(Heap));
    if (new == NULL) {
        printf("Nao ha memoria suficiente!\n");
        exit(1);
    }
    new->v = malloc(size * sizeof(Item));
    if (new->v == NULL) {
        printf("Nao ha memoria suficiente!\n");
        exit(1);
    }
    new->i = 0;
    new->size = size;
}

void insert_heap(p_heap h, Item item, int (*compare_function)(char* a, char* b)) {
    h->v[h->i] = item;
    h->i++;
    risein_heap(h, compare_function);
}

void risein_heap(p_heap heap, int k, int (*cmp)(char*, char*)) {
    char* father_code = get_code(heap->v[FTR(k)]);
    char* my_code = get_code(heap->v[k]);
    
    if (k > 0 && cmp(father_code, my_code)) {
        swap(&heap->v[k], &heap->v[FTR(k)]);
        risein_heap(heap, FTR(k), cmp);
    }
}

int get_index(p_heap h) {
    return h->i;
}

char* peek_root(p_heap h) {
    return h->v[0].code;
}


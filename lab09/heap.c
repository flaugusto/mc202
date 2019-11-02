#include <string.h>
#include <stdlib.h>
#include <stdio.h>
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
    return new;
}

void insert_heap(p_heap h, Item item, int (*cmp)(char* a, char* b)) {
    h->v[h->i] = item;
    h->i++;
    risein_heap(h, h->i-1, cmp);
}

void risein_heap(p_heap heap, int k, int (*cmp)(char*, char*)) {
    char* father_code = heap->v[FTR(k)].code;
    char* my_code = heap->v[k].code;
    
    if (k > 0 && cmp(father_code, my_code)) {
        swap(&heap->v[k], &heap->v[FTR(k)]);
        risein_heap(heap, FTR(k), cmp);
    }
}

void fallin_heap(p_heap heap, int k, int (*cmp)(char*, char*)) {
    int best_son;

    // Se existir um filho esquerdo, começa chutando que este é o melhor filho
    if (L_SON(k) < heap->i) {
        best_son = L_SON(k);

        // Compara os dois filhos e decide quem é o melhor candaidato a pai
        if (R_SON(k) < heap->i &&
            cmp(heap->v[R_SON(k)].code, heap->v[L_SON(k)].code))
            best_son = R_SON(k);

        // Verifica se o pai deve ser trocado com o filho
        if (cmp(heap->v[best_son].code, heap->v[k].code)) {
            swap(&heap->v[k], &heap->v[best_son]);
            fallin_heap(heap, best_son, cmp);
        }
    }
}

Item extract_root(p_heap h, int (*cmp)(char*, char*)) {
    Item root = h->v[0];
    swap(&h->v[0], &h->v[h->i - 1]);
    h->i--;
    fallin_heap(h, 0, cmp);
    return root;
}

int get_index(p_heap h) {
    return h->i;
}

char* peek_root(p_heap h) {
    return h->v[0].code;
}

void swap(Item* a, Item* b) {
    Item tmp = *a;
    *a = *b;
    *b = tmp;
}

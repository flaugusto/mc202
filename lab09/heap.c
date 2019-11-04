#include "heap.h"

/**
 * Em relação a posição i de um nó do Heap, seguem:
 * */
#define DAD(i) ((i-1)/2) // Pai
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

void destroy_heap(p_heap heap) {
    free(heap->v);
    free(heap);
}

void insert_heap(p_heap heap, Item item, int (*cmp)(char* a, char* b)) {
    heap->v[heap->i] = item;
    heap->i++;
    risein_heap(heap, heap->i - 1, cmp);
}

void risein_heap(p_heap heap, int k, int (*cmp)(char*, char*)) {
    if (k > 0 && cmp(heap->v[k].code, heap->v[DAD(k)].code)) {
        swap(&heap->v[k], &heap->v[DAD(k)]);
        risein_heap(heap, DAD(k), cmp);
    }
}

void fallin_heap(p_heap heap, int k, int (*cmp)(char*, char*)) {
    int best_son;

    // Se existir um filho esquerdo, começa chutando que este é o melhor filho
    if (L_SON(k) < heap->i) {
        best_son = L_SON(k);

        // Compara os dois filhos e decide quem é o melhor candidato a pai
        if (R_SON(k) < heap->i &&
            cmp(heap->v[R_SON(k)].code, heap->v[L_SON(k)].code))
                best_son = R_SON(k);
          
        // Verifica se este melhor filho deve subir no lugar do pai, e desce o pai se verdadeiro
        if (cmp(heap->v[best_son].code, heap->v[k].code)) {
            swap(&heap->v[k], &heap->v[best_son]);
            fallin_heap(heap, best_son, cmp);
        }
    }
}

Item extract_root(p_heap heap, int (*cmp)(char*, char*)) {
    Item root = heap->v[0];
    swap(&heap->v[0], &heap->v[heap->i - 1]);
    heap->i--;
    fallin_heap(heap, 0, cmp);
    return root;
}

int get_index(p_heap heap) {
    return heap->i;
}

char* peek_root(p_heap heap) {
    if (heap->i != 0)
        return heap->v[0].code;
    return "";
}

void swap(Item* a, Item* b) {
    Item tmp = *a;
    *a = *b;
    *b = tmp;
}

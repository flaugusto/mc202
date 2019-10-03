#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

p_node create_list() {
    return NULL;
}

p_node create_node(Block x) {
    p_node new;
    new = malloc(sizeof(Node));
    if (new == NULL) {
        printf("Nao ha memoria suficiente!\n");
        exit(1);
    }
    new->data = x;
    new->prev = NULL;
    new->next = NULL;
    return new;
}
void insert_sorted(Block x, p_node head) {
    p_node new = create_node(x);
    if (head == NULL) {
        head = new;
        return;
    }
    p_node pos = bestfit(x, head);
    2
    3 
    4 * verif se ins fim

    new->next = pos->next; // 1
    new->prev = post; // 2
    pos->next = new // 3
    if (pos->next != NULL) {
        new->next-prev = new // 4
    }
    *pos = new;
    new->next->prev = new;
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

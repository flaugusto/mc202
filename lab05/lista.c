#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

p_node create_list() {
    return NULL;
}

p_node create_node(Block x) {
    p_node new;
    new = (sizeof(Node));
    if (new == NULL) {
        printf("Nao ha memoria suficiente!\n");
        exit(1);
    }
    new->data = x;
    new->prev = NULL;
    new->next = NULL;
    return new;
}


p_node insert_sorted(Block x, p_node head) {
    p_node new = create_node(x);
    if (head == NULL) {
        return new;
    }
    p_node pos = head;

    new->next = pos->next;
    new->prev = pos;
    if (pos->next != NULL) {
        new->next->prev = new;
    }
    pos->next = new;
    return head;
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

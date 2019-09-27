#include <stdlib.h>
#include <stdio.h>

#include "lista.h"

p_node create_list() {
    return NULL;
}

p_node insert(p_node list, Block x) {
    p_node node;
    node = malloc(sizeof(Node));
    if (node == NULL) {
        printf("Nao ha memoria suficiente!\n");
        exit(1);
    }
    node->data = x;
    node->next = list;
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
        printf("heap:\n");
        printf("%d", list->data.start);
        printf("%d", list->data.size);
        print(list->next);
    }
}

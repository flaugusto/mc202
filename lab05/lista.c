#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

p_node create_list() {
    return NULL;
}

p_node* search_insertpos(Block x, p_node* head) {
}

p_node insert(Block x, p_node* head) {
    
    p_node new = create_node(x);
    p_node* pos = search_insertpos(x, head);
    1
    2
    3 
    4 * verif se ins fim
    
    p_node new;
    new = malloc(sizeof(Node));
    if (new == NULL) {
        printf("Nao ha memoria suficiente!\n");
        exit(1);
    }
    new->data = x;
    new->next = *pos;
    if (head == NULL) {
        new->prev = head;
        return new;
    }
    new->prev = (*pos)->prev;
    *pos = new;
    new->next->prev = new;
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

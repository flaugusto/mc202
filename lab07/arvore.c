#include <stdlib.h>
#include "arvore.h"

p_node create_tree(Data v, p_node l, p_node r) {
    p_node root = malloc(sizeof(Node));
    root->value = v;
    root->left = l;
    root->right = r;
    return root;
}


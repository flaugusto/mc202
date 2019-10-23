#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "abb.h"

Data create_data(int key, const char* msg) {
    Data new;
    new.key = key;
    strcpy(new.msg, msg);
    return new;
}

int get_key(Data* data) {
    return data->key;
}

const char* get_msg(const Data* data) {
    return data->msg;
}

p_node create_tree(Data v) {
    p_node root = malloc(sizeof(Node));
    if (root == NULL) {
        printf("Nao ha memoria suficiente!\n");
        exit(1);
    }
    root->value = v;
    root->left = root->right = NULL;
    return root;
}

p_node insert(p_node root, Data value) {
    if (root == NULL) {
        return create_tree(value);
    }
    if (get_key(&value) < get_key(&root->value)) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}
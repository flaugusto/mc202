#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

Data create_data(int x, char chr, int type) {
    Data new;
    new.num = x;
    new.chr = chr;
    new.type = type;
    return new;
}

int get_num(Data data) {
    return data.num;
}

int get_chr(Data data) {
    return data.chr;
}

int get_type(Data data) {
    return data.type;
}

void set_num(Data* data, int x) {
    data->num = x;
    data->type = 0;
    data->chr = EMPTY;
}

p_node create_tree(Data v, p_node l, p_node r) {
    p_node root = malloc(sizeof(Node));
    if (root == NULL) {
        printf("Nao ha memoria suficiente!\n");
        exit(1);
    }
    root->value = v;
    root->left = l;
    root->right = r;
    return root;
}

void destroy_tree(p_node tree) {
    if (tree == NULL) {
        return;
    }
    if (tree->right == NULL && tree->left == NULL) {
        free(tree);
        return;
    }
    destroy_tree(tree->right);
    destroy_tree(tree->left);
    free(tree);
}

int operate(int a, int b, char op) {
   switch (op) {
        case '/':
            return a / b;
            break;
        case '+':
            return a + b;
            break;
        case '*':
            return a * b;
            break;
        case '-':
            return a - b;
            break;
        default:
            return 0;
   }
}

p_node optmize_tree(p_node tree) {
    // É uma folha
    if (tree->left == NULL && tree->right == NULL) {
        return tree;
    }

    // Simplifica as sub-árvores
    tree->left = optmize_tree(tree->left);
    tree->right = optmize_tree(tree->right);

    // Faz a operação das sub-arvores se as duas filhas forem números
    if (get_type(tree->left->value) == 0 &&
        get_type(tree->right->value) == 0) {

        int a = get_num(tree->left->value);
        int b = get_num(tree->right->value);
        char op = get_chr(tree->value);
        set_num(&tree->value, operate(a, b, op));

        free(tree->left);
        free(tree->right);
        tree->left = NULL;
        tree->right = NULL;

        return tree;
    }

    // Se tiver alguma incógnita, já está otimizada
    return tree;
}

int empty_root(p_node tree) {
   if (get_type(tree->value) == -1) {
      return 1;
   } else return 0;
}
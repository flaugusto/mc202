#ifndef ARVORE_H
#define ARVORE_H

/**
 * Define o dato que será guardado em cada nó da arvore
 * num -> valor se for numero
 * chr -> valor se for um caractere (operador ou incógnita)
 * type -> indicador de qual tipo o bloco carrega, 0 pra num, e 1 pra chr
 * */
typedef struct Data {
    int num;
    char chr;
    int type;
} Data;

typedef struct Node {
    Data value;
    struct Node *left, *right;
} Node;

typedef Node * p_node;

p_node create_tree(Data v, p_node l, p_node r);

p_node optmize_tree(p_node root);

#endif

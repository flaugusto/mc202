#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

#define OP_SIZE  32

/**
 * Retorna 1 (true) se o char passado for um dos operadores válidos (+, -, *, /).
 * 0 caso contrário.
 * c -> caractere a ser analisado
 * */
int is_operator(char c);

/**
 * Retorna a raiz da árvore dada preenchida com os dados do buffer do teclado.
 * tree -> raiz da arvore a ser preenchida
 * */
p_node fill_tree(p_node tree);

/** 
 * Exibe uma árvore em inordem no terminal (com parênteses).
 * tree -> raiz de uma arvore binária de expressão
 * */
void print_tree(p_node tree);
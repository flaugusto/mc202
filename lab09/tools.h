#include "heap.h"

/**
 * */
void swap(Item* a, Item* b);

void swap_nodes(p_heap min, p_heap max);

/**
 * Função que compara strings.
 * 
 * @a:     String 1 a ser comparada
 * @b:     String 2 a ser comparada
 * retorno: 1 se a string a é for lexicograficamente menor que b,
 *          0 caso contrário.
 * */
int lt(char* a, char* b);

/**
 * Função que compara strings.
 * 
 * @a:     String 1 a ser comparada
 * @b:     String 2 a ser comparada
 * 
 * retorno:  1 se a string a for lexicograficamente maior que b,
 *          0 caso contrário.
 * */
int gt(char* a, char* b);
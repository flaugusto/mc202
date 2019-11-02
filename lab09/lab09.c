#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "heap.h"

/**
 * Função que compara strings (less than).
 * 
 * @a:      String 1 a ser comparada
 * @b:      String 2 a ser comparada
 * retorno: 1 se a string a é for lexicograficamente menor que b,
 *          0 caso contrário.
 * */
int lt(char* a, char* b);

/**
 * Função que compara strings (greater than).
 * 
 * @a:      String 1 a ser comparada
 * @b:      String 2 a ser comparada
 * 
 * retorno:  1 se a string a for lexicograficamente maior que b,
 *          0 caso contrário.
 * */
int gt(char* a, char* b);

int main() {
    int n, m;
    char code[5];

    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &m);
        p_heap max = create_heap(m);
        p_heap min = create_heap(m);

        for (int j = 0; j < m; j++) {
            scanf(" %s", code);

            if (get_index(max) < get_index(min))
                insert_heap(max, create_item(code), gt);
            else
                insert_heap(min, create_item(code), lt);

            while (gt(peek_root(max), peek_root(min))) {
                // Troca nós entre os os dois heaps
                printf("passei aqui");
                insert_heap(max, extract_root(min, lt), gt);
                insert_heap(min, extract_root(max, gt), lt);
            }
        }
        if (get_index(max) == get_index(min))
            printf("%s %s\n", peek_root(max), peek_root(min));
        else 
            printf("%s", peek_root(min));
    }

    return EXIT_SUCCESS;
}

int lt(char* a, char* b) {
    return strcmp(a, b) < 0 ? 1 : 0;
}

int gt(char* a, char* b) {
    return strcmp(a, b) > 0 ? 1 : 0;
}
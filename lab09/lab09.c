#include "heap.h"

/**
 * Função que compara strings (less than).
 * 
 * @a:      String 1 a ser comparada
 * @b:      String 2 a ser comparada
 * 
 * retorno: 1 se a string a for lexicograficamente menor que b,
 *          0 caso contrário.
 * */
int lt(char* a, char* b);

/**
 * Função que compara strings (greater than).
 * 
 * @a:      String 1 a ser comparada
 * @b:      String 2 a ser comparada
 * 
 * retorno: 1 se a string a for lexicograficamente maior que b,
 *          0 caso contrário.
 * */
int gt(char* a, char* b);

/**
 * Imprime a mediana baseada nos heaps de maximo e minimo
 * 
 * @max: ponteiro para um heap de máximo
 * @min: ponteiro para um heap de minimo
 * @group: número indicador do grupo de códigos
 * */
void print_m(p_heap max, p_heap min, int group);

int main() {
    int n, m;
    char code[MAX_LEN];

    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &m);
        p_heap max = create_heap(m);
        p_heap min = create_heap(m);

        int j = 0;
        for (; j < m; j++) {
            scanf(" %s", code);

            if (get_index(max) < get_index(min))
                insert_heap(max, create_item(code), gt);
            else
                insert_heap(min, create_item(code), lt);

            while (gt(peek_root(max), peek_root(min))) {
                // Troca nós entre os dois heaps
                insert_heap(max, extract_root(min, lt), gt);
                insert_heap(min, extract_root(max, gt), lt);
            }
            // A cada 5 códigos, exibe a mediana
            if (j != 0 && (j + 1) % 5 == 0) {
                print_m(max, min, i + 1);
            }
        }
        // Exibe a mediana final (se já não tiver sido)
        if (j % 5 != 0)
            print_m(max, min, i + 1);

        destroy_heap(min);
        destroy_heap(max);
    }

    return EXIT_SUCCESS;
}

int lt(char* a, char* b) {
    return strcmp(a, b) < 0 ? 1 : 0;
}

int gt(char* a, char* b) {
    return strcmp(a, b) > 0 ? 1 : 0;
}

void print_m(p_heap max, p_heap min, int group) {
    if (get_index(max) == get_index(min))
        printf("%d %s %s\n", group, peek_root(max), peek_root(min));
    else 
        printf("%d %s\n", group, peek_root(min));
}

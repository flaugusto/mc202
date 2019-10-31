#include <stdlib.h>
#include <stdio.h>

#include "heap.h"

/**
 * Retorna 1 se o valor a é menor que b
 * 0 caso contrário.
 * */
int less_than(char* a, char* b);

/**
 * Retorna 1 se o valor a é maior que b
 * 0 caso contrário.
 * */
int greater_than(char* a, char* b);

void swap_nodes(p_heap a, p_heap b);


int main()
{
   int n, m;
   char code[10];

   scanf("%d", &n);

   for (int i = 0; i < n; ++i) {

      scanf("%d", &m);
      for (int j = 0; j < m; j++) {
         scanf(" %s", code);
         p_heap max = create_heap(m, greater_than);
         p_heap min = create_heap(m, less_than);
         if (get_size(max) < get_size(min)) {
            insert_heap(max, create_item(code));
         } else {
            insert_heap(min, create_item(code));
         }
         while (peek_root(max) > peek_root(min)) {
            swap_nodes(min, max);
         }

      }
      


   }

   return EXIT_SUCCESS;

}

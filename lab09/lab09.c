#include <stdlib.h>
#include <stdio.h>

#include "heap.h"
#include "tools.h"

int main()
{
   int n, m;
   char code[10];

   scanf("%d", &n);

   for (int i = 0; i < n; ++i) {

      scanf("%d", &m);
      for (int j = 0; j < m; j++) {
         scanf(" %s", code);
         p_heap max = create_heap(m);
         p_heap min = create_heap(m);
         if (get_index(max) < get_index(min)) {
            insert_heap(max, create_item(code), gt);
         } else {
            insert_heap(min, create_item(code), lt);
         }
         while (peek_root(max) > peek_root(min)) {
            swap_nodes(min, max);
         }
      }
   }

   return EXIT_SUCCESS;

}

#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

#define ALLOC     'A'
#define FREE      'D'
#define REALLOC   'R'
#define PRINT     'P'

int main()
{
   int m, n;

   scanf("%d %d", &m, &n);
   // p_node heap;
   char op;
   int a_size, r_size, start, i;
   for (i = 0; i < m; i++) {
      scanf(" %c", &op);
      switch (op) {
         case ALLOC:
            scanf(" %d", &a_size);
            // TODO allocate
            printf("alloc: %d\n", a_size);
            break;
         case FREE:
            scanf(" %d%d", &start, &a_size);
            // TODO free block
            printf("free: %d, %d\n", start, a_size);
            break;
         case REALLOC:
            scanf(" %d%d%d", &start, &a_size, &r_size);
            //TODO reallocate
            printf("realloc: %d, %d, %d\n", start, a_size, r_size);
            break;
         case PRINT:
            printf("heap:\n");
            // print(heap);
            break;
      }
      
   }
   return EXIT_SUCCESS;
}

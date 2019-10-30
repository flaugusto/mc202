#include <stdlib.h>
#include <stdio.h>

// #include "heap.h"]

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


int main()
{
   int n, m;
   char code[10];

   scanf("%d", &n);

   for (int i = 0; i < n; ++i) {

      scanf("%d", &m);
      for (int j = 0; j < m; j++) {
         scanf(" %s", code);
         printf("%s\n", code);
      }
      


   }

   return EXIT_SUCCESS;

}

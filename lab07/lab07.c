#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvore.h"

// p_node fill_tree(Data v) {

// }

int main() {
   int m, num;
   char buffer[100];
   scanf("%d", &m);
   
   for (int i = 0; i < m; i++)
   {
      do {
         scanf(" %s", buffer);
         if (buffer[0] == '(') {
            //Inicio de expressão

         }
         else if (buffer[0] >= '0' && buffer[0] <= '9') {
            // Número
            num = atoi(buffer);
         }
         else  {
            // Incógnita
         }
      } while (getchar() != '\n');
   }
   
   
      
   
   return EXIT_SUCCESS;
}

#include <stdio.h>
#include "io.h"
#include "arvore.h"

int main() {
   int m;
   char buffer[OP_SIZE];
   
   scanf("%d", &m);
   
   for (int i = 0; i < m; i++)
   {
      scanf(" %s", buffer);
      if (buffer[0] == '(') {
         // Inicio de expressão
         p_node root = create_tree(create_data(0, EMPTY, -1), NULL, NULL);
         root = fill_tree(root);
         root = optmize_tree(root);
         print_tree(root);
         destroy_tree(root);
      }
      printf("\n");
   }
   return EXIT_SUCCESS;
}

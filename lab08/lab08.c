#include <stdio.h>
#include <stdlib.h>

#include "abb.h"

/**
 * Une todos os pacotes da árvore e exibe na tela.
 * tree - aŕvore binária de busca com os pacotes lidos
 * */
void join_msg(p_node tree) {
   if (tree == NULL) 
      return;
   if (tree->right == NULL && tree->left == NULL) {
      printf("%s", get_msg(&tree->value));
      return;
   }
   join_msg(tree->left);
   printf("%s", get_msg(&tree->value));
   join_msg(tree->right);
}

int main() {

   int id;
   char pkg[PKG_SIZE];

   p_node tree = NULL;
   do {
      scanf(" %d", &id);
      if (id != 0) {
         getchar();
         scanf("%[^\n]", pkg);
         tree = insert(tree, create_data(id, pkg));
      }
   } while (id != 0);

   join_msg(tree);
   printf("\n");
   destroy_tree(tree);

   return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>

#include "abb.h"

void join_msg(p_node tree) {
   if (tree == NULL) 
      return;
   if (tree->right == NULL && tree->left == NULL) {
      printf("%d ", get_key(&tree->value));
      return;
   }
   join_msg(tree->left);
   printf("%d ", get_key(&tree->value));
   join_msg(tree->right);
}


int main() {

   int id;
   char pkg[PKG_SIZE];

   p_node root;
   do {
      scanf(" %d", &id);
      if (id != 0)
         scanf(" %[^\n]", pkg);
      // printf("%d ", id); /* remove before submit */
      
      root = insert(root, create_data(id, pkg));
      
   } while (id != 0);

   join_msg(root);


   return EXIT_SUCCESS;
}

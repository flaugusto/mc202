#include "io.h"

#define OPEN      '('
#define CLOSE     ')'

int is_operator(char c) {
   switch (c) {
      case '/':
         return 1;
         break;
      case '+':
         return 1;
         break;
      case '*':
         return 1;
         break;
      case '-':
         return 1;
         break;
      default:
         return 0;
         break;
   }
}

p_node fill_tree(p_node tree) {
   int num;
   char buffer[OP_SIZE];
   scanf(" %s", buffer);

   while (buffer[0] != CLOSE) {
      // Número
      if ((buffer[0] >= '0' && buffer[0] <= '9') ||
          (buffer[0] == '-' && (buffer[1] >= '0' && buffer[1] <= '9'))) {

         num = atoi(buffer);
         Data value = create_data(num, EMPTY, 0);
         // Decide qual dos filhos o novo dado vai ser inserido
         if (empty_root(tree)) {
            tree->left = create_tree(value, NULL, NULL);
         } else {
            tree->right = create_tree(value, NULL, NULL);
         }
      } 
      
      else if (is_operator(buffer[0])) {
         tree->value = create_data(0, buffer[0], 1);
      }

      // Se leu uma sub-expressão, cria um sub-árvore
      else if (buffer[0] == OPEN) {
         p_node son = create_tree(create_data(0, EMPTY, -1), NULL, NULL);
         // Decide em qual dos filhos a nova sub-arvore vai ser inserida
         if (empty_root(tree)) {
            tree->left = fill_tree(son);
         } else {
            tree->right = fill_tree(son);
         }
      } 
      
      else {
         // Incógnita
         Data value = create_data(0, buffer[0], 1);
         // Decide qual dos filhos o novo dado vai ser inserido
         if (empty_root(tree)) {
            tree->left = create_tree(value, NULL, NULL);
         } else {
            tree->right = create_tree(value, NULL, NULL);
         }
      }
      
      scanf(" %s", buffer);
   }
   return tree;
}

void print_tree(p_node tree) {
    if (tree != NULL) {
        // Folha
        if (tree->right == NULL && tree->left == NULL) {
            if (get_type(tree->value) == 0) {
                printf("%d ", get_num(tree->value));
            } else {
                printf("%c ", get_chr(tree->value));
            }
            return;
        }
        // Geral
        printf("( ");
        print_tree(tree->left);
        printf("%c ", get_chr(tree->value));
        print_tree(tree->right);
        printf(") ");
    }
}
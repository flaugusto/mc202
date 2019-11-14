#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

int main()
{
   int n;
   char *pattern, *text;

   scanf("%d", &n);

   for (int i = 0; i < n; i++) {
      int m = scanf(" %ms", &pattern);
      if (m == 1) {
         printf("read: %s\n", pattern);
         free(pattern);
      }
   }
   
   scanf(" %ms", &text);
   printf("text: %s\n", text);
   free(text);



   return EXIT_SUCCESS;

}

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

   int block = 20;
   char* part = malloc((block + 1) * sizeof(char));

   for (int i = 0; i <= strlen(text) - block; i++) {
      int j = 0;
      for (; j < block; j++)
         part[j] = text[i + j];
      part[j] = '\0';
         
      printf("%s\n", part);
   }

   free(part);
   free(text);



   return EXIT_SUCCESS;

}

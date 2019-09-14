#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

int main()
{
   int m, n;

   scanf("%d %d", &m, &n);

   char** lab = criar_mapa(m, n);
   ler_mapa(lab, m, n);
   imprime_mapa(lab, m);

   return EXIT_SUCCESS;
}

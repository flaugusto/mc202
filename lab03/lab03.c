#include <stdio.h>
#include <stdlib.h>
#include "livro.h"
#include "leitor.h"

Leitor* le_leitores(Leitor* leitores, int n) 
{
   char nome[MAXCHAR_LNOME];
   int e, id;
   for (int i = 0; i < n; i++)
   {
      scanf(" %s %d ", nome, &e);
      Leitor novo = criar_leitor(nome, e);
      for (int j = 0; j < e; j++)
      {
         scanf("%d ", &id);
         // Empréstimo
         if (id < 0) {
            id = id * (-1);
            registrar_restituicao(&novo, id);
         } else registrar_devolucao(&novo, id);
      }      
   }
   
   
   
}

int main()
{
   char titulo[MAXCHAR_TITULO]; // string para a leitura do título
   char nome[MAXCHAR_LNOME];    // string para a leitura do nome

   Livro* livros = NULL;        // ponteiro para o vetor de livros
   Leitor* leitores = NULL;     // ponteiro para o vetor de leitores
   
   int m,n;
   scanf("%d %d ", &m, &n);





   free(livros);
   free(leitores);

   return 0;
}

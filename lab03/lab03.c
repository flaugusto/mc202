#include <stdio.h>
#include <stdlib.h>
#include "livro.h"
#include "leitor.h"

/**
 * Esta função lê do teclado e cadastra os leitores ativos
*/
void le_leitores(Leitor* lista, int len) 
{
   char nome[MAXCHAR_LNOME]; // string para a leitura do nome
   int e, id;

   for (int i = 0; i < len; i++)
   {
      scanf(" %s %d", nome, &e);
      Leitor novo = criar_leitor(nome, e);
      for (int j = 0; j < e; j++)
      {
         scanf("%d", &id);
         // Leitor deixou para empréstimo
         if (id < 0) {
            registrar_restituicao(&novo, id);
         // Leitor pegou emprestado
         } else registrar_devolucao(&novo, id);
      }
      lista[i] = novo;
   }
}

/**
 * Função que faz a leitura completa dos livros
 * */
void le_livros(Livro* lista, int len) 
{
   for (int i = 0; i < len; i++) 
   {
      // Lê a data do empréstimo no começo da linha
      int dia, mes, ano;
      scanf("%d-%d-%d", &dia, &mes, &ano);
      Data emp = criar_data(dia, mes, ano);

      // Leitura do título do livro
      char titulo[MAXCHAR_TITULO]; // string para a leitura do título
      scanf(" %[^\n]", titulo);
      Livro novo = criar_livro(titulo, emp);
      lista[i] = novo;
   }
}

int main()
{
   Livro* livros = NULL;        // ponteiro para o vetor de livros
   Leitor* leitores = NULL;     // ponteiro para o vetor de leitores
   
   int m,n;
   scanf(" %d %d", &m, &n);     // Leitura dos números iniciais

   livros = malloc(m * sizeof(Livro));
   leitores = malloc(n * sizeof(Leitor));

   le_livros(livros, m);
   le_leitores(leitores, n);

   // Leitura da data da consulta
   int dia, mes, ano;
   scanf("%d-%d-%d", &dia, &mes, &ano);
   Data consulta = criar_data(dia, mes, ano);

   for (int x = 0; x < n; x++)
   {
      printf("Leitor: %s\n", obter_nome(&leitores[x]));
      printf("Res: %d\n", obter_num_restituicoes(&leitores[x]));
      printf("Devs: %d\n", obter_num_devolucoes(&leitores[x]));
   }
   printf("Consulta: %d-%d-%d", consulta.dia, consulta.mes, consulta.ano);

   for (int i = 0; i < n; i++) 
   {
      desalocar_memoria(&leitores[i]);
   }
   free(livros);
   free(leitores);

   return 0;
}

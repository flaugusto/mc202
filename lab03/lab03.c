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
         scanf(" %d", &id);
         // Leitor pegou emprestado
         if (id < 0) {
            id *= -1;
            registrar_devolucao(&novo, id);
         // Leitor deixou para empréstimo
         } else registrar_restituicao(&novo, id);
      }
      lista[i] = novo;
   }
}

/**
 * Função que faz a leitura completa dos livros
 * */
void le_livros(Livro* lista, int len) 
{
   for (int i = 1; i < len; i++) 
   {
      // Lê a data do empréstimo no começo da linha
      int dia, mes, ano;
      scanf("%d-%d-%d", &dia, &mes, &ano);

      // Leitura do título do livro
      char titulo[MAXCHAR_TITULO]; // string para a leitura do título
      scanf(" %[^\n]", titulo);
      lista[i] = criar_livro(titulo, criar_data(dia, mes, ano));
   }
}

int main()
{
   Livro* livros = NULL;        // ponteiro para o vetor de livros
   Leitor* leitores = NULL;     // ponteiro para o vetor de leitores
   
   int m,n;
   scanf(" %d %d", &m, &n);     // Leitura dos números iniciais
   // Soma mais um no número máximo pelo índice de livros começar em 1
   m++;

   livros = malloc(m * sizeof(Livro));
   leitores = malloc(n * sizeof(Leitor));

   le_livros(livros, m);
   le_leitores(leitores, n);

   // Leitura da data da consulta
   int dia, mes, ano;
   scanf("%d-%d-%d", &dia, &mes, &ano);
   Data consulta = criar_data(dia, mes, ano);

   /**
    * Processamento e exibição das descrições
    */
   for (int x = 0; x < n; x++)
   {
      // Nome do leitor
      printf("%s\n", obter_nome(&leitores[x]));

      // Exibe os livros a serem restituídos
      int len = obter_num_restituicoes(&leitores[x]);
      const int* res = obter_restituicoes(&leitores[x]);
      for (int i = 0; i < len; i++)
      {  
         Data emp_livro = obter_data_emprestimo(&livros[res[i]]);
         if (eh_menor_que(emp_livro, consulta) &&
            !eh_nula(emp_livro)) {
            printf("Restituição: %s\n", obter_titulo(&livros[res[i]]));
         }
         
      }
      // Exibe os livros a serem devolvidos
      len = obter_num_devolucoes(&leitores[x]);
      const int* dev = obter_devolucoes(&leitores[x]);
      for (int i = 0; i < len; i++)
      {  
         Data emp_livro = obter_data_emprestimo(&livros[dev[i]]);
         if (eh_menor_que(emp_livro, consulta) &&
            !eh_nula(emp_livro)) {
            printf("Devolução: %s\n", obter_titulo(&livros[dev[i]]));
         }
      }
   }
 
   for (int i = 0; i < n; i++) 
   {
      desalocar_memoria(&leitores[i]);
   }
   free(livros);
   free(leitores);

   return 0;
}

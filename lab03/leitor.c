#include <stdlib.h>
#include <string.h>
#include "leitor.h"

Leitor criar_leitor(const char* nome, int e)
{
   Leitor novo;
   strcpy(novo.nome, nome);
   novo.restituicoes = malloc(e * sizeof(int));
   novo.devolucoes = malloc(e * sizeof(int));
   novo.num_devolucoes = 0;
   novo.num_restituicoes = 0;
   return novo;
}

void desalocar_memoria(Leitor* leitor)
{
    free(leitor->restituicoes);
    free(leitor->devolucoes);
}

const char* obter_nome(const Leitor* leitor)
{
   return leitor->nome;
}

void registrar_restituicao(Leitor* leitor, int i)
{
   int len = leitor->num_restituicoes;
   leitor->restituicoes[len] = i;
   leitor->num_restituicoes++; 
}

void registrar_devolucao(Leitor* leitor, int i)
{
   int len = leitor->num_devolucoes;
   leitor->devolucoes[len] = i;
   leitor->num_devolucoes++;
}

const int* obter_restituicoes(const Leitor* leitor)
{
   return leitor->restituicoes;
}

const int* obter_devolucoes(const Leitor* leitor)
{
   return leitor->devolucoes;
}

int obter_num_restituicoes(const Leitor* leitor)
{
   return leitor->num_restituicoes;
}

int obter_num_devolucoes(const Leitor* leitor)
{
   return leitor->num_devolucoes;
}

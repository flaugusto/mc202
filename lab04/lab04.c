#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

/** Função recursiva que acha um caminho até algo
 * oq -> Char que se deve procurar por
 * onde -> o mapa do labirinto pra procurar
 * i -> posição na linha que está
 * j -> ''      na coluna ''
 * marcador -> a migalha de pão que deve ser deixada para invalidar o caminho já visitado
 * *x -> ponteiro para retornar a posição da linha do item achado
 * *y -> ''       ''    ''       ''       da coluna   ''
 * */
int achar(char oq, char** onde, int i, int j, char marcador, int *x, int *y) {
   int dir = j + 1;
   int bai = i + 1;
   int esq = j - 1;
   int cim = i - 1;

   /** Casos base
    * Se achou o que queria, retorna VERDADEIRO
    * Se não achou, retorna FALSO
    * */
   if (i < 0 || j < 0)
      return 0;
   else if (onde[i][j] == oq) {
      *x = i;
      *y = j;
      return 1;
   } else if (onde[i][j] == marcador)
      return 0;
   else if (onde[i][j] == PAREDE)
      return 0;
   else if (onde[i][j] == ENT)
      return 0;
   else if (onde[i][j] == SOL_P)
      return 0;
   else if (onde[i][j] == MINOTAURO)
      return 0;
   else if (onde[i][j] == ESPADA)
      return 0;
   

   /** Caso geral
    * Tenta achar nas direções seguindo a ordem
    * Se não achar em nenhuma delas, marca que já passou e retorna FALSO
    * */
   if (onde[i][j] == SOL)
      onde[i][j] = SOL_P;
   else onde[i][j] = marcador;
   // Direita
   if (achar(oq, onde, i, dir, marcador, x, y)) {
      onde[i][j] = SOL;
      return 1;
   // Baixo
   } else if (achar(oq, onde, bai, j, marcador, x, y)) {
      onde[i][j] = SOL;
      return 1;
   // Esquerda
   } else if (achar(oq, onde, i, esq, marcador, x, y)) {
      onde[i][j] = SOL;
      return 1;
   // Cima
   } else if (achar(oq, onde, cim, j, marcador, x, y)) {
      onde[i][j] = SOL;
      return 1;
   } else 
      return 0;
}

int main() {
   // Leitura do tamanho
   int m, n;
   scanf("%d %d", &m, &n);

   // Cria o mapa do labirinto
   char** lab = criar_mapa(m, n);      
   ler_mapa(lab, m);

   // Acha a entrada
   int e;
   for (int i = 0; i < n; i++) {
      if (lab[0][i] == ENT)
         e = i;
   }

   // Variáveis para guardar a posição e o caminho da espada
   int x, y;                           
/*    int* passei = malloc((m - 1) * (n -1) * sizeof(int));
   if (passei == NULL) {
      printf("Nao ha memoria suficiente!\n");
      exit(1);      
   } */
   // Tenta achar recursivamente a espada
   if (!achar(ESPADA, lab, 1, e, M_ESP, &x, &y))
      return 1; // Não achou
      
   // Tenta achar recursivamente o minotauro
   if (
      // Direita
      !achar(MINOTAURO, lab, x, y + 1, M_MIN, &x, &y) &&
      // Baixo
      !achar(MINOTAURO, lab, x + 1, y, M_MIN, &x, &y) &&
      // Esquerda
      !achar(MINOTAURO, lab, x, y - 1, M_MIN, &x, &y) &&
      // Cima
      !achar(MINOTAURO, lab, x - 1, y, M_MIN, &x, &y)
      )
         return 1; // Não achou
   
   // Preparação da saída e exibição
   limpar_mapa(lab, m, n, M_ESP, M_MIN, SOL_P);
   imprimir_mapa(lab, m);

   // Liberação dos vetores
   desalocar_mapa(lab, m);
   // free(passei);

   return EXIT_SUCCESS;
}

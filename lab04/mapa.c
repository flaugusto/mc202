#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

char** criar_mapa(int m, int n) {
    char** mapa;
    mapa = malloc(m * sizeof(char *));
    for (int i = 0; i < m; i++) {
        mapa[i] = malloc(n + 1 * sizeof(char));
    }
    return mapa;
}

void ler_mapa(char** mapa, int m, int n) {
    // Leitura do mapa
   for (int i = 0; i < m; i++) {
      fgets(mapa[i], n, stdin);
   }
}

void imprime_mapa(const char** mapa, int m) {
    // Impressão do mapa
    for (int i = 0; i < m; i++) {
      printf("%s", mapa[i]);
   }
}

void desalocar_mapa(char** mapa, int m){
    for (int i = 0; i < m; i++) {
        free(mapa[i]);
    }
    free(mapa);
}
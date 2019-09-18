#include <stdlib.h>
#include <stdio.h>
#include "mapa.h"

char** criar_mapa(int m, int n) {
    char** mapa;
    mapa = malloc(m * sizeof(char *));
    if (mapa == NULL) {
        printf("Nao ha memoria suficiente!\n");
        exit(1);
    }
    for (int i = 0; i < m; i++) {
        mapa[i] = malloc(n + 1 * sizeof(char));
        if (mapa[i] == NULL) {
            printf("Nao ha memoria suficiente!\n");
            exit(1);
        }
    }
    return mapa;
}

void ler_mapa(char** mapa, int m) {
   for (int i = 0; i < m; i++) {
      scanf(" %[^\n]", mapa[i]);
   }
}

void imprimir_mapa(char** mapa, int m) {
    for (int i = 0; i < m; i++) {
      printf("%s\n", mapa[i]);
   }
}

void limpar_mapa(char** mapa, int m, int n, char m_esp, char m_min, char m_parcial) {
    for (int i = 1; i < m - 1; i++)
        for (int j = 1; j < n - 1; j++)
            if (mapa[i][j] == m_esp || mapa[i][j] == m_min)
                mapa[i][j] = ' ';
            else if (mapa[i][j] == m_parcial) {
                mapa[i][j] = SOL;
            }
}

void desalocar_mapa(char** mapa, int m){
    for (int i = 0; i < m; i++) {
        free(mapa[i]);
    }
    free(mapa);
}
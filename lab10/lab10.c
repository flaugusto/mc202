#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

/**
 * Função: Está no vetor
 * 
 * Retorna 1 se acha x no vetor v
 * ou 0 se falso.
 * 
 * @x: numero a ser procurado
 * @v: vetor de inteiros
 * @size: tamanho do vetor
 * */
int in_arr(int x, int *v, int size);

/**
 * Função: Exibe vetor
 * 
 * Exibe os elementos de um vetor simples de inteiros na tela
 * 
 * @arr: vetor
 * @n: tamanho do vetor
 * */
void print_arr(int* arr, int n);

int main()
{
    int n;
    char *pattern, *text;

    scanf("%d", &n);

    /* Contador do número de ocorrências */
    int *counter = malloc(n * sizeof(int));
    if (counter == NULL)
    {
        printf("Nao ha memoria suficiente!\n");
        exit(1);
    }

    /** 
     * A fim de fazer menos pesquisas na tabela, 
     * cria um vetor para guardar tamanhos distintos.
     * */
    int *sizes = malloc(n * sizeof(int));
    if (sizes == NULL)
    {
        printf("Nao ha memoria suficiente!\n");
        exit(1);
    }
    int s_size = 0;

    p_ht table = new_hash_table(n);

    for (int i = 0; i < n; i++)
    {
        scanf(" %ms", &pattern);
        ht_insert(table, pattern, i);
        counter[i] = 0;

        // Guarda os tamanhos
        int len = strlen(pattern);
        if (!in_arr(len, sizes, s_size))
        {
            sizes[s_size] = len;
            s_size++;
        }

        free(pattern);
    }

    scanf(" %ms", &text);

    /* Divide o texto em partes e procura as partes na tabela */
    int block;
    for (int x = 0; x < s_size; x++) /* para cada tamanho */
    {
        /* Cria um vetor para guardar a parte do texto */
        block = sizes[x];
        char *part = malloc((block + 1) * sizeof(char));
        if (part == NULL)
        {
            printf("Nao ha memoria suficiente!\n");
            exit(1);
        }

        /* Testa todos os subpadrões do tamanho do bloco */
        int txt_len = strlen(text);
        for (int i = 0; i <= txt_len - block; i++) /* para cada char no texto */
        {
            /* Monta uma parte do tamanho do bloco */
            int j = 0;
            for (; j < block; j++)
                part[j] = text[i + j];
            part[j] = '\0';

            int value = ht_search(table, part);
            if (value != -1)
                counter[value]++;
        }
        
        free(part);
    }

    /* Exibe o número de ocorrências para cada padrão */
    print_arr(counter, n);
    
    free(text);
    free(sizes);
    free(counter);
    ht_destroy(table);

    return EXIT_SUCCESS;
}

int in_arr(int x, int *v, int size)
{
    for (int i = 0; i < size; i++)
        if (x == v[i])
            return 1;
    return 0;
}

void print_arr(int* arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d\n", arr[i]);
}
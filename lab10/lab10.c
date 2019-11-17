#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

/**
 * Retorna 1 se acha x no vetor v
 * ou 0 se falso.
 * */
int in_arr(int x, int *v, int size);

void printArr(Item **arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("v[%d]: ", i);
        if (arr[i])
            printf("{%s: %d}\n", arr[i]->key, arr[i]->value);
        else
            printf("NULL\n");
    }
}

int main()
{
    int n;
    char *pattern, *text;

    scanf("%d", &n);

    /* Afim de fazer menos pesquisas, cria um vetor para guardar tamanhos distintos */
    int *sizes = malloc(n * sizeof(int));
    // TODO if NULL
    int s_size = 0;
    p_ht table = new_hash_table(n);

    for (int i = 0; i < n; i++)
    {
        scanf(" %ms", &pattern);
        // printf("read: %s, hash: %d\n", pattern, hash(pattern, table->size));
        ht_insert(table, pattern, i);

        int len = strlen(pattern);
        if (!in_arr(len, sizes, s_size))
        {
            sizes[s_size] = len;
            s_size++;
        }
        free(pattern);
    }

    scanf(" %ms", &text);

    //TODO remove this code (for tests only)
    /* for (int j = 0; j < n; j++) {
        // printf("Procurar padrões.\n");
        scanf(" %ms", &pattern);

        int value = ht_search(table, pattern);
        if (value != -1)
            printf("key: %s, value: %d\n", pattern, value);
        else printf("não achou\n");

        free(pattern);
    } */

    // printf("text: %s\n", text);
    printArr(table->set, table->size);

    /** Divide o texto em partes e procura as partes na tabela */
    int *counter = malloc(n * sizeof(int));
    if (counter == NULL)
    {
        printf("Nao ha memoria suficiente!\n");
        exit(1);
    }
    int block;
    for (int x = 0; x < s_size; x++)
    {
        block = sizes[x];
        char *part = malloc((block + 1) * sizeof(char));
        if (part == NULL)
        {
            printf("Nao ha memoria suficiente!\n");
            exit(1);
        }

        for (int i = 0; i <= strlen(text) - block; i++)
        {
            int j = 0;
            for (; j < block; j++)
                part[j] = text[i + j];
            part[j] = '\0';

            // printf("%s\n", part);
        }

        free(part);
        // printf("-----------------------\n");
    }

    free(text);
    free(sizes);
    ht_destroy(table);
    // free(counter);

    return EXIT_SUCCESS;
}

int in_arr(int x, int *v, int size)
{
    for (int i = 0; i < size; i++)
        if (x == v[i])
            return 1;
    return 0;
}

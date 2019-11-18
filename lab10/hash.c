#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "hash.h"

int is_prime(int n);
int next_prime(int n);
int hash(char *key, int m);

p_item new_item(char *key, int value)
{
    p_item new;
    new = malloc(sizeof(Item));
    if (new == NULL)
    {
        printf("Nao ha memoria suficiente!\n");
        exit(1);
    }
    strcpy(new->key, key);
    new->value = value;
    return new;
}

p_ht new_hash_table(int size)
{
    /**
     * Encontra um tamanho para a tabela baseado no número de chaves (n)
     * Regra usada: o próximo primo maior ou igual que 2 * n.
     * */
    p_ht new;
    int m = next_prime((size * 2));
    new = malloc(sizeof(HashTable));
    if (new == NULL)
    {
        printf("Nao ha memoria suficiente!\n");
        exit(1);
    }
    new->set = malloc(m * sizeof(p_item));
    if (new->set == NULL)
    {
        printf("Nao ha memoria suficiente!\n");
        exit(1);
    }
    for (int i = 0; i < m; i++)
        new->set[i] = NULL;

    new->size = m;
    return new;
}

void ht_destroy(p_ht table)
{
    for (int i = 0; i < table->size; i++)
        if (table->set[i])
            free(table->set[i]);

    free(table->set);
    free(table);
}

void ht_insert(p_ht table, char *key, int value)
{
    int pos = hash(key, table->size);
    while (table->set[pos])
        pos = (pos + 1) % table->size;
    
    table->set[pos] = new_item(key, value);
}

int ht_search(p_ht table, char *key)
{
    int pos = hash(key, table->size);
    int start = pos;

    while (table->set[pos])
    {
        p_item row = table->set[pos];
        if (strcmp(row->key, key) == 0)
            return row->value;
        pos = (pos + 1) % table->size;
        if (pos == start)
            return -1;
    }
    return -1;
}

/*************** Funções auxiliares ao TAD *******************
 *
 * As funções a seguir não devem ser utilizadas pelo cliente,
 * servem apenas para auxiliar na implementação da HashTable.
 * 
 * */

/**
 * Função de hash para strings
 * 
 * Implementação retirada de link externo
 * Referencia: https://visualgo.net/en/hashtable?slide=4-7
 * 
 * @key: uma chave para calcular o hash
 * @m: tamanho da tabela de hashing
 * 
 * */
int hash(char *key, int m)
{
    long int x = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        char c = key[i];
        x = ((x * 26) % m + (c - 'A' + 1)) % m;
    }
    return x;
}

/**
 * Função que acha o próximo número primo
 * 
 * Retorna um número primo maior ou igual ao n dado
 * */
int next_prime(int n)
{
    for (int i = n; i < 2 * n; ++i)
        if (is_prime(i))
            return i;
    return -1;
}

/**
 * Função que diz se um número é primo
 * 
 * Retorna 1 se um número é primo ou 0 se falso.
 * */
int is_prime(int n)
{
    if (n <= 1)
        return 0;

    // Bertrand's postulate (teorema pra achar primos)
    // Ref: https://en.wikipedia.org/wiki/Bertrand%27s_postulate
    for (int j = 2; j <= n / 2; j++)
        if ((n % j) == 0)
            return 0;
    return 1;
}
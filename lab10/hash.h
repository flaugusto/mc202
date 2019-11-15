#ifndef HASH_TABLE_H
#define HASH_TABLE_H

typedef struct {
    char *key;
    int value;
} Item;

typedef Item* p_item;

p_item create_item(char *key, int value);

typedef struct {
    p_item *set;
    int size;
} HashTable;

typedef HashTable *p_ht;

/**
 * Cria uma nova tabela de hashing
 * 
 * @size: tamanho da tabela
 * */
p_ht new_hash_table(int size);

/**
 * Libera a memória de uma tabela de hashing alocada
 * 
 * @table: HashTable a ser destruída
 * */
void ht_destroy(p_ht table);

/**
 * Insere uma nova chave na tabela de hashing
 * */
void ht_insert(p_ht table, char *key, int value);

/**
 * Procura se uma determinada chave está na tabela
 * 
 * Retorno:
 * 1 se a chave está na tabela
 * 0 do contrário
 * */
int ht_search(p_ht table, char* key);

/**
 * Função de hash
 * 
 * @key: uma chave para calcular o hash
 * @m: tamanho da tabela de hashing
 * */
int hash(char* key, int m);

#endif

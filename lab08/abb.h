#ifndef ABB_H
#define ABB_H

#define PKG_SIZE 15

/**
 * Bloco de dados de cada nó da arvore.
 * key -> valor identificador do nó (posição)
 * msg -> string que guarda o pacote recebido
 * */

typedef struct Data {
    int key;
    char msg[PKG_SIZE];
} Data;

/**
 * Cria uma bloco de dados para guardar os dados dos nós da árvore.
 * key -> identificador do nó
 * msg -> string que guarda uma mensagem parcial (pacote)
 * */
Data create_data(int key, const char* msg);

/**
 * Retorna o valor do inteiro no bloco de dados.
 * data -> um bloco de dados
 * */
int get_key(Data data);

/**
 * Retorna o ponteiro para a string do bloco de dados.
 * data -> ponteiro para um bloco de dados da árvore
 * */
const char* get_msg(const Data* data);

/** Estrutura de um nó da árvore
 * value -> blodo de dados que contém os valores do nó.
 * left -> ponteiro do filho esquerdo
 * right -> ponteiro do filho direito
 * */

typedef struct Node {
    Data value;
    struct Node *left, *right;
} Node;
typedef Node * p_node;

/**
 * Cria uma nova árvore com o dado especificado (uma folha com o valor na raiz).
 * v -> bloco de dados a ser guardado no nó
 * */
p_node create_tree(Data v);

/**
 * Faz a inserção de um novo dado (nó) na árvore.
 * v -> bloco de dados a ser inserido
 * */
p_node insert(p_node tree, Data v);

/**
 * Libera a memória anteriormente alocada para a árvore.
 * tree -> raiz da arvore alocada
 * */
void destroy_tree(p_node tree);

#endif

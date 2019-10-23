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
 * msg -> string que carrega a msg
 * */
Data create_data(int key, const char* msg);

/**
 * Retorna o valor do inteiro no bloco de dados.
 * data -> um bloco de dados de valor inteiro (type = 0)
 * */
int get_key(Data* data);

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

p_node create_tree(Data v);

p_node insert(p_node tree, Data v);

int search(p_node tree);

/**
 * Destrói a árvore anteriormente alocada.
 * tree -> raiz da arvore alocada
 * */
void destroy_tree(p_node tree);


#endif

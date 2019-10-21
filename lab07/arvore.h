#ifndef ARVORE_H
#define ARVORE_H

#define EMPTY     '\0'

/**
 * Bloco de dados de cada nó da arvore.
 * num -> valor se for numero
 * chr -> valor se for um caractere (operador ou incógnita)
 * type -> indicador de qual tipo o bloco carrega, 0 pra num, e 1 pra chr 
 *         e -1 se estiver apenas com valores nulos
 * */
typedef struct Data {
    int num;
    char chr;
    int type;
} Data;

/**
 * Cria uma bloco de dados para alocar nos nós da árvore.
 * x -> número para alocação
 * chr -> char para alocação
 * type -> tipo do valor a ser considerado (0 ou 1)
 * */
Data create_data(int x, char chr, int type);

/**
 * Retorna o valor do inteiro no bloco de dados.
 * data -> um bloco de dados de valor inteiro (type = 0)
 * */
int get_num(Data data);

/**
 * Retorna o valor do caractere no bloco de dados.
 * data -> um bloco de dados de valor char (type = 1)
 * */
int get_chr(Data data);

/**
 * Retorna o valor do tipo do bloco de dados (0 se int, 1 se char).
 * data -> um bloco de dados inicializado
 * */
int get_type(Data data);

/**
 * Define um novo valor numérico para o bloco de dados e apaga o valor de char anterior.
 * data -> ponteiro do bloco de dados (será transformado em type = 0)
 * */
void set_num(Data* data, int x);

/** Nó da árvore
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
 * Retorna uma nova arvore com os valores passados.
 * v -> bloco de dados a ser guardado no nó
 * l -> nó filho esquerdo
 * r -> nó filho direito
 * */
p_node create_tree(Data v, p_node l, p_node r);

/**
 * Destrói a árvore anteriormente alocada.
 * tree -> raiz da arvore alocada
 * */
void destroy_tree(p_node tree);

/**
 * Calcula uma operação baseada nos parâmetros.
 * a -> inteiro operador do lado esquerdo
 * b -> inteiro operador do lado direito
 * op -> caractere de operação (+, -, *, /)
 * */
int operate(int a, int b, char op);

/**
 * Retorna uma nova arvore simplificada (reduz os números que podem ser operados).
 * tree -> raiz da arvore a ser simplificada
 * */
p_node optmize_tree(p_node tree);

/**
 * Retorna 1 (true) se o valor da raíz da arvore está vazio (valor de inicialização).
 * 0 caso contrário.
 * root -> raiz da árvore a ser analisada
 * */
int empty_root(p_node root);

#endif

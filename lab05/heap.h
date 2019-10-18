/**
 * Definição do tipo Bloco
 * start -> representa a posição de início de um bloco de memória vazio
 * size -> quantidade de posições que este bloco representado possui
 * */
typedef struct Block {
    int start;
    int size;
} Block;

/**
 * Inicializa um novo bloco
 * */
Block create_block(int start, int size);

/**
 * Função de retorno do tamanho de um bloco
 * */
int get_size(Block block);

/**
 * Função de retorno do endereço de início de um bloco
 * */
int get_start(Block block);

/**
 * Atualizador de tamanho de um bloco
 * */
void set_size(int size, Block* block);

/**
 * Atualizador de início de um bloco
 * */
void set_start(int start, Block* block);
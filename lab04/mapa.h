#define M_MIN        ',' // Marcador do caminho p/ o minotauro
#define M_ESP        '.' //    ''         ''       a espada
#define ESPADA       'S' // Char que representa a espada
#define MINOTAURO    'M' // ''      ''          o minotauro
#define ENT          'E' // ''      ''          a entrada
#define PAREDE       '#' // ''      ''          a parede
#define SOL          '*' // ''      ''          o caminho solução
#define SOL_P        '/' // ''      ''          o caminho solução parcial

/** Cria a matriz do labirinto e retorna a matriz alocada
 * m -> numero de linhas
 * n -> numero de colunas
 * Retorno: um ponteiro de ponteiros de char (matriz de chars)
 * */
char** criar_mapa(int m, int n);

/** Faz a leitura do labirinto
 *  mapa -> labirinto alocado
 *  m -> número de linhas a serem lidas
 * */
void ler_mapa(char** mapa, int m);

/** Exibe o labirinto no terminal da forma que está
 * mapa -> labirinto alocado
 * m - > linhas
 * */
void imprimir_mapa(char** mapa, int m);

/** Limpa os lixos deixados pelo algoritmo no mapa
 * mapa -> labirinto alocado
 * m -> linhas
 * n -> colunas
 * m_esp -> marcador do camindo da espada 
 * m_min -> marcador do caminho do minotauro 
 * m_parcial -> marcador de uma solução parcial
 * */
void limpar_mapa(char** mapa, int m, int n, char m_esp, char m_min, char m_parcial);

/** Desaloca a memória anteriormente alocada para o labirinto
 * mapa -> labirinto alocado
 * m -> linhas
 * */
void desalocar_mapa(char** mapa, int m);

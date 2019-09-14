/** Criar a matriz do labirinto e retorna a matriz alocada
 * m -> numero de linhas
 * n -> numero de colunas
 * Retorno: um ponteiro de ponteiros de char (matriz de chars)
 * */
char** criar_mapa(int m, int n);

/** Faz a leitura do labirinto
 *  mapa -> labirinto alocado
 *  m -> número de linhas a serem lidas
 *  n -> número de colunas 
 * */
void ler_mapa(char** mapa, int m, int n);

/** Exibe o labirinto no terminal da forma que está
 * mapa -> labirinto alocado
 * m - > linhas
 * */
void imprime_mapa(char** mapa, int m);

/** Desaloca a memória anteriormente alocada para o labirinto
 * mapa -> labirinto alocado
 * m -> linhas
 * */
void desalocar_mapa(char** mapa, int m);

/**
@file interfacePrograma.h
Mecânica por trás do jogo, interface visual e orientação do jogo por comandos.
*/
#ifndef INTERFACE_FILE
#define INTERFACE_FILE

/**
\brief Apresenta o nº da jogada atual e do jogador a efetuar jogada. 
@param e Estado atual do jogo
*/
void prompt_INFO (ESTADO *e);


/**
\brief Apresenta a lista de todas as jogadas efetuadas durante um jogo, na consola.
@param e Estado atual do jogo
@param jog1 Lista de coordenadas alcançadas pelo jogador 1
@param jog2 Lista de coordenadas alcançadas pelo jogador 2
@param contadorJogadas Número total de jogadas efetuadas
*/
void movs_Consola(ESTADO *e, COORDENADA jog1[65], COORDENADA jog2[65], int contadorJogadas);


/**
\brief Apresenta o estado do tabuleiro impresso no ecrã.
@param e Estado atual do jogo
*/
void mostrar_tabuleiro(ESTADO *e);


/**
\brief Termina o programa
*/
void Q ();


/**
\brief Escreve, num ficheiro, a lista de todas as jogadas efetuadas durante um jogo.
@param e Estado atual do jogo
@param jog1 Lista de coordenadas alcançadas pelo jogador 1
@param jog2 Lista de coordenadas alcançadas pelo jogador 2
@param contadorJogadas Número total de jogadas efetuadas
@param file Nome do ficheiro onde se pretende gravar a informação
*/
void movs(ESTADO *e, COORDENADA jog1[65], COORDENADA jog2[65], int contadorJogadas, char *file);


/**
\brief Cria uma string com o nome do ficheiro, com o tamanho exato desse nome
@param linha String onde se encontra o nome do ficheiro
@param file Apontador para uma string onde se pretende guardar o nome do ficheiro
@param i índice a partir do qual se encontrará o nome do ficheiro na string inicial, linha
@returns char* Apontador para a string criada
*/
char* nome_Ficheiro (char linha[], char *file, int i);


/**
\brief Grava, num ficheiro .txt, o estado atual do jogo. 
@param e Estado atual do jogo
@param file Nome do ficheiro a guardar
*/
void gr (ESTADO *e, char *file);


/**
\brief A partir de um ficheiro de texto, verifica se o número de jogadas é par ou ímpar
@param jogo Ficheiro a ser analizado
@returns int 1 se for ímpar, 0 caso contrário
*/
int confirmaImpar (FILE *jogo);


/**
\brief Guarda, conforme o estado do jogo, as coordenadas efetuadas por ambos os jogadores
@param jogo Ficheiro onde se encontram os dados sobre o estado do jogo
@param jogadastotais Jogadas totais efetuadas por ambos os jogadores
@param jog1_chars Array de char's onde se encontram guardadas as coordenadas alcançadas pelo jogador 1
@param jog2_chars Array de char's onde se encontram guardadas as coordenadas alcançadas pelo jogador 2
*/
void coords_para_array (FILE *jogo, int jogadastotais, char jog1_chars[], char jog2_chars[]);


/**
\brief De acordo com um estado de jogo atual e arrays com coordenadas para cada jogador, efetua todas as jogadas possíveis com as mesmas
@param e Estado atual do jogo
@param jogo Ficheiro a ser analisado
@param jog1 Array de coordenadas alcançadas pelo jogador 1
@param jog2 Array de coordenadas alcançadas pelo jogador 2
@param jogadastotais Número total de jogadas efetuadas por ambos os jogadores
*/
void ajuda (ESTADO *e, FILE *jogo, COORDENADA *jog1, COORDENADA *jog2, int jogadastotais);


/**
\brief Transforma, a partir de arrays de char's, essa informação em dados do tipo COORDENADA
@param e Estado atual do jogo
@param jogo Ficheiro onde se encontram os dados sobre o estado do jogo em questão
@param jog1_chars Array de char's com as coordenadas alcançadas pelo jogador 1
@param jog2_chars Array de char's com as coordenadas alcançadas pelo jogador 2
@param jog1 Apontador para array de coordenadas alcançadas pelo jogador 1
@param jog2 Apontador para array de coordenadas alcançadas pelo jogador 2
@param jogadastotais Número total de jogadas efetuadas por ambos os jogadores
*/
void coords_de_ficheiro_jog (ESTADO *e, FILE *jogo, char jog1_chars[], char jog2_chars[], COORDENADA *jog1, COORDENADA *jog2, int jogadastotais);


/**
\brief Retorna o jogo atual para a jogada anterior pretendida, conforme input do utilizador
@param jogada Jogada anterior que se pretende alcançar
@param jog1 Lista de coordenadas alcançadas pelo jogador 1
@param jog2 Lista de coordenadas alcançadas pelo jogador 2
@param e Estado atual do jogo
*/
void pos (int jogada, COORDENADA jog1[], COORDENADA jog2[], ESTADO *e);


/**
\brief Lê um ficheiro de texto e imprime-o no ecrã.
@param file Nome do ficheiro a ler
@param e Estado atual do jogo
@param jog1 Apontador para array de coordenadas alcançadas pelo jogador 1
@param jog2 Apontador para array de coordenadas alcançadas pelo jogador 2
@returns int referente ao número de jogadas totais efetuadas no jogo (jog1 + jog2)
*/
int ler (char *file, ESTADO *e, COORDENADA *jog1, COORDENADA *jog2);


/**
\brief Recebe um comando do utilizador e orienta-o para a sua realização
@param e Estado atual do jogo
@returns int referente à boa execução da função (1)
*/
int interpretador(ESTADO *e);

#endif
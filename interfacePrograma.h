/**
@file interfacePrograma.h
Apresentação da informação, tabuleiro, jogo aos jogadores.
*/

#ifndef INTERFACE_FILE
#define INTERFACE_FILE

/**
\brief Informa qual é o jogador a jogar e o numero dejogadas feitas.
*/
void prompt_INFO (ESTADO *e);


/**
\brief Imprime tabuleiro atual. 
*/
void mostrar_tabuleiro(ESTADO *e);

/**
\brief Guarda a ultima jogada no ficheiro jogadaAtual.txt
*/
void gr (FILE *jogadaAtual, ESTADO *e);

/**
\brief Lê o ficheiro que contem a ultima jogada efetuada. jogadaAtual.txt
*/
void ler (FILE *ficheiro);

/**
\brief
*/
int interpretador(ESTADO *e);

#endif

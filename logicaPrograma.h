/**
@file logicaPrograma.h
Definição de funções auxiliares que realizam, além de deteções dos estados do jogo, as jogadas e atualizações necessárias para o correr do jogo.
*/
#ifndef LOGICA_FILE
#define LOGICA_FILE

/**
\brief Verifica se a coordenada a utilizar é vizinha da peça atual.
Analisa a coordenada para onde se pretende fazer uma jogada, retornando se esta é vizinha última peça ocupada por um jogador.
@param e Estado atual do jogo
@param c Coordenada a verificar
@returns True, caso seja vizinha, False, caso contrário
*/
int verifica_Posicao_Jogada (ESTADO *e, COORDENADA c);



int verifica_CASA (ESTADO *e, COORDENADA c);



int verifica_PERDEU (ESTADO *e, COORDENADA c);



int verifica_GANHOU (ESTADO *e);



void jogada_Intermedia (ESTADO *e, COORDENADA c);



void jogada_Vencedora(ESTADO *e, COORDENADA c);



int jogar (ESTADO *e, COORDENADA c);



void felicitar(ESTADO *e);

#endif
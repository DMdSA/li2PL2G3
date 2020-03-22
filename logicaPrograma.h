/**
@file logicaPrograma.h
*/

#ifndef LOGICA_FILE
#define LOGICA_FILE

/**
\brief Verifica se posição onde se pretende jogar é valida. 
@param c Coordenada
@parama e Apontador para o estado
@return Verdade ou Falso
*/
int verifica_Posicao_Jogada (ESTADO *e, COORDENADA c);

/**
\brief Verifica se a casa para onde se pretende mover ja tem peça preta.
@param e Apontador para o Estado
@param c Coordenada
@return Verdade ou Falso
*/
int verifica_CASA (ESTADO *e, COORDENADA c);

/**
\brief Verifica se é possivel continuar a jogar. Se todas as casas a sua volta são Pretas.
@param e Apontador para o Estado
@param c Coordenada
@return Verdade ou Falso
*/ 
int verifica_PERDEU (ESTADO *e, COORDENADA c);

/** 
\brief Verifica se as coordenadas sao igual a casa "1" ou "2" e se o jogador ganhou
@param e Apontador para o Estado
@param c Coordenada
@return Verdade ou Falso
*/
int verifica_GANHOU (ESTADO *e, COORDENADA c);


/** 
\brief Substitui a casa da peça branca por peça preta depois da jogada ser validada
*/
void jogada_Intermedia (ESTADO *e, COORDENADA c);


/** 
\brief Informar que jogador ganhou
*/
void jogada_Vencedora(ESTADO *e, COORDENADA c);


/** 
\brief Verifica se jogada é possivel
@param e apontador para o estado
@param c Coordenada
@return Verdade ou Falso
*/
int antecipa_Possibilidade_Jogada (ESTADO *e, COORDENADA c)


/** 
\brief Função para efetuar a jogada.
@param e apontador para o estado
@param c Coordenada
@return Verdade se for possivel jogar Falso se nao for possivel.  
*/
int jogar (ESTADO *e, COORDENADA c);

#endif

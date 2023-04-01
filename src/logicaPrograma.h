/**
@file logicaPrograma.h
Definição de funções auxiliares que realizam, além de deteções dos estados do jogo, as jogadas e atualizações necessárias para o correr do jogo.
*/
#ifndef LOGICA_FILE
#define LOGICA_FILE


/**
\brief Verifica se a coordenada a utilizar é vizinha da peça atual.
Analisa a coordenada para onde se pretende fazer uma jogada, retornando se esta é vizinha última peça ocupada por um jogador.
@param e Estado atual do jogo.
@param c Coordenada a verificar.
@returns True, caso seja vizinha. False, caso contrário.
*/
int verifica_Posicao_Jogada (ESTADO *e, COORDENADA c);


/**
\brief Verifica se é possivel jogar para a casa, ou seja, se a casa esta VAZIA ou '1' ou '2'.
@param e Estado atual do jogo.
@param c Coordenada a verificar.
@return True, caso seja VAZIA, '1' ou '2'. False caso seja invalida.
*/ 
int verifica_CASA (ESTADO *e, COORDENADA c);


/** 
\brief Verifica se o Jogador atual perdeu, isto é se todas as peças a volta são pretas.
@param e Estado atual do jogo. 
@param c Coordenada em que peça branca se encontra.
@return True, se todas as peças a volta forem pretas. False, caso ainda existam jogadas possiveis.
*/ 
int verifica_PERDEU (ESTADO *e, COORDENADA c);


/**
\brief Verifica se o Jogador ganhou. Se a coordenada da peça branca corresponde à casa '1' ou '2'.
@param e Estado atual do jogo.
@return True, caso uma das peças atuais sejam '1' ou '2'. Falso, caso seja outra peça qualquer. 
*/ 
int verifica_GANHOU (ESTADO *e);


/**
\brief Função para fazer a jogada, isto é, procura a peça branca e substitui-a por uma peça preta. 
Coloca a peça branca na nova coordenada em que foi jogada. 
@param e Estado atual do jogo.
@param c Coordenada em que se pretende jogar a peça branca.
*/ 
void jogada_Intermedia (ESTADO *e, COORDENADA c);


/** 
\brief Função principal para jogar. 
Vai juntar as funções anteriores para mover a peça, verificando se ganhou, perdeu, e se esta vazia.
@param e Estado atual do jogo.
@param c Coordenada a ser jogada.
@return True, se for possivel jogar. False, caso contrario. 
*/ 
int jogar (ESTADO *e, COORDENADA c);


/**
\brief Verifica qual foi jogador vencedor e felicita-o.
@param e Estado atual do jogo.
*/
void felicitar(ESTADO *e);

#endif
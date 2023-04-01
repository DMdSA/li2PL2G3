/**
@file bases.h
Definição dos tipos de dados para posterior utilização no projeto
*/
#ifndef BASES_FILE
#define BASES_FILE
#define BUF_SIZE 1024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
\brief Tipo de dados para a casa.
*/
typedef enum {VAZIA = '.', BRANCA = '*', PRETA = '#', UM = '1', DOIS = '2'} CASA;

/**
\brief Tipo de dados para as coordenadas.
*/
typedef struct {

	int coluna;
	int linha;

} COORDENADA;

/**
\brief Tipo de dados para a jogada.
*/
typedef struct {

	COORDENADA jogador1;
	COORDENADA jogador2;

} JOGADA;

/**
\brief Tipo de dados para as jogadas
*/
typedef JOGADA JOGADAS[32];

/**
\brief Tipo de dados para o estado.
*/
typedef struct {
	/** O tabuleiro */
	CASA tab[9][9]; //tab armazena informação sobre o tabuleiro.

	/** A coordenada da última jogada */
	COORDENADA ultima_jogada; //ultima_jogada -> coordenada da última jogada.
	
	/** As jogadas */
	JOGADAS jogadas; //jogadas -> informação sobre as jogadas.
	
	/** O número de jogadas */
	int num_jogadas; //num_jogadas -> quantas jogadas foram efetuadas. 
	
	/** O jogador atual */
	int jogador_atual; // jogador_atual -> indica qual é o jogador a jogar.

	//Todas as funções que alterem a estrutura dos dados devem receber um apontador para ESTADO.

} ESTADO;

#endif
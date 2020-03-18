#ifndef BASES_FILE
#define BASES_FILE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {VAZIA = '.', BRANCA = '*', PRETA = '#', UM = '1', DOIS = '2'} CASA;


typedef struct {

	int coluna;
	int linha;

} COORDENADA;


typedef struct {

	COORDENADA jogador1;
	COORDENADA jogador2;

} JOGADA;


typedef JOGADA JOGADAS[32];


typedef struct {

	CASA tab[8][8]; //tab armazena informação sobre o tabuleiro.

	COORDENADA ultima_jogada; //ultima_jogada -> coordenada da última jogada.
	
	JOGADAS jogadas; //jogadas -> informação sobre as jogadas.
	
	int num_jogadas; //num_jogadas -> quantas jogadas foram efetuadas. 
	
	int jogador_atual; // jogador_atual -> indica qual é o jogador a jogar.

	//Todas as funções que alterem a estrutura dos dados devem receber um apontador para ESTADO.

} ESTADO;

#endif

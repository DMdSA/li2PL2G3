#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bases.h"
#include "camadaDados.h"


//------------------------------------------------------------------------------------------------------------------------------

ESTADO *inicializar_estado() {

	ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
	
	e -> jogador_atual = 1;
	e -> num_jogadas = 0;
	e -> jogadas[32];
	e -> ultima_jogada.coluna = 4;
	e -> ultima_jogada.linha = 3;
	
	for (int i = 0; i < 8; i++) {

		for (int d = 0; d < 8; d++)
			e -> tab[i][d] = VAZIO;
	}

	e -> tab[0][7] = '2';
	e -> tab[7][0] = '1';
	e -> tab[3][4] = BRANCA;

	return e;
} // -> Cria um estado vazio (com o tabuleiro inicializado).
//------------------------------------------------------------------------------------------------------------------------------

/*

//------------------------------------------------------------------------------------------------------------------------------
int obter_jogador_atual(ESTADO *estado) {

	return estado -> jogador_atual;

} // -> Obtém o número do jogador atual.
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
int obter_numero_de_jogadas(ESTADO *estado) {

	return estado -> num_jogadas;

} // -> Permite obter quantas jogadas já foram efetuadas (cada jogada tem o movimento de 2 jogadores).
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
CASA obter_estado_casa(ESTADO *e, COORDENADA c) {


	
} // -> Permite obter o estado atual da casa.
//------------------------------------------------------------------------------------------------------------------------------
*/

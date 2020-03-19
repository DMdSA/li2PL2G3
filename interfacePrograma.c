#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bases.h"
#include "camadaDados.c"
#include "interfacePrograma.h"
#include "logicaPrograma.c"
//#define BUF_SIZE = 255;


//------------------------------------------------------------------------------------------------------------------------------
void prompt_INFO (ESTADO *e) {

	if (obter_estado_casa(e, criar_Coordenada(3, 4)) == BRANCA) //Se o jogo estiver no seu inicio,
		printf("[Inicio Jogo] | Jogador[%d] > Posicionamento na casa [L.%d, C.%d]\n\n", obter_jogador_atual(e), obter_Linha_Atual(e) + 1, obter_Coluna_Atual(e) + 1);
	else //Caso contrário,
		printf("[Jogada %d] | Jogador[%d] > movimento para a casa [L.%d, C.%d]\n\n", obter_numero_de_jogadas(e), obter_jogador_atual(e), obter_Linha_Atual(e) + 1, obter_Coluna_Atual(e) + 1);

}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
void mostrar_tabuleiro(ESTADO *e) { 

		printf("\n");
		for (int i = 0; i < 8; i++) {

			for (int d = 0; d < 8; d++) {

				printf("%c ", obter_estado_casa(e, criar_Coordenada(i, d)));
			}
			printf("\n");
		}
		prompt_INFO(e);
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
void gr (ESTADO *e) {

	FILE *game;

	game = fopen ("game.txt", "a");

	for (int d = 0; d < 8; d++) {

		for (int a = 0; a < 8; a++)
			fprintf(game, "%c ", obter_estado_casa(e, criar_Coordenada (d, a)) );

		fprintf(game, "\n");
	}

	fprintf(game, "\n");
	fclose(game);
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
void ler (ESTADO *e) {

	FILE *game;

	game = fopen("game.txt", "r");

	fclose(game);
}
//------------------------------------------------------------------------------------------------------------------------------




//------------------------------------------------------------------------------------------------------------------------------
int interpretador(ESTADO *e) {
	
	char linha[BUF_SIZE];
	char col[2], lin[2];
	
	if (fgets(linha, BUF_SIZE, stdin) == NULL)
	
		return 0;
	
	if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
	
		COORDENADA coord = {*col - 'a', *lin - '1'};
		jogar(e, coord);
		mostrar_tabuleiro(e);
	}
	
	return 1;
} 
//------------------------------------------------------------------------------------------------------------------------------


/*
int main () {

	ESTADO *e = inicializar_estado();
	mostrar_tabuleiro(e);
	gr(e);

	COORDENADA teste, teste2, teste3;

	teste.linha = 2;
	teste.coluna = 3;

	teste2.linha = 2;
	teste2.coluna = 4;

	teste3.linha = 1;
	teste3.coluna = 5;
	
	jogar(e, teste);
		
		mostrar_tabuleiro(e);
		gr(e);


	jogar (e, teste2);

		mostrar_tabuleiro(e);
		gr(e);


	jogar (e, teste3);

		mostrar_tabuleiro(e);
		gr(e);

	return 0;
}
*/

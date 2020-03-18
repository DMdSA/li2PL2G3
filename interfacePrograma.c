#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bases.h"
#include "camadaDados.h"
#include "interfacePrograma.h"
//#include "logicaPrograma.c"
//#define BUF_SIZE = 255;

//------------------------------------------------------------------------------------------------------------------------------
void mostrar_tabuleiro(ESTADO *e) { 

		for (int i = 0; i < 8; i++) {

			for (int d = 0; d < 8; d++) {

				if (e -> tab[i][d] == VAZIA)
					printf("%c ", VAZIA);
				
				else
					if (e -> tab[i][d] == BRANCA)
						printf("%c ", BRANCA);
				
					else
						if (e -> tab[i][d] == PRETA)
							printf("%c ", PRETA);
				
						else
							if (e -> tab[i][d] == UM)
								printf("%c ", UM);
				
							else
								printf("%c ", DOIS);
			}
			printf("\n");
		}
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



/*
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
*/



/*
int main () {

	ESTADO *e = inicializar_estado();
	mostrar_tabuleiro(e);
	gr(e);

	return 0;
}
*/

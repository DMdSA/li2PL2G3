#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bases.h"
#include "camadaDados.c"
#include "interfacePrograma.h"


//------------------------------------------------------------------------------------------------------------------------------
void mostrar_tabuleiro(ESTADO *e) { 

		for (int i = 0; i < 8; i++) {

			for (int d = 0; d < 8; d++) {

				if (e -> tab[i][d] == VAZIO)
					printf(". ");
				
				else
					if (e -> tab[i][d] == BRANCA)
						printf("* ");
				
					else
						if (e -> tab[i][d] == PRETA)
							printf("# ");
				
						else
							if (e -> tab[i][d] == '1')
								printf("1 ");
				
							else
								printf("2 ");
			}
			printf("\n");
		}
}

//Apenas constrói mediante as informações do ESTADO
//Vazia, Antiga, Atual, Inicial.
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
/* int interpretador(ESTADO *e) {
	
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
} */
//------------------------------------------------------------------------------------------------------------------------------


int main () {

	ESTADO *e = inicializar_estado();
	mostrar_tabuleiro(e);

	return 0;
}
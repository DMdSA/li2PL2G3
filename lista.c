#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "bases.h"
#include "camadaDados.h"
#include "interfacePrograma.h"
#include "logicaPrograma.h"


//------------------------------------------------------------------------------------------------------------------------------
LISTA criar_Lista() {

	LISTA inicial = malloc(sizeof(NODO));

	inicial -> primeiro = NULL;
	inicial -> proximo = NULL;
	
	return inicial;
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
LISTA insere_cabeca(LISTA L, void *valor) {

	if (L == NULL) {
		
		L -> primeiro = valor;
		return L;
	}

	else {

		LISTA L2 = malloc(sizeof(NODO));

		L2 -> primeiro = valor;
		L2 -> proximo = L;
		return L2;
	}
	//free(L);
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
COORDENADA *devolve_cabeca(LISTA L) {

	return L -> primeiro;
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
LISTA proximo(LISTA L) {

	return L -> proximo;
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
LISTA remove_cabeca(LISTA L) {


	LISTA final = L == NULL ? NULL : L -> proximo;

	free (L);

	return final;
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
int lista_esta_vazia(LISTA L) {

	return (L == NULL);
}
//------------------------------------------------------------------------------------------------------------------------------




COORDENADA *listaJogadasPossiveis (ESTADO *e) {

	COORDENADA verificar[8];

	COORDENADA atual = obter_Ultima_Jogada(e);

	COORDENADA esq, esqC, esqB, C, B, dir, dirC, dirB;

	C = criar_Coordenada(atual.linha - 1, atual.coluna);
	verificar[0] = C;

	B = criar_Coordenada(atual.linha + 1, atual.coluna);
	verificar[1] = B;

	esq = criar_Coordenada(atual.linha, atual.coluna - 1);
	verificar[2] = esq;

	dir = criar_Coordenada(atual.linha, atual.coluna + 1);
	verificar[3] = dir;

	esqB = criar_Coordenada(atual.linha + 1, atual.coluna - 1);
	verificar[4] = esqB;

	esqC = criar_Coordenada(atual.linha - 1, atual.coluna - 1);
	verificar[5] = esqC;

	dirB = criar_Coordenada(atual.linha + 1, atual.coluna + 1);
	verificar[6] = dirB;

	dirC = criar_Coordenada(atual.linha - 1, atual.coluna + 1);
	verificar[7] = dirC;


	int nCoords = 0;

	for (int d = 0; d < 8; d++) {
		if (obter_estado_casa(e, verificar[d]) == VAZIA) {
			nCoords++;
		}
	}
	printf("%d \n", nCoords);
	COORDENADA* jogadasPossiveis = (COORDENADA*) malloc( nCoords * sizeof(COORDENADA));

	for (int d = 0; d < nCoords; d++) {
		
		if (obter_estado_casa(e, verificar[d]) == VAZIA) {
			
			jogadasPossiveis[d] = verificar[d];
		}
		else
			printf("OH MEU DEUS\n");
	}

	return jogadasPossiveis;
}




int main () {

	ESTADO *e = inicializar_estado();
	mostrar_tabuleiro(e);

	jogar(e, criar_Coordenada(2,4));
	mostrar_tabuleiro(e);

	jogar(e, criar_Coordenada(2,5));
	mostrar_tabuleiro(e);

	printf("AQUI\n");
	COORDENADA *lista = listaJogadasPossiveis(e);


	imprime(lista[0]);
	printf("\n");
	imprime(lista[1]);
	printf("\n");
	imprime(lista[2]);
	printf("\n");
	imprime(lista[3]);
	printf("\n");
	imprime(lista[4]);
	printf("\n");
	imprime(lista[5]);
	printf("\n");
	imprime(lista[6]);
	printf("\n");

	return 0;


}








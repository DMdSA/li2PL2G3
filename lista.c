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

	LISTA inicial = (malloc(sizeof(NODO)));
	inicial -> primeiro = NULL;
	inicial -> proximo = NULL;
	
	return inicial;
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
LISTA insere_cabeca(LISTA L, void *valor) {

	if (L->primeiro == NULL) {
		
		L->primeiro = valor;
		
		return L;
	} 

	else {
		
		LISTA L2 = malloc(sizeof(NODO));
		L2->primeiro = valor;
		L2->proximo = L;
		L = L2;

		return L;
		free (L2);

	}
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
LISTA remove_cabeca(LISTA L) {

	struct  nodo *paraRemover;

	if (L == NULL || (L->primeiro == NULL && L->proximo == NULL)){
		printf("Lista esta vazia.\n");
	}
	
	else {

		paraRemover = L -> primeiro;
		//free(L -> primeiro);
		L -> primeiro = L -> proximo;
		free(paraRemover);
		
		printf("\nCabeca removida! \n\n");
		
	}
	return L;
}
//------------------------------------------------------------------------------------------------------------------------------

int tamanhoLista (LISTA L){
	int cont = 0; //Iniciar o contador
	if (L -> primeiro != NULL)
		cont ++;
	while ( L -> proximo != NULL){
		cont ++;
		L -> primeiro = L -> proximo;
	}
	return cont;
}

//------------------------------------------------------------------------------------------------------------------------------
int lista_esta_vazia(LISTA L) {

	if (L == NULL || (L->primeiro == NULL && L->proximo == NULL))
		return 1;
	return 0;
}
//------------------------------------------------------------------------------------------------------------------------------



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


	int nCoords = 0, aux = 0;

	for (int d = 0; d < 8; d++) {
		if ((obter_estado_casa(e, verificar[d]) == VAZIA) || (obter_estado_casa(e, verificar[d]) == UM) || (obter_estado_casa(e, verificar[d]) == DOIS)) {
			nCoords++;
		}
	}

	printf("%d \n", nCoords);

	COORDENADA* jogadasPossiveis = (COORDENADA*) malloc( nCoords * sizeof(COORDENADA));

	for (int d = 0; d < 8; d++) {
		
		if ((obter_estado_casa(e, verificar[d]) == VAZIA) || (obter_estado_casa(e, verificar[d]) == UM) || (obter_estado_casa(e, verificar[d]) == DOIS)) {
			jogadasPossiveis[aux] = verificar[d];
			aux++;
		}
	}
	return jogadasPossiveis;
}
//------------------------------------------------------------------------------------------------------------------------------




//------------------------------------------------------------------------------------------------------------------------------
LISTA imprimeLista(LISTA L){

	struct nodo *temp;

	if (L == NULL || (L->primeiro == NULL && L->proximo == NULL)) {
		printf("VAZIA\n");
	}
	else {
		temp = (L -> primeiro);
		while (temp != NULL){
			printf("L: ");
			imprime(*devolve_cabeca(temp));
			temp = L -> proximo;
		}
	}
	
	//if (L -> proximo != NULL) imprimeLista(L -> proximo);
}
//------------------------------------------------------------------------------------------------------------------------------



int main () {

	ESTADO *e = inicializar_estado();
	mostrar_tabuleiro(e);

	jogar(e, criar_Coordenada(2,4));
	mostrar_tabuleiro(e);

	jogar(e, criar_Coordenada(2,5));
	mostrar_tabuleiro(e);

	jogar(e, criar_Coordenada(1,6));
	mostrar_tabuleiro(e);

	jogar(e, criar_Coordenada(0,6));
	mostrar_tabuleiro(e);

	COORDENADA *lista = listaJogadasPossiveis(e);


	LISTA jogadas = criar_Lista();

	for (int d = 0; d < 4; d++)
		imprime(lista[d]); 
	printf("\n\n");



	//insere_cabeca(jogadas, lista);
	//printf("Esta vazia[2] = %d\n", lista_esta_vazia(jogadas));	

	printf("\nisto é a lista ANTES da cabeca! \n");
	imprimeLista(jogadas);

	insere_cabeca(jogadas, lista);
	printf("\nIsto é a lista DEPOIS de (1) cabeca! \n");
	

	insere_cabeca(jogadas, lista);

	//remove_cabeca(jogadas);
	printf("Tamanho %d ", tamanhoLista (jogadas));


	printf("insere %d \n", lista_esta_vazia(jogadas));
	remove_cabeca(jogadas);
	printf("Tamanho %d ", lista_esta_vazia(jogadas));

	printf("\n");
	//imprimeLista(jogadas);
	printf("\n\n");
	//imprime(*devolve_cabeca(jogadas));
	//printf("\n");



	return 0;
}
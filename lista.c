#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "bases.h"
#include "camadaDados.h"
#include "interfacePrograma.h"
#include "logicaPrograma.h"
#include <time.h>

//------------------------------------------------------------------------------------------------------------------------------
int tamanhoLista (LISTA L){

    int cont = 0;
    LISTA novo;
    novo = L;

    if (novo -> primeiro != NULL)
        cont ++;

    while (novo -> proximo != NULL){
        cont ++;
        novo -> primeiro = novo -> proximo;
    }
    return cont;
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
void printCoordVoid(void *coordenada) {

	COORDENADA c = *((COORDENADA *) coordenada);

	printf("%c%d\n", numero_Letra(c.coluna), (8 - c.linha));
}
//------------------------------------------------------------------------------------------------------------------------------



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

	if (L == NULL || (L -> primeiro == NULL && L-> proximo == NULL)) {
		L -> primeiro = valor;
		L -> proximo = NULL;
		return L;
	}

	else {

		LISTA aux = malloc(sizeof(NODO));
		aux -> primeiro = valor;
		aux -> proximo = L;
		L = aux;
		free(aux);
		return L;
	}
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
void *devolve_cabeca(LISTA L) {

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

	struct nodo *paraRemover;

    if (L == NULL || (L->primeiro == NULL && L->proximo == NULL)){
        printf("Lista esta vazia.\n");
    }

    else {

        paraRemover = L -> primeiro;
        //free(L -> primeiro);
        L -> primeiro = L -> proximo;

        printf("\nCabeca removida! \n\n");
    }
    free(paraRemover);
    return L;
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
int lista_esta_vazia(LISTA L) {

	if (L == NULL || (L->primeiro == NULL && L->proximo == NULL))
		return 1;
	return 0;
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
int qts_Espacos_Vazios(ESTADO *e) {

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

	for (int d = 0; d < 8; d++) { //Calcula quantas casas vazias há à volta do jogador em questão
		if ((obter_estado_casa(e, verificar[d]) == VAZIA) || (obter_estado_casa(e, verificar[d]) == UM) || (obter_estado_casa(e, verificar[d]) == DOIS)) {
			nCoords++;
		}
	}

	return nCoords;
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

	for (int d = 0; d < 8; d++) { //Calcula quantas casas vazias há à volta do jogador em questão
		if ((obter_estado_casa(e, verificar[d]) == VAZIA) || (obter_estado_casa(e, verificar[d]) == UM) || (obter_estado_casa(e, verificar[d]) == DOIS)) {
			nCoords++;
		}
	}

	COORDENADA* jogadasPossiveis = (COORDENADA*) malloc( nCoords * sizeof(COORDENADA)); //Cria um pointer com armazenamento suficiente para o número de coordenadas que é suposto armazenar

	for (int d = 0; d < 8; d++) {
		
		if ((obter_estado_casa(e, verificar[d]) == VAZIA) || (obter_estado_casa(e, verificar[d]) == UM) || (obter_estado_casa(e, verificar[d]) == DOIS)) { //Ao percorrer as casas, se forem vazias guarda as suas coordenadas no array de COORDENADAS
			jogadasPossiveis[aux] = verificar[d];
			aux++;
		}
	}
	return jogadasPossiveis;
}
//------------------------------------------------------------------------------------------------------------------------------




//------------------------------------------------------------------------------------------------------------------------------
void imprimeLista(LISTA L){
	
	struct nodo *temp;

    if (L == NULL || (L->primeiro == NULL && L->proximo == NULL)) {
        printf("VAZIA\n");
    }
   
    else {
        temp = (L -> primeiro);
        while (temp != NULL){
            printf("L: ");
            printCoordVoid(temp);
            temp = L -> proximo;
        }
    }

}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
int escolher_aleatorio(int max) {

	srand (time (NULL));

	int escolha = rand () % (max);

	return escolha;
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
COORDENADA escolha_jogada(COORDENADA *listaCoords, int indice) {

	return listaCoords[indice];
}
//------------------------------------------------------------------------------------------------------------------------------
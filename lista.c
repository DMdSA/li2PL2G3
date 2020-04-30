#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "bases.h"
#include "camadaDados.h"
#include "interfacePrograma.h"
#include "logicaPrograma.h"
#include <time.h>
#include <math.h>

//------------------------------------------------------------------------------------------------------------------------------
int tamanhoLista (LISTA L){

    int cont = 0; 
    LISTA aux = L; 

    while (aux -> valor != NULL){
        cont ++;
        aux = aux -> proximo;
    }
    return cont;
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
void printCoordVoid(COORDENADA *c) {

	printf("%c%d\n", numero_Letra(c -> coluna), (8 - c -> linha));
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
LISTA criar_lista() {

	LISTA inicial = malloc(sizeof(NODO));

	inicial -> valor = NULL;
	inicial -> proximo = NULL;
	
	return inicial;
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
LISTA insere_cabeca(LISTA L, void *valor) {

		LISTA aux = malloc(sizeof(NODO));
		aux -> proximo = L;
		aux -> valor = valor;
		return aux;
	} // -> Insere um valor na cabeça da lista
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
void *devolve_cabeca(LISTA L) {

	return L -> valor;
} // -> Devolve a cabeça da lista
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
LISTA proximo(LISTA L) {

	return L -> proximo;
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
LISTA remove_cabeca(LISTA L) {

	LISTA aux;

    if (L == NULL || (L->valor == NULL && L->proximo == NULL)){
        printf("Lista esta vazia.\n");
        return L;
    }
    else {

        aux = L -> proximo;
        //printf("Cabeca removida!\n");
        free(L);
        return aux;

    }
} // -> Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
_Bool lista_esta_vazia(LISTA L) {

	if (L == NULL || (L->valor == NULL && L->proximo == NULL))
		return 0;
	return 1;
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
		if (((obter_estado_casa(e, verificar[d]) == VAZIA) || (obter_estado_casa(e, verificar[d]) == UM) || (obter_estado_casa(e, verificar[d]) == DOIS)) && verifica_Coordenada(verificar[d])) {
			nCoords++;
		}
	}
	return nCoords;
}
//------------------------------------------------------------------------------------------------------------------------------
LISTA listaJogadasPossiveisLista (ESTADO *e){ // explicar bem

	LISTA final = criar_lista();
	COORDENADA atual = obter_Ultima_Jogada(e);

	COORDENADA *esq = malloc(sizeof(COORDENADA));
	COORDENADA *dir = malloc(sizeof(COORDENADA));
	COORDENADA *C = malloc(sizeof(COORDENADA));
	COORDENADA *B = malloc(sizeof(COORDENADA));
	COORDENADA *esqC = malloc(sizeof(COORDENADA));
	COORDENADA *esqB = malloc(sizeof(COORDENADA));
	COORDENADA *dirC = malloc(sizeof(COORDENADA));
	COORDENADA *dirB = malloc(sizeof(COORDENADA));

	*C = criar_Coordenada(atual.linha - 1, atual.coluna);
	if (((obter_estado_casa(e, *C ) == VAZIA) || (obter_estado_casa(e, *C) == UM) || (obter_estado_casa(e, *C) == DOIS)) && verifica_Coordenada(*C)) { //Ao percorrer as casas, se forem vazias guarda as suas coordenadas no array de COORDENADAS
		final = insere_cabeca(final, C);
	}

	*B = criar_Coordenada(atual.linha + 1, atual.coluna);
	if (((obter_estado_casa(e, *B ) == VAZIA) || (obter_estado_casa(e, *B) == UM) || (obter_estado_casa(e, *B) == DOIS)) && verifica_Coordenada(*B)) { //Ao percorrer as casas, se forem vazias guarda as suas coordenadas no array de COORDENADAS
		final = insere_cabeca(final, B);
	}

	*esq = criar_Coordenada(atual.linha, atual.coluna - 1);
	if (((obter_estado_casa(e, *esq ) == VAZIA) || (obter_estado_casa(e, *esq) == UM) || (obter_estado_casa(e, *esq) == DOIS)) && verifica_Coordenada(*esq)) { //Ao percorrer as casas, se forem vazias guarda as suas coordenadas no array de COORDENADAS
		final = insere_cabeca(final, esq);
	}

	*dir = criar_Coordenada(atual.linha, atual.coluna + 1);
	if (((obter_estado_casa(e, *dir ) == VAZIA) || (obter_estado_casa(e, *dir) == UM) || (obter_estado_casa(e, *dir) == DOIS)) && verifica_Coordenada(*dir)) { //Ao percorrer as casas, se forem vazias guarda as suas coordenadas no array de COORDENADAS
		final = insere_cabeca(final, dir);
	}

	*esqB = criar_Coordenada(atual.linha + 1, atual.coluna - 1);
	if (((obter_estado_casa(e, *esqB ) == VAZIA) || (obter_estado_casa(e, *esqB) == UM) || (obter_estado_casa(e, *esqB) == DOIS)) && verifica_Coordenada(*esqB)) { //Ao percorrer as casas, se forem vazias guarda as suas coordenadas no array de COORDENADAS
		final = insere_cabeca(final, esqB);
	}

	*esqC = criar_Coordenada(atual.linha - 1, atual.coluna - 1);
	if (((obter_estado_casa(e, *esqC ) == VAZIA) || (obter_estado_casa(e, *esqC) == UM) || (obter_estado_casa(e, *esqC) == DOIS)) && verifica_Coordenada(*esqC)) { //Ao percorrer as casas, se forem vazias guarda as suas coordenadas no array de COORDENADAS
		final = insere_cabeca(final, esqC);
	}

	*dirB = criar_Coordenada(atual.linha + 1, atual.coluna + 1);
	if (((obter_estado_casa(e, *dirB ) == VAZIA) || (obter_estado_casa(e, *dirB) == UM) || (obter_estado_casa(e, *dirB) == DOIS)) && verifica_Coordenada(*dirB)) { //Ao percorrer as casas, se forem vazias guarda as suas coordenadas no array de COORDENADAS
		final = insere_cabeca(final, dirB);
	}

	*dirC = criar_Coordenada(atual.linha - 1, atual.coluna + 1);
	if (((obter_estado_casa(e, *dirC ) == VAZIA) || (obter_estado_casa(e, *dirC) == UM) || (obter_estado_casa(e, *dirC) == DOIS)) && verifica_Coordenada(*dirC)) { //Ao percorrer as casas, se forem vazias guarda as suas coordenadas no array de COORDENADAS
		final = insere_cabeca(final, dirC);
	}

	printf("\n");
	return final;
}
//------------------------------------------------------------------------------------------------------------------------------




//------------------------------------------------------------------------------------------------------------------------------
void imprimeLista(LISTA L){
	
	LISTA aux;

    if(lista_esta_vazia(L) == 0){
    	printf("VAZIA\n");
    }

    aux = L;

    for(int i = 0; i < tamanhoLista(L); i++){
    		printf("L: ");
            printCoordVoid( (COORDENADA *) aux -> valor);
            aux = aux -> proximo;
    }
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
int escolher_aleatorio(int max) {

	int escolha = rand () % (max);

	return escolha;
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
COORDENADA *escolha_jogada(LISTA listaCoords, int indice) {

	for (int i = 0; i < indice; i++) {

		listaCoords = remove_cabeca(listaCoords);
	}

	return devolve_cabeca(listaCoords);
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
double distancia_Coords(COORDENADA c, int jogador) {

	double distancia = 0;
	int coluna = coluna_Coord(c);
	int linha = linha_Coord(c);

	if (jogador == 1)
		distancia = sqrt(pow(coluna - 0, 2) + pow(linha - 7, 2));

	if (jogador == 2)
		distancia = sqrt(pow(coluna - 7, 2) + pow(linha - 0, 2));

	return distancia;
}
//------------------------------------------------------------------------------------------------------------------------------




//------------------------------------------------------------------------------------------------------------------------------
COORDENADA *bot_v2(ESTADO *e) {

	LISTA listaOficial = criar_lista();
	int jogador = obter_jogador_atual(e);
	COORDENADA *final = malloc(sizeof(COORDENADA));
	listaOficial = listaJogadasPossiveisLista(e);

	imprimeLista(listaOficial);

	COORDENADA listaCoordenadas[qts_Espacos_Vazios(e)];

	for (int d = 0; d < qts_Espacos_Vazios(e); d++) {

		listaCoordenadas[d] = *((COORDENADA *) devolve_cabeca(listaOficial));
		listaOficial = remove_cabeca(listaOficial);
	}

	printf("\n");

	double distanciaMenor = distancia_Coords(listaCoordenadas[0], jogador);
	*final = listaCoordenadas[0];

	for (int d = 1; d < qts_Espacos_Vazios(e); d++) {

		if (distancia_Coords(listaCoordenadas[d], jogador) < distanciaMenor) {
			distanciaMenor = distancia_Coords(listaCoordenadas[d], jogador);
			*final = listaCoordenadas[d];
		}
	}



	//printf("%d DISTANCIA MENOR\n", distanciaMenor);
	free(listaOficial);
	return final;
}	
//------------------------------------------------------------------------------------------------------------------------------
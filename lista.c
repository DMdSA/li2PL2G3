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
// -> Função que ao receber uma lista devolve um inteiro com o seu tamanho.
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
void printCoordVoid(COORDENADA *c) {

	printf("%c%d\n", numero_Letra(c -> coluna), (8 - c -> linha));
}
//-> Função que recebendo um apontador de coordenada, da print da mesma na consola.
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
LISTA criar_lista() {

	LISTA inicial = malloc(sizeof(NODO));

	inicial -> valor = NULL;
	inicial -> proximo = NULL;
	
	return inicial;
}
//-> Função que cria uma lista vazia.
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
LISTA insere_cabeca(LISTA L, void *valor) {

		LISTA aux = malloc(sizeof(NODO));
		aux -> proximo = L;
		aux -> valor = valor;
		return aux;
	}
// -> Insere um valor na cabeça da lista.
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
void *devolve_cabeca(LISTA L) {

	return L -> valor;
} 
// -> Devolve a cabeça da lista.
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
LISTA proximo(LISTA L) {

	return L -> proximo;
}
// -> Devolve a cauda da lista.
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
} // -> Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda.
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
_Bool lista_esta_vazia(LISTA L) {

	if (L == NULL || (L->valor == NULL && L->proximo == NULL))
		return 0;
	return 1;
}
// -> Verifica se uma lista está vazia ou não.
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
// -> Função que, atravez do estado, calcula quantas casas vazias estão a volta da peça, ou seja, calcula quantas jogadas possíveis há a volta da peça.
//------------------------------------------------------------------------------------------------------------------------------
LISTA listaJogadasPossiveis (ESTADO *e){ // 

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
	if (((obter_estado_casa(e, *B ) == VAZIA) || (obter_estado_casa(e, *B) == UM) || (obter_estado_casa(e, *B) == DOIS)) && verifica_Coordenada(*B)) {
		final = insere_cabeca(final, B);
	}

	*esq = criar_Coordenada(atual.linha, atual.coluna - 1);
	if (((obter_estado_casa(e, *esq ) == VAZIA) || (obter_estado_casa(e, *esq) == UM) || (obter_estado_casa(e, *esq) == DOIS)) && verifica_Coordenada(*esq)) {
		final = insere_cabeca(final, esq);
	}

	*dir = criar_Coordenada(atual.linha, atual.coluna + 1);
	if (((obter_estado_casa(e, *dir ) == VAZIA) || (obter_estado_casa(e, *dir) == UM) || (obter_estado_casa(e, *dir) == DOIS)) && verifica_Coordenada(*dir)) {
		final = insere_cabeca(final, dir);
	}

	*esqB = criar_Coordenada(atual.linha + 1, atual.coluna - 1);
	if (((obter_estado_casa(e, *esqB ) == VAZIA) || (obter_estado_casa(e, *esqB) == UM) || (obter_estado_casa(e, *esqB) == DOIS)) && verifica_Coordenada(*esqB)) {
		final = insere_cabeca(final, esqB);
	}

	*esqC = criar_Coordenada(atual.linha - 1, atual.coluna - 1);
	if (((obter_estado_casa(e, *esqC ) == VAZIA) || (obter_estado_casa(e, *esqC) == UM) || (obter_estado_casa(e, *esqC) == DOIS)) && verifica_Coordenada(*esqC)) {
		final = insere_cabeca(final, esqC);
	}

	*dirB = criar_Coordenada(atual.linha + 1, atual.coluna + 1);
	if (((obter_estado_casa(e, *dirB ) == VAZIA) || (obter_estado_casa(e, *dirB) == UM) || (obter_estado_casa(e, *dirB) == DOIS)) && verifica_Coordenada(*dirB)) {
		final = insere_cabeca(final, dirB);
	}

	*dirC = criar_Coordenada(atual.linha - 1, atual.coluna + 1);
	if (((obter_estado_casa(e, *dirC ) == VAZIA) || (obter_estado_casa(e, *dirC) == UM) || (obter_estado_casa(e, *dirC) == DOIS)) && verifica_Coordenada(*dirC)) {
		final = insere_cabeca(final, dirC);
	}

	printf("\n");
	return final;
}
// -> Função que cria uma lista e 8 coordenadas, associando-as as casas a volta da peça, e adiciona na lista as casas cuja jogada é possível, retornando a Lista.
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
int escolher_aleatorio(int max) {

	int escolha = rand () % (max);

	return escolha;
}
// -> Função que recebe a quantidade de casas vazias ao redor da peça e devolve um int.
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
COORDENADA *escolha_jogada(LISTA listaCoords, int indice) {

	for (int i = 0; i < indice; i++) {

		listaCoords = remove_cabeca(listaCoords);
	}

	return devolve_cabeca(listaCoords);
}
//-> Recebendo um índice aleatório, devolve a coordenada nesse índice da lista, coordenada que vai ser jogada.
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
//-> Função que calcula a distancia euclidiana entre dois pontos.
//------------------------------------------------------------------------------------------------------------------------------




//------------------------------------------------------------------------------------------------------------------------------
COORDENADA *calcula_Distancia_Menor(ESTADO *e) {

	LISTA listaOficial = criar_lista();
	int jogador = obter_jogador_atual(e);
	COORDENADA *final = malloc(sizeof(COORDENADA));
	listaOficial = listaJogadasPossiveis(e);

	COORDENADA listaCoordenadas[qts_Espacos_Vazios(e)];

	for (int d = 0; d < qts_Espacos_Vazios(e); d++) {

		listaCoordenadas[d] = *((COORDENADA *) devolve_cabeca(listaOficial));
		listaOficial = remove_cabeca(listaOficial);
	}

	double distanciaMenor = distancia_Coords(listaCoordenadas[0], jogador);//primeira comparação, guardando a coordenada no apontador "final"
	*final = listaCoordenadas[0];

	for (int d = 1; d < qts_Espacos_Vazios(e); d++) { 

		if (distancia_Coords(listaCoordenadas[d], jogador) < distanciaMenor) { //Compara a distancia entre os dois pontos e caso seja uma distancia menor do que a registada anteriormente
			distanciaMenor = distancia_Coords(listaCoordenadas[d], jogador);
			*final = listaCoordenadas[d];
		}
	}



	//printf("%d DISTANCIA MENOR\n", distanciaMenor);
	free(listaOficial);
	return final;
}
//-> Função que devolve, das coordenadas que é possivel jogar, aqula cuja distancia à casa pretendida é a menor.
//------------------------------------------------------------------------------------------------------------------------------
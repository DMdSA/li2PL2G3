#ifndef LISTAS_LIGADAS
#define LISTAS_LIGADAS
#include "bases.h"
#include "camadaDados.h"


typedef struct nodo {
   void *primeiro;
   struct nodo *proximo;
} NODO, *LISTA;


int tamanhoLista (LISTA L);

void printCoordVoid(void *coordenada);



// Cria uma lista vazia
LISTA criar_lista();



// Insere um valor na cabeça da lista
LISTA insere_cabeca(LISTA L, void *valor);



// Devolve a cabeça da lista
void *devolve_cabeca(LISTA L);



// Devolve a cauda da lista
LISTA proximo(LISTA L);



// Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
LISTA remove_cabeca(LISTA L);



// Devolve verdareiro se a lista é vazia
int lista_esta_vazia(LISTA L);

COORDENADA *listaJogadasPossiveis (ESTADO *e);

void imprimeLista(LISTA L);


int qts_Espacos_Vazios(ESTADO *e);

int escolher_aleatorio(int max);

COORDENADA escolha_jogada(COORDENADA *listaCoords, int indice);

//Imprime uma lista ligada
void imprime_lista_ligada(LISTA L);


#endif
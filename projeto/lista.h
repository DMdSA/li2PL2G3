/**
@file lista.h
Definição dos tipos de dados para posterior utilização no projeto
*/
#ifndef LISTAS_LIGADAS
#define LISTAS_LIGADAS
#include "bases.h"
#include "camadaDados.h"

/**
\brief Tipo de dados para as listas.
*/
typedef struct nodo {
   void *valor;
   struct nodo *proximo;
} NODO, *LISTA;


/**
\brief Calcula o tamanho de uma lista.
@param L Lista a analisar.
@returns int com o tamanho da lista atribuída.
*/
int tamanhoLista (LISTA L);


/**
\brief Imprime na consola um apontador de coordenada.
@param c apontador para uma coordenada.
*/
void printCoordVoid(COORDENADA *c);


/**
\brief Cria uma lista vazia.
@returns LISTA vazia.
*/
LISTA criar_lista();


/**
\brief Insere um valor na cabeça da lista.
@param L Lista que vai ser alterada.
@param valor que vai ser inserido na lista
@returns LISTA com o valor inserido
*/
LISTA insere_cabeca(LISTA L, void *valor);


/**
\brief Devolve a cabeça da lista
@param L Lista cuja cabeça vai ser devolvida
@returns Apontador da cabeça
*/
void *devolve_cabeca(LISTA L);


/**
\brief Devolve a cauda da lista
@param L Lista cuja cauda vai ser devolvida
@returns LISTA contendo a cauda de L
*/
LISTA proximo(LISTA L);


/**
\brief Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
@param L Lista cuja cabeça vai ser removida.
@returns Lista com a cabeça removida
*/
LISTA remove_cabeca(LISTA L);


/**
\brief Verifica se a Lista L está ou não vazia.
@param L Lista 
@returns 0 se for verdade (lista está vazia) ou 1 caso seja falso (lista não esta vazia)
*/
_Bool lista_esta_vazia(LISTA L);


/**
\brief Calcula quantos espaços vazios existem à volta da peça
@param e apontador para o Estado
@returns int igual ao numero de espaços vazios
*/
int qts_Espacos_Vazios(ESTADO *e);


/**
\brief Junta numa lista as casas adjacentes para as quais pode ser jogado
@param e apontador para o estado
@returns Lista com as coordenadas para as quais se pode jogar
*/
LISTA listaJogadasPossiveis (ESTADO *e);


/**
\brief Calcula um numero aleatorio entre 0 e max
@param max valor maximo que o aleatorio pode tomar.
@returns valor aleatorio
*/
int escolher_aleatorio(int max);


/**
\brief Vai percorrendo a Lista ate alcancar o índice, devolvendo a coordenada desse índice
@param listaCoords Lista com as coordenadas possíveis de jogar
@param indice Índice da coordenada retirada
@returns Coordenada para onde o bot irá jogar
*/
COORDENADA *escolha_jogada(LISTA listaCoords, int indice);


/**
\brief calcula a distância euclidiana entre a coordenada recebida e a casa da vitoria (1 para jogador 1 e 2 para jogador 2)
@param c Coordenada que se prentende jogar
@param jogador Jogador que esta a efetuar a jogada
@returns distancia euclidiana
*/
double distancia_Coords(COORDENADA c, int jogador);


/**
\brief Compara a distância entre todas as jogadas possíveis e escolhe a jogada com a menor.
@param e apontador para o Estado
@returns Coordenada cuja distancia é a menor
*/
COORDENADA *calcula_Distancia_Menor(ESTADO *e);



#endif
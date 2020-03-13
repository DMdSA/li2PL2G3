#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bases.h"
//#include "camadaDados.h"
#include "camadaDados.c"
//#include "interfacePrograma.h"
#include "interfacePrograma.c"
#include "logicaPrograma.h"


int jogar(ESTADO *e, COORDENADA c) {
	
	printf("Antes da Jogada:\n");
	mostrar_tabuleiro(e);
	printf("\n\n");

	for (int d = 0; d < 8; d++) {
		for (int a = 0; a < 8; a++)
			if (e -> tab[d][a] == BRANCA)
				e -> tab[d][a] = PRETA;
	}
	e -> tab[c.linha][c.coluna] = BRANCA;

	printf("Jogar para linha %d coluna %d:\n", c.linha, c.coluna);

	mostrar_tabuleiro(e);

	return 1;

}
//Recebe o estadoAtual e uma coordenada -> Modifica o estado ao jogar na casa correta SE a jogada for válida.
//Devolve VDD (!= 0) se for possível jogar.
//Devolve F (== 0) caso não seja possível.

//--------------------------!!!
//Tem de se arranjar restrições para não sair da matriz do tabuleiro.
//Ver uma restrição rápida para só se mover entre peças vizinhas.



//TESTE
/*
int main () {

	ESTADO *e = inicializar_estado();

	COORDENADA teste;
	teste.linha = 7;
	teste.coluna = 6;
	
	jogar(e, teste);
	return 0;

} */

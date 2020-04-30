#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bases.h"
#include "camadaDados.h"
#include "logicaPrograma.h"

//------------------------------------------------------------------------------------------------------------------------------
int verifica_Posicao_Jogada (ESTADO *e, COORDENADA c) { //Verifica se a jogada Horizonta, Vertical ou Obliqua é possivel (ou seja, vizinha).

	COORDENADA inicial = obter_Ultima_Jogada(e); //coordenada inicial da peça branca

	int esq, dir;
	
	esq = inicial.coluna - 1; //coordenada da coluna à esquerda da peça branca (== para todas as linhas!)
	dir = inicial.coluna + 1; //coordenada da coluna à direita da peça branca (== para todas as linhas!)


	if (inicial.linha == c.linha) { //Se ambas as coordenadas (inicial e a que se pretende jogar) coincidirem com a mesma linha,
		if (c.coluna == esq || c.coluna == dir)	//Se a coluna for imediantamente à esquerda ou imediatamente à direita, da peça branca, a jogada é válida!
			return 1;
	}

	if (inicial.linha + 1 == c.linha) { //Se a coordenada da linha para a qual se pretende jogar for a imediatamente abaixo da peça branca,
		if (c.coluna == esq || c.coluna == dir || c.coluna == inicial.coluna) //Verifica as mesmas restrições, incluindo a própria coluna central.
			return 1;
	}

	if (inicial.linha - 1 == c.linha) {
		if (c.coluna == esq || c.coluna == dir || c.coluna == inicial.coluna)
			return 1;
	}

	return 0;
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
int verifica_CASA (ESTADO *e, COORDENADA c) { //Verifica se a casa, para onde se pretende efetuar a jogada, já está PRETA, ou se se encontra VAZIA.

	if (verifica_Posicao_Jogada(e, c)) {

		if (obter_estado_casa(e, c) == PRETA) //Se for preta, devolve 0.
			return 0;
		
		else
			if (obter_estado_casa(e, c) == VAZIA || obter_estado_casa(e ,c) == UM || obter_estado_casa(e, c) == DOIS) //Se for VAZIA, '1' ou '2', devolve1.
				return 1;
	}
	return 0;
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
int verifica_PERDEU (ESTADO *e, COORDENADA c) { //Verifica se TODAS as peças vizinhas estão pretas, ou seja, se o jogadorAtual perdeu.

	CASA cima, baixo, dir, esq, esqCima, esqBaixo, dirCima, dirBaixo;

	cima = obter_estado_casa (e, criar_Coordenada(c.linha - 1, c.coluna));
	baixo = obter_estado_casa (e, criar_Coordenada(c.linha + 1, c.coluna));

	esq = obter_estado_casa (e, criar_Coordenada(c.linha, c.coluna - 1));
	dir = obter_estado_casa (e, criar_Coordenada(c.linha, c.coluna + 1));

	esqBaixo = obter_estado_casa (e, criar_Coordenada(c.linha + 1, c.coluna - 1));
	esqCima = obter_estado_casa (e, criar_Coordenada(c.linha - 1, c.coluna - 1));

	dirBaixo = obter_estado_casa (e, criar_Coordenada(c.linha + 1, c.coluna + 1));
	dirCima = obter_estado_casa (e, criar_Coordenada(c.linha - 1, c.coluna + 1));

	if (cima == PRETA && cima == esq && cima == dir && cima == baixo && cima == esqBaixo && cima == esqCima && cima == dirBaixo && cima == dirCima ) //Se todas forem iguais ..
		return 1;

	if (obter_Linha_Atual(e) == 0 && obter_Coluna_Atual(e) >= 1 && obter_Coluna_Atual(e) <= 6) //Se estiver na linha de cima e nas colunas não dos extremos
		if (esq == PRETA && esq == esqBaixo && esqBaixo == baixo && baixo == dirBaixo && dirBaixo == dir)
			return 1;

	if (obter_Linha_Atual(e) == 0 && obter_Coluna_Atual(e) == 0) //Se estiver no canto superior esquerdo
		if (baixo == PRETA && baixo == dirBaixo && dirBaixo == dir)
			return 1;

	if (obter_Linha_Atual(e) == 7 && obter_Coluna_Atual(e) >= 1 && obter_Coluna_Atual(e) <= 6) //Se estiver na linha de baixo e não nas colunas extremas
		if (cima == PRETA && cima == esqCima && esqCima == esq && esq == dir && dir == dirCima)
			return 1;

	if (obter_Coluna_Atual(e) == 0 && obter_Linha_Atual(e) >= 1 && obter_Linha_Atual(e) <= 6) //Se estiver na primeira coluna da esquerda
		if (dir == PRETA && dir == dirCima && dirCima == cima && cima == baixo && baixo == dirBaixo)
			return 1;

	if (obter_Coluna_Atual(e) == 7 && obter_Linha_Atual(e) >= 1 && obter_Linha_Atual(e) <= 6) //Se estiver na última coluna da direita
		if (cima == PRETA && cima == esqCima && esqCima == esq && esq == esqBaixo && esqBaixo == baixo)
			return 1;

	if (obter_Linha_Atual(e) == 7 && obter_Coluna_Atual(e) == 7) //Se estiver no canto inferior direito
		if (esq == PRETA && esq == esqCima && esqCima == cima)
			return 1;

	return 0;
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
int verifica_GANHOU (ESTADO *e) { 

	int coluna_jogada, linha_jogada;
	coluna_jogada = obter_Coluna_Atual (e);
	linha_jogada = obter_Linha_Atual (e);

	if ((coluna_jogada == 7 && linha_jogada == 0) ||(coluna_jogada == 0 && linha_jogada == 7)) //Se a casa da coordenada C for '1' ou '2', o jogador atual ganhou o jogo!
		return 1; //retorna VDD
	else
		return 0; //retorna F
}
//------------------------------------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------------------------------------------
void jogada_Intermedia (ESTADO *e, COORDENADA c) {

	for (int d = 0; d < 8; d++) {
			for (int a = 0; a < 8; a++)
				if (obter_estado_casa (e, criar_Coordenada(d, a)) == BRANCA) //Procura a peça BRANCA atual no jogo
					atualiza_Casas (e, criar_Coordenada(d, a), PRETA);;	//E substitui a mesma por uma peça PRETA.
	}

	atualiza_Casas (e, c, BRANCA); //Atualiza a coordenada para onde se jogou com uma peça BRANCA.

	//Aqui já se considera que a jogada foi efetuada, tornando-se apenas de 'atualizações' ao estado.

	atualiza_Ultima_Jogada(e, c); // Atualiza, dentro de ESTADO, as coordenadas da ULTIMA_JOGADA.
	atualiza_Num_Jogadas (e);
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
void jogada_Vencedora(ESTADO *e, COORDENADA c) {

	for (int d = 0; d < 8; d++) {
			for (int a = 0; a < 8; a++)
				if (obter_estado_casa (e, criar_Coordenada(d, a)) == BRANCA) //Procura a peça BRANCA atual no jogo
					atualiza_Casas (e, criar_Coordenada(d, a), PRETA);	//E substitui a mesma por uma peça PRETA.
	}

	
	atualiza_Casas(e, c, BRANCA); //Atualiza a coordenada para onde se jogou com uma peça BRANCA.

	//Aqui já se considera que a jogada foi efetuada, tornando-se apenas de 'atualizações' ao estado.

	atualiza_Ultima_Jogada(e, c); // Atualiza, dentro de ESTADO, as coordenadas da ULTIMA_JOGADA.
	
	atualiza_Num_Jogadas(e); // Atualiza, dentro de ESTADO, o número de jogadas efetuadas.
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
int jogar(ESTADO *e, COORDENADA c) { //Função principal do jogo

	// BUGGGGGGGG -> Se o jogador 1 chegar a casa 2 ou o jog. 2 chegar a casa 1 esse jogador ganha apesar de essa não ser a sua  casa. CORRIGIR.
	if (verifica_Posicao_Jogada (e, c) && verifica_CASA (e, c) && verifica_GANHOU (e)) { //Se a jogada for possivel nas direções possiveis, a coordenada que se pretende estiver VAZIA e esta ser '1' ou '2', então ganhou!
		
		jogada_Vencedora(e, c); //Atualizações necessárias ao ESTADO e parabenização.
		return 1;
	}
	
	if (verifica_Posicao_Jogada(e, c) && verifica_CASA(e, c))  { //Se a coordenada dada for vizinha e a casa estiver VAZIA, a jogada é possível.

		atualiza_Jogador(e); //Se o jogador inicial for o 1, atualiza para 2, e vice-versa.
		
		jogada_Intermedia(e ,c); //Atualizações necessárias ao estado.

		return 1;
	}

	else {
		
		perdeste(1);
		return 0;
	}
}
//Devolve VDD (!= 0) se for possível jogar.
//Devolve F (== 0) caso não seja possível.
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
void felicitar(ESTADO *e) {

	int jogador = obter_jogador_atual(e);
	COORDENADA atual = obter_Ultima_Jogada(e);
	int colunaF = atual.coluna;
	int linhaF = atual.linha;

	if (colunaF == 0 && linhaF == 7 && jogador == 2)
		printf("O jogador[1] ganhou o jogo, parabens!\n");
	else
		if (colunaF == 0 && linhaF == 7 && jogador == 1)
			printf("Casa errada jogador[2], ganhou o jogador[1]!!\n");
		else
			if (colunaF == 7 && linhaF == 0 && jogador == 2)
				printf("Casa errada jogador[1], ganhou o jogador[2]!!\n");
			else
				if (colunaF == 7 && linhaF == 0 && jogador == 1)
					printf("O jogador[2] ganhou o jogo, parabens!\n");
}
//------------------------------------------------------------------------------------------------------------------------------
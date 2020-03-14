#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bases.h"
//#include "camadaDados.h"
#include "camadaDados.c"
//#include "interfacePrograma.h"
#include "interfacePrograma.c"
#include "logicaPrograma.h"



//------------------------------------------------------------------------------------------------------------------------------
int verifica_Posicao_Jogada (ESTADO *e, COORDENADA c) { //Verifica se a jogada Horizonta, Vertical ou Obliqua é possivel (ou seja, vizinha).

	COORDENADA inicial = e -> ultima_jogada; //coordenada inicial da peça branca

	int esq, dir;
	
	esq = e -> ultima_jogada.coluna - 1; //coordenada da coluna à esquerda da peça branca (== para todas as linhas!)
	dir = e -> ultima_jogada.coluna + 1; //coordenada da coluna à direita da peça branca (== para todas as linhas!)


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

		if (e -> tab[c.linha][c.coluna] == PRETA) //Se for preta, devolve 0.
			return 0;
		
		else
			if (e -> tab[c.linha][c.coluna] == VAZIO || e -> tab[c.linha][c.coluna] == '1' || e -> tab[c.linha][c.coluna] == '2') //Se for VAZIA, '1' ou '2', devolve1.
				return 1;
			
//			else {
//				printf("ERRO, FORA TABULEIRO\n"); -> Not sure se se deve usar.
//				return 0;
//			}
	}
	return 0;
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
int verifica_PERDEU (ESTADO *e, COORDENADA c) { //Verifica se TODAS as peças vizinhas estão pretas, ou seja, se o jogadorAtual perdeu.

	CASA cima, baixo, dir, esq, esqCima, esqBaixo, dirCima, dirBaixo;

	cima = e -> tab[c.linha - 1][c.coluna];
	baixo = e -> tab[c.linha + 1][c.coluna];

	esq = e -> tab[c.linha][c.coluna - 1];
	dir = e -> tab[c.linha][c.coluna + 1];

	esqBaixo = e -> tab[c.linha + 1][c.coluna - 1];
	esqCima = e -> tab [c.linha - 1][c.coluna - 1];

	dirBaixo = e -> tab[c.linha + 1][c.coluna + 1];
	dirCima = e -> tab[c.linha - 1][c.coluna + 1];

	if (cima == baixo && esq == dir && esqBaixo == esqCima && dirBaixo == dirCima && cima == esq) //Se todas forem iguais ..
		return 1;

	return 0;
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
int jogar(ESTADO *e, COORDENADA c) { //Função principal do jogo
	
	
	printf("\nAntes da Jogada: Linha %d, Coluna %d\n", e -> ultima_jogada.linha, e -> ultima_jogada.coluna);
	mostrar_tabuleiro(e); //Mostra a configuração inicial do jogo.
	printf("\n");

	
	if (verifica_Posicao_Jogada(e, c) && verifica_PERDEU(e, c)) //Se a coordenada da peça seguinte for vizinha, SE todas as peças à volta forem PRETAS, o jogo acaba! ("Se 1 e 1, ent VDD")
		printf("O jogo acabou para ti, Jogador [%d]. Boa sorte para a próxima!\n", e -> jogador_atual);



	if (verifica_Posicao_Jogada(e, c) && verifica_CASA(e, c))  { //Se a coordenada dada for vizinha e a casa estiver VAZIA, a jogada é possível.
		
		for (int d = 0; d < 8; d++) {
			for (int a = 0; a < 8; a++)
				if (e -> tab[d][a] == BRANCA) //Procura a peça BRANCA atual no jogo
					e -> tab[d][a] = PRETA;	//E substitui a mesma por uma peça PRETA.
		}

	
		obter_jogador_atual(e) == 1 ? (e -> jogador_atual = 2) : (e -> jogador_atual = 1); //Se o jogador inicial for o 1, atualiza para 2, e vice-versa.
		
		e -> tab[c.linha][c.coluna] = BRANCA; //Atualiza a coordenada para onde se jogou com uma peça BRANCA.
		e -> ultima_jogada = c; // Atualiza, dentro de ESTADO, as coordenadas da ULTIMA_JOGADA.
		
	
		if (obter_jogador_atual(e) == 2) //Se o jogador final for o 2, atualiza o ESTADO para a jogada + 1 (cada jogada é determinada pelo movimento de 2 jogadores*)
			e -> num_jogadas += 1;
		
	
		printf("Jogar para linha %d coluna %d:\n", c.linha, c.coluna);
		mostrar_tabuleiro(e); //imprime o tabuleiro atualizado.
		return 1;
	}


	else {
		
		printf("A jogada que tentaste efetuar (linha %d, coluna %d) nao e possivel!!\n\n", c.linha, c.coluna);
		mostrar_tabuleiro(e);
		return 0;
	}
}
//Recebe o estadoAtual e uma coordenada -> Modifica o estado ao jogar na casa correta SE a jogada for válida.
//Devolve VDD (!= 0) se for possível jogar.
//Devolve F (== 0) caso não seja possível.
//------------------------------------------------------------------------------------------------------------------------------



//TESTE
/*
int main () {

	ESTADO *e = inicializar_estado();

	COORDENADA teste, teste2, teste3;

	teste.linha = 2;
	teste.coluna = 3;

	teste2.linha = 2;
	teste2.coluna = 4;

	teste3.linha = 2;
	teste3.coluna = 3;
	
	jogar(e, teste);

	jogar (e, teste2);

	jogar (e, teste3);


	return 0;
} 
*/

//FALTA
//Parabenizar quem ganha

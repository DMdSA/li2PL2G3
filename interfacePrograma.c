#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bases.h"
#include "camadaDados.h"
#include "interfacePrograma.h"
#include "logicaPrograma.h"

//------------------------------------------------------------------------------------------------------------------------------
void prompt_INFO (ESTADO *e) {
	if (verifica_Inicio_Jogo(e))
		atualiza_Num_Jogadas(e);
	printf("#[%d], Jog[%d] > ", obter_numero_de_jogadas(e), obter_jogador_atual(e));
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
void mostrar_tabuleiro(ESTADO *e) { 

		printf("\n");
		for (int i = 0; i < 8; i++) {

			for (int d = 0; d < 8; d++) {

				printf("%c ", obter_estado_casa(e, criar_Coordenada(i, d)));
			}
			printf("\n");
		}
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
void Q (){
	printf("A sair do programa...\n");
	exit(0);
	// Função que fecha o programa.
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
void gr (FILE *jogadaAtual, ESTADO *e) {

	jogadaAtual = fopen("jogadaAtual.txt", "w");

	for (int i = 0; i < 8; i++) {

		for (int a = 0; a < 8; a++)
			fprintf(jogadaAtual, "%c ", obter_estado_casa(e, criar_Coordenada(i, a)));
		
		fprintf(jogadaAtual, "\n");
	}

	fclose(jogadaAtual); 
}	// -> Grava apenas a última jogada no ficheiro jogadaAtual.txt
//------------------------------------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------------------------------------------
/*void grTUDO (ESTADO *e) { // -> Grava todas as jogadas efetuadas por jogo.
	FILE *game;
	game = fopen ("game.txt", "a");
	for (int d = 0; d < 8; d++) {
		for (int a = 0; a < 8; a++)
			fprintf(game, "%c ", obter_estado_casa(e, criar_Coordenada (d, a)) );
		fprintf(game, "\n");
	}
	fprintf(game, "\n");
	fclose(game);
} */
//------------------------------------------------------------------------------------------------------------------------------

void movs(ESTADO *e, COORDENADA jog1[65], COORDENADA jog2[65], int number){
	int i;

	printf("\n");
	if(number%2 != 0){
		for (i = 1; i < obter_numero_de_jogadas(e); i ++){
			printf("[%d]: ",i);
			imprime(jog1[i]);
			printf(" ");
			imprime(jog2[i]);
			printf("\n");
		}
		printf("[%d]: ",i);
		imprime(jog1[i]);
		printf("\n\n");
	}
	else{
		for (int f = 1; f < obter_numero_de_jogadas(e); f++){
			printf("[%d]: ",f);
			imprime(jog1[f]);
			printf(" ");
			imprime(jog2[f]);
			printf("\n");
		}
		printf("\n");
	}
	
}


//------------------------------------------------------------------------------------------------------------------------------
void ler (FILE *ficheiro) {

	char linha[15];
	ficheiro = fopen("jogadaAtual.txt", "r");

	while ( fgets(linha, sizeof(linha), ficheiro) )
		printf("%s", linha);

	fclose(ficheiro);
}	// -> Lê o ficheiro que contém a última jogada efetuada.
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
int interpretador(ESTADO *e) {
	
	FILE *ficheiro;
	char linha[BUF_SIZE];
	char col[2], lin[2];
	COORDENADA coord2;
	COORDENADA jog1 [65];
	COORDENADA jog2 [65];
	int number = 0;

	do{

	prompt_INFO(e);

	if (fgets(linha, BUF_SIZE, stdin) == NULL)
		return 0;

	if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {

		//printf("COLUNA %d, LINHA %d\n", *col - 'a', (*lin - '1'));// -> Alterações necessárias face à nossa interpretação da matriz, presente em RASCUNHOS.Ht
		
		COORDENADA coord = {*col - 'a', 7 - (*lin - '1') };
		
		coord2 = coord;
		number++;

		if (obter_jogador_atual(e) == 1){
			jog1 [obter_numero_de_jogadas(e)] = coord2;
		}
		else{
			jog2 [obter_numero_de_jogadas(e)] = coord2;
		}
		
		if (jogar(e, coord)) { // -> O facto de a própria jogada ser argumento do if, não faz com que ele "funcione", em vez de só o verificar??
			mostrar_tabuleiro(e);
//		gr(ficheiro, e); -> Só deve gravar quando se dá o respetivo comando.
		}
	}
	
	else
		if (strlen(linha) == 5 && strcmp(linha, "Q\n") == 0)
			Q();
	
		else
			if (strlen(linha) == 7 && strcmp(linha, "gr\n") == 0)
				gr(ficheiro, e);

			else
				if (strlen(linha) == 4 && strcmp(linha, "ler\n") == 0)
					ler(ficheiro);

				else
					if (strlen(linha) == 5 && strcmp(linha, "movs\n") == 0)
					{
						movs(e, jog1, jog2, number);
					}
					else
						printf("COMANDO INVALIDO!\n\n");
		}
		while(verifica_GANHOU(e, coord2) == 0 && verifica_PERDEU(e, coord2) == 0);

	return 1;
}
//------------------------------------------------------------------------------------------------------------------------------


/*
int main () {
	FILE *atual;
	ESTADO *e = inicializar_estado();
	mostrar_tabuleiro(e);
	gr(atual, e);
	COORDENADA teste, teste2, teste3;
	teste.linha = 2;
	teste.coluna = 3;
	teste2.linha = 2;
	teste2.coluna = 4;
	teste3.linha = 1;
	teste3.coluna = 5;
	
	jogar(e, teste);
		
		mostrar_tabuleiro(e);
		gr(atual, e);
	jogar (e, teste2);
		mostrar_tabuleiro(e);
		gr(atual, e);
	jogar (e, teste3);
		mostrar_tabuleiro(e);
		gr(atual, e);
	return 0;
}
*/

/*
int main () {
	FILE *qqercoisa;
	//ESTADO *e = inicializar_estado();
	ler(qqercoisa);
	return 0;
}
*/
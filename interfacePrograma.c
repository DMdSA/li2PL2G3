#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bases.h"
#include "camadaDados.h"
#include "interfacePrograma.h"
#include "logicaPrograma.h"
#include "lista.h"

//------------------------------------------------------------------------------------------------------------------------------
void prompt_INFO (ESTADO *e) {
	if (verifica_Inicio_Jogo(e))
		e -> num_jogadas = 1;
	printf("#[%d], Jog[%d] > ", obter_numero_de_jogadas(e), obter_jogador_atual(e));
} // -> Local de input para o utilizador efetuar jogadas
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
void movs_Consola(ESTADO *e, COORDENADA jog1[], COORDENADA jog2[], int number){ // number -> Numero de jogadas totais (jog1 + jog2).
	int i;

	printf("\n");
	if (number%2 != 0){//loop para caso o numero de jogadas totais seja impar, isto é, numero de jogadas do jogador 1 é 1 a mais do que o numero de jogadas do jogador 2.
		for (i = 1; i < obter_numero_de_jogadas(e); i ++){
			printf("[%02d]: ",i);
			imprime(jog1[i]);
			printf(" ");
			imprime(jog2[i]);
			printf("\n");
		}
		printf("[%02d]: ",i);
		imprime(jog1[i]);
		printf("\n\n");
	}
	else{ //loop para caso o numero de jogadas totais seja par aka numero de jogadas do jogador 1 é igual ao numero de jogadas do jogador 2.
		for (int f = 1; f < obter_numero_de_jogadas(e); f++){
			printf("[%02d]: ",f);
			imprime(jog1[f]);
			printf(" ");
			imprime(jog2[f]);
			printf("\n");
		}
		printf("\n");
	}
} // -> Função que imprime os movimentos todos efetuados até então, na própria consola.
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
void mostrar_tabuleiro(ESTADO *e) { 

		printf("\n");
		for (int i = 0; i < 9; i++) {

			for (int d = 0; d < 9; d++) {

				printf("%c ", obter_estado_casa(e, criar_Coordenada(i, d)));
			}
			printf("\n");
		}
		printf("\n");
} // -> Imprime um tabuleiro com os dados associados ao estado atual.
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
void Q (){
	printf("A sair do programa...\n");
	exit(0);
} // ->Função que encerra o programa.
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
void movs(ESTADO *e, COORDENADA jog1[65], COORDENADA jog2[65], int number, char *file){ //number -> Numero de jogadas totais (jog1 + jog2).
	int i;
	FILE *gravaMovimentos;

	gravaMovimentos = fopen (file, "a");
	fprintf(gravaMovimentos, "\n");

	if(number % 2 != 0){
		for (i = 1; i < obter_numero_de_jogadas(e); i++){ //loop para caso o numero de jogadas totais seja impar, isto é, numero de jogadas do jogador 1 é 1 a mais do que o numero de jogadas do jogador 2.

			fprintf(gravaMovimentos, "%02d: ",i);
			fprintf(gravaMovimentos, "%c%d", letra_Coordenada(jog1[i]), (8 - jog1[i].linha));
			fprintf(gravaMovimentos, " ");

			fprintf(gravaMovimentos, "%c%d", letra_Coordenada(jog2[i]), (8 - jog2[i].linha));

			fprintf(gravaMovimentos, "\n");
		}
		fprintf(gravaMovimentos, "%02d: ",i);

		fprintf(gravaMovimentos, "%c%d", letra_Coordenada(jog1[i]), (8 - jog1[i].linha));

		fprintf(gravaMovimentos, "\n\n");
	}
	else{

		for (int f = 1; f < obter_numero_de_jogadas(e); f++){ //loop para caso o numero de jogadas totais seja par aka numero de jogadas do jogador 1 é igual ao numero de jogadas do jogador 2.

			fprintf(gravaMovimentos, "%02d: ",f);
			fprintf(gravaMovimentos, "%c%d", letra_Coordenada(jog1[f]), (8 - jog1[f].linha));

			fprintf(gravaMovimentos, " ");

			fprintf(gravaMovimentos, "%c%d", letra_Coordenada(jog2[f]), (8 - jog2[f].linha));

			fprintf(gravaMovimentos, "\n");
		}
		fprintf(gravaMovimentos, "\n");
	}
	fclose(gravaMovimentos);
}
// -> Função que imprime no ficheiro as jogadas anteriores.
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
char* nome_Ficheiro (char linha[], char *file, int i) {

	int d;
	for (d = 0; ((linha[i] >= 'a' && linha[i] <= 'z') || (linha[i] >= 'A' && linha[i] <= 'Z') || (linha[i] >= '0' && linha[i] <= '9')); d++) {  
			
			if (file[d]) {

					file[d] = linha[i];
					i++;
			}

			else { 

				file = (char *) realloc(file, d+1);
				file[d] = linha[i];
				i++;
			}
	}
	file[d] = '\0';
	return file;
} // -> Função que cria uma string que se readapta ao tamanho do nome do ficheiro.
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
void gr (ESTADO *e, char *file) {
	
	strcat(file, ".txt\0"); //adiciona o .txt de modo a poder abrir o ficheiro mais à frente

	FILE *jogo; 
	jogo = fopen (file, "w");

	printf("A gravar...\n");

	for (int i = 0; i < 8; i++) {

		for (int a = 0; a < 8; a++)
			fprintf(jogo, "%c ", obter_estado_casa(e, criar_Coordenada(i, a)));

		fprintf(jogo, "\n");
	}
	fclose(jogo);
}	// -> Grava a última jogada efetuada no ficheiro pretendido
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
int confirmaImpar (FILE *jogo) {

	int confirma = 1;
	int char2;

	
	//Vai a posição 8 a contar do fim do ficheiro e ve se existe um numero nessa posição
	fseek(jogo, -6, SEEK_END); //Para Linux
	//fseek(jogo, -8, SEEK_END); //Para Windows
	char duvida = fgetc(jogo);

	char2 = duvida - '0';

	if (char2 >= 1 && char2 <= 8) //Se houver entao o jogador 2 tambem jogou, ou seja o numero de jogadas seria par
		confirma = 0;

	return confirma;
} //-> Confirma no ficheiro se, na ultima jogada, o jogador 2 jogou (visto que se for o jogador 2 a gravar, apenas o jogador 1 jogou). 
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
 void coords_para_array (FILE *jogo, int jogadastotais, char jog1_chars[], char jog2_chars[]){

 	int contador = 141; //-> Opção para Linux.
	//int contador = 150; //-> ignora o desenho do tabuleiro e comeca na primeira coordenada!
	int d = 0, e = 0, ajuda1 = 2, ajuda2 = 2;
	int numerDeJogadas = 0;

		fseek(jogo, contador, SEEK_SET);    
		for (int a = 1; a <= jogadastotais; a++) {

			if (a % 2 != 0) {
				for (; d < ajuda1; d++){
					jog1_chars[d] = fgetc(jogo);
				}
				ajuda1 += 2;

				contador += 3; //-> ignorar o espaco entre as coorenadas do jog1 e do jog2!
				fseek(jogo, contador , SEEK_SET);
			}

			else{

				if (a != jogadastotais+1 || confirmaImpar(jogo) == 0) {

					for (; e < ajuda2; e++) {
						jog2_chars[e] = fgetc(jogo);

					}
					ajuda2 += 2;
					contador += 7 // para linux
					//contador += 8; 
					// ^ numero de espacos para mudar de linha!
					fseek(jogo, contador, SEEK_SET);
				}
			}
		}
		numerDeJogadas = jogadastotais;
		printf("%d\n", jogadastotais);
}
 //------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
void ajuda (ESTADO *e, FILE *jogo, COORDENADA *jog1, COORDENADA *jog2, int jogadastotais) {

	if (verifica_Inicio_Jogo(e))
		atualiza_Num_Jogadas(e);

	if (confirmaImpar(jogo) == 0) {

		for (int a = 1; a < jogadastotais+1; a++) {

			jogar(e, jog1[a]);

			jogar(e, jog2[a]);

		}
	}
	else {
		int z = 1;
		for (; z <= jogadastotais-1; z++) {
			jogar(e, jog1[z]);

			jogar(e, jog2[z]);
		}

		jogar(e, jog1[z]);
	}
} // -> Realiza todas as jogadas possíveis conforme as coordenadas guardadas nos arrays dados, até alcançar o estado pretendido
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
void coords_de_ficheiro_jog (ESTADO *e, FILE *jogo, char jog1_chars[], char jog2_chars[], COORDENADA *jog1, COORDENADA *jog2, int jogadastotais) {

	int i = 1;
	for (int a = 0; a < jogadastotais*2; a += 2) { // -> O primeiro 2 é o numero de jogadas que há

		int letra = letra_Numero(jog1_chars[a]);

		int numero = 8-(jog1_chars[a + 1] - '0');

		jog1[i] = criar_Coordenada(numero, letra);
		i++;
	}

	i = 1;
	for (int a = 0; a < jogadastotais*2; a += 2) { // -> O primeiro 2 é o numero de jogadas que há

		int letra = letra_Numero(jog2_chars[a]);

		int numero = 8-(jog2_chars[a + 1] - '0');

		jog2[i] = criar_Coordenada(numero, letra);

		i++;
		}

	ajuda(e, jogo, jog1, jog2, jogadastotais);
} // -> A partir de um array de chars com as coordenadas de cada jogador, transforma-os num array do tipo COORDENADA, para cada jogador
//-----------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
void pos(int jogada, COORDENADA jog1[], COORDENADA jog2[], ESTADO *e) {

	if (verifica_Inicio_Jogo(e))
		atualiza_Num_Jogadas(e);

	if (jogada != 0) {

		for (int d = 1; d <= jogada; d++) {

			jogar(e, jog1[d]);

			jogar(e, jog2[d]);
		}
		mostrar_tabuleiro(e);
	}
} // -> Conforme as coordenadas guardadas em cada array, efetua todas as jogadas possíveis até alcançar uma jogada anterior pretendida
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
int ler (char *file, ESTADO *e, COORDENADA *jog1, COORDENADA *jog2) { //explicar!
	char linha[40];
	int jogadastotais = 0;
	char jog1_chars[128];
    char jog2_chars [128];
    int contadorJogadas=0;

	strcat(file, ".txt\0");

	FILE *jogo;
	jogo = fopen(file, "r");

	if (jogo == NULL){
		printf("Este ficheiro nao existe\n");
	}

	else {
		while ( fgets(linha, sizeof(linha), jogo) ) {
			jogadastotais++;
			printf("%s", linha);
		}
		
		jogadastotais -= 10; // Retira as 10 primeiras linhas, referentes à "imagem" do tabuleiro e linha em branco
		if (confirmaImpar(jogo) == 0){
			contadorJogadas = jogadastotais*2;
		}
		else {
			contadorJogadas = jogadastotais*2+1;
		}

		coords_para_array(jogo, jogadastotais*2, jog1_chars, jog2_chars);

		coords_de_ficheiro_jog(e, jogo, jog1_chars, jog2_chars, jog1, jog2, jogadastotais);

		mostrar_tabuleiro(e);
		fclose(jogo);
	}
		return contadorJogadas;
}	// -> Lê o ficheiro que contém a última jogada efetuada.
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
int interpretador(ESTADO *e) {

	char linha[BUF_SIZE];
	char col[2], lin[2], *file, gravar[7], posicao_Lida[3];
	COORDENADA coord2;
	COORDENADA jog1 [65];
	COORDENADA jog2 [65];
	int contadorJogadas = 0;   //Serve para verificar se a jogada é par ou impar (jog1 ou jog2)
	posicao_Lida[2] = '\0';
	int guardarJogadaPos =  0;
	coord2 = criar_Coordenada(3,4);

	do {
		file = (char *) malloc(8);
		prompt_INFO(e);

		if (fgets(linha, BUF_SIZE, stdin) == NULL)
			return 0;

		if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
			COORDENADA coord = {*col - 'a', 7 - (*lin - '1') };
			coord2 = coord;			

			if (verifica_Posicao_Jogada(e, coord2) && verifica_CASA(e, coord2)) {
				if (obter_jogador_atual(e) == 1)
					jog1 [obter_numero_de_jogadas(e)] = coord2;
				else
					jog2 [obter_numero_de_jogadas(e)] = coord2;
				contadorJogadas++;
			}

			if (jogar(e, coord)) { // -> O facto de a própria jogada ser argumento do if, não faz com que ele "funcione", em vez de só o verificar??
				mostrar_tabuleiro(e);
				guardarJogadaPos = 0;
			}
		}
		else
			if (strlen(linha) == 2 && strcmp(linha, "q\n") == 0) // SE O COMANDO FOR SAIR
				Q();

			else {
					for (int a = 0; a < 5; a++)
						gravar[a] = linha[a];
					gravar[6] = '\0'; // -> Grava a instrução "gr ", "ler " ou "movs "
				
					if (gravar[0] == 'g' && gravar[1] == 'r' && gravar[2] == ' ') { // SE O COMANDO FOR GRAVAR
						int i = 3; // Contador inicializar a 3 espaços "gr " <- ignora

						file = nome_Ficheiro(linha,file, i);						
						gr(e, file); // Não tentar gravar à primeira, porque o jogo nem inicializou! É só uma "visualizacao" do tabuleiro.
						movs(e, jog1, jog2, contadorJogadas, file);
						free(file);
						if(obter_numero_de_jogadas(e) == 1){
							coord2 = criar_Coordenada(3,4);
						}
					}
					else
						if (gravar[0] == 'l' && gravar[1] == 'e' && gravar[2] == 'r' && gravar[3] == ' ') { // -> SE O COMANDO FOR LER
							int i = 4;
							file = nome_Ficheiro(linha, file, i);
								e = inicializar_estado();
								contadorJogadas = 0;
								contadorJogadas = ler(file,e,jog1,jog2);
								free(file);

								if(obter_numero_de_jogadas(e) == 1){
									coord2 = criar_Coordenada(3,4);
								}
						}
						else
							if (gravar[0] == 'm' && gravar[1] == 'o' && gravar[2] == 'v' && gravar[3] == 's') //SE O COMANDO FOR MOVS
							{
								movs_Consola(e, jog1, jog2, contadorJogadas);
								if(obter_numero_de_jogadas(e) == 1){
									coord2 = criar_Coordenada(3,4);
								}
							}
							else{
								if (gravar[0] == 'p' && gravar[1] == 'o' && gravar[2] == 's' && gravar[3] == ' ') { //SE O COMANDO FOR POS

									if (linha[4] >= '0' && linha[4] <= '9')
										posicao_Lida[0] = linha[4];
									if (linha[5] >= '0' && linha[5] <= '9')
										posicao_Lida[1] = linha[5];

									int posicao = atoi(posicao_Lida);
									if(guardarJogadaPos < obter_numero_de_jogadas(e)){
											guardarJogadaPos = obter_numero_de_jogadas(e);
									}
									if (posicao > 0 && posicao < guardarJogadaPos) {
										e = inicializar_estado();
										pos(posicao, jog1, jog2, e);
										contadorJogadas = 0;
									}
									else if (posicao == 0){
										e = inicializar_estado();
										contadorJogadas = 0;
										mostrar_tabuleiro(e);
									}
									if(obter_numero_de_jogadas(e) == 1){
									coord2 = criar_Coordenada(3,4);
									}
								}
								else
									if (gravar[0] == 'j' && gravar[1] == 'o' && gravar[2] == 'g' && gravar[3] == '2'){ //SE O COMANDO FOR JOG
										COORDENADA *proxJogada2;
											proxJogada2 = calcula_Distancia_Menor(e);
											coord2 = *proxJogada2;

											printf("\nJogada para: ");
											imprime(coord2);
											printf("\n");

											if (verifica_Posicao_Jogada(e, coord2) && verifica_CASA(e, coord2)) {
												
												if (obter_jogador_atual(e) == 1)
													jog1 [obter_numero_de_jogadas(e)] = coord2;
												else {
													jog2 [obter_numero_de_jogadas(e)] = coord2;
												}
													contadorJogadas++;
											}
											jogar(e, coord2);
											mostrar_tabuleiro(e);
									}
									else {

										if (gravar[0] == 'j' && gravar[1] == 'o' && gravar[2] == 'g') {
											LISTA jogadasPossiveis = criar_lista();
											jogadasPossiveis = listaJogadasPossiveis(e);
											COORDENADA *proxJogada;

											do {
												proxJogada = escolha_jogada(jogadasPossiveis, escolher_aleatorio(qts_Espacos_Vazios(e)));
											} while (verifica_Coordenada(*proxJogada) == 0);

												coord2 = *proxJogada;
												printf("\nJogada para: ");
												imprime(coord2);
												printf("\n");

											if (verifica_Posicao_Jogada(e, coord2) && verifica_CASA(e, coord2)) {
												if (obter_jogador_atual(e) == 1)
													jog1 [obter_numero_de_jogadas(e)] = coord2;
												else {
													jog2 [obter_numero_de_jogadas(e)] = coord2;
												}
													contadorJogadas++;
											}
											jogar(e, coord2);
											mostrar_tabuleiro(e);
											free(jogadasPossiveis);
										}
										else {
											printf("COMANDO INVALIDO!\n\n");
										}
									}
								}
			}
	} while (verifica_GANHOU(e) == 0 && verifica_PERDEU(e, coord2) == 0);

	printf("Acabou\n");
	felicitar(e);
	return 1;
}
//------------------------------------------------------------------------------------------------------------------------------
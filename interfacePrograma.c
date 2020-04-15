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
void movs_Consola(ESTADO *e, COORDENADA jog1[], COORDENADA jog2[], int number){
	int i;

	printf("\n");
	if (number%2 != 0){
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
	else{
		for (int f = 1; f < obter_numero_de_jogadas(e); f++){
			printf("[%02d]: ",f);
			imprime(jog1[f]);
			printf(" ");
			imprime(jog2[f]);
			printf("\n");
		}
		printf("\n");
	}
}
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
void movs(ESTADO *e, COORDENADA jog1[65], COORDENADA jog2[65], int number, char *file){
	
	int i;

	FILE *gravaMovimentos;

	gravaMovimentos = fopen (file, "a");
	
	fprintf(gravaMovimentos, "\n");

	if(number % 2 != 0){
		for (i = 1; i < obter_numero_de_jogadas(e); i++){
			
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

		for (int f = 1; f < obter_numero_de_jogadas(e); f++){
			
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
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
char* nome_Ficheiro (char linha[], char *file, int i) {

	int d;
	for (d = 0; ((linha[i] >= 'a' && linha[i] <= 'z') || (linha[i] >= 'A' && linha[i] <= 'Z')); d++) {  
			
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
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
void gr (ESTADO *e, char *file) {
	
	strcat(file, ".txt\0");

	FILE *jogo; 

	jogo = fopen (file, "w");

	//jogadaAtual = fopen("jogadaAtual.txt", "w");
	printf("A gravar...\n");

	for (int i = 0; i < 8; i++) {

		for (int a = 0; a < 8; a++)
			fprintf(jogo, "%c ", obter_estado_casa(e, criar_Coordenada(i, a)));
		
		fprintf(jogo, "\n");
	}

	fclose(jogo);
	//free (file);
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



//------------------------------------------------------------------------------------------------------------------------------
int confirmaImpar (FILE *jogo) { //-> Confirma se, na ultima jogada, tem 1 jogada ou 2
	
	int confirma = 1;
	int char2;
    
    fseek(jogo, -5, SEEK_END);
   	char duvida = fgetc(jogo);
   	
    
    fseek(jogo, -8, SEEK_END);
    char duvida2 = fgetc(jogo);

    char2 = duvida2 - '0';

    if (char2 >= 1 && char2 <= 8) 
    	confirma = 0;

    return confirma;
}
//------------------------------------------------------------------------------------------------------------------------------


/* void coords_para_array (FILE *jogo, int jogadasTotais, char jog1_4chars[], char jog2_4chars[]){ // jogadas totais

	size_t len = 0;
	char * line = NULL;
	ssize_t read;
   char mystring [100];
if ( fgets (mystring , 100 , jogo) != NULL )
       puts (mystring);
     fclose (jogo);

} */

//------------------------------------------------------------------------------------------------------------------------------
 void coords_para_array (FILE *jogo, int jogadasTotais, char jog1_4chars[], char jog2_4chars[]){ // jogadas totais

	char line [25];
    int contador = 150; //-> ignora o desenho do tabuleiro e comeca na primeira coordenada!
    int d = 0, e = 0, ajuda1 = 2, ajuda2 = 2;
    


    	fseek(jogo, contador, SEEK_SET);    
        for (int a = 1; a <= jogadasTotais; a++) { //-> Em vez do 'a' será o número do turno em que estas!

            if (a % 2 != 0) {
                for (d; d < ajuda1; d++){
                  
                	jog1_4chars[d] = fgetc(jogo);
               		
                }
                ajuda1 += 2;
                
                contador += 3; //-> ignorar o espaco entre as coorenadas do jog1 e do jog2!
                fseek(jogo, contador , SEEK_SET);
            }

            else{

            	if (a != jogadasTotais+1 || confirmaImpar(jogo) == 0) {

                    for (e; e < ajuda2; e++) {
                	   	jog2_4chars[e] = fgetc(jogo);
                		
               		}
                	ajuda2 += 2;
                
                	contador += 8; //-> numero de espacos para mudar de linha!
           			fseek(jogo, contador, SEEK_SET);
           		}
           	}	

                    
    	}
		char new_jog1_4chars[jogadasTotais];
		for(int i=0; i<jogadasTotais;i++) {
			new_jog1_4chars[i] = jog1_4chars[i];
		}
		for(int i=0; i<128;i++) {
			jog1_4chars[i] = '\0';
		}
		for(int i=0; i<jogadasTotais;i++) {
			jog1_4chars[i] = new_jog1_4chars[i];
		}
		// int c = 0;
		// char sub[] = jog1_4chars[];
		// jog1_4chars="";
		// while (c < jogadasTotais) {
      	// 	jog1_4chars[c] = sub[0+c];
      	// 	c++;
  		//  }
       // printf("%s STRING 1\n", jog1_4chars);
       // printf("%s STRING 2 \n", jog2_4chars);

}
 //------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
/*int ultima_jogada_ficheiro (FILE *jogo){
	 int nJogadas;
     int nJogadas2;
     int nFinal;


	 fseek(jogo, -10, SEEK_END);//-> Posição onde esta o ultimo algarismo da ultima jogada
        //fgets(line, sizeof line, jogo);
        //fputs(line, stdout);
        nJogadas = fgetc(jogo) - '0';
        
        fseek(jogo, -11, SEEK_END);//-> Posicao onde esta o primeiro algarismo da ultima jogada
        nJogadas2 = fgetc(jogo) - '0';
    
        if (nJogadas2 > 0 && nJogadas2 <= 9)
            nFinal = 10 * nJogadas2 + nJogadas;
        else
            nFinal = nJogadas;

        return nFinal;
}*/
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
		for (z; z <= jogadastotais-1; z++) {
			jogar(e, jog1[z]);
				
			jogar(e, jog2[z]);
				
		}

		jogar(e, jog1[z]);
	
	}
	//pos(jogadastotais, jog1, jog2, e);
}







//------------------------------------------------------------------------------------------------------------------------------
ESTADO *coords_de_ficheiro_jog (ESTADO *e, FILE *jogo, char jog1_4chars[], char jog2_4chars[], COORDENADA *jog1, COORDENADA *jog2, int jogadastotais) {

	//printf("%s this\n", jog1_4chars);

    int i = 1;
	for (int a = 0; a < jogadastotais*2; a += 2) { // -> O primeiro 2 é o numero de jogadas que há
           
		    int letra = letra_Numero(jog1_4chars[a]);

            //printf("%c <- char \n", jog1_4chars[a]);
            
            int numero = 8-(jog1_4chars[a + 1] - '0');
            
           // printf("letra %d numero %d\n", letra, numero);
            jog1[i] = criar_Coordenada(numero, letra);
            i++;
	}

    i = 1;
    for (int a = 0; a < jogadastotais*2; a += 2) { // -> O primeiro 2 é o numero de jogadas que há

        int letra = letra_Numero(jog2_4chars[a]);

        //printf("%s this\n", jog2_4chars);
        int numero = 8-(jog2_4chars[a + 1] - '0');
        //printf("letra %d numero %d\n", letra, numero);
        jog2[i] = criar_Coordenada(numero, letra);
        i++;
        
        }


    ajuda(e, jogo, jog1, jog2, jogadastotais);

}
//-----------------------------------------------------------------------------------------------------------------------------







//------------------------------------------------------------------------------------------------------------------------------
void pos(int jogada, COORDENADA jog1[], COORDENADA jog2[], ESTADO *e) {

	//printf("\n\n\n\n");
	//mostrar_tabuleiro(e);
	//printf("\n\n\n\n");
	if (verifica_Inicio_Jogo(e))
		atualiza_Num_Jogadas(e);
	//jogada += 1;

	if (jogada != 0) {

		for (int d = 1; d <= jogada; d++) {

			jogar(e, jog1[d]);
			//mostrar_tabuleiro(e);
			jogar(e, jog2[d]);
			//mostrar_tabuleiro(e);
		}
		mostrar_tabuleiro(e);
	}
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
int ler (char *file, ESTADO *e, COORDENADA *jog1, COORDENADA *jog2) {
	
	char linha[40];
	int jogadastotais = 0;
	char jog1_4chars[128];
    char jog2_4chars [128];
    int number=0;

	strcat(file, ".txt\0");

	FILE *jogo;
	
	jogo = fopen(file, "r");

	while ( fgets(linha, sizeof(linha), jogo) ) {
		jogadastotais++;
		printf("%s", linha);
	}
	
	jogadastotais -= 10;
	printf("%d\n", jogadastotais );
	if (confirmaImpar(jogo) == 0){
		number = jogadastotais*2;
	}
	else{
		number = jogadastotais*2+1;
	}

	coords_para_array(jogo, jogadastotais*2, jog1_4chars, jog2_4chars);

	//coords_de_ficheiro_jog1(jogo, jog1_4chars, jog1, jogadastotais);
	//coords_de_ficheiro_jog2(jogo, jog2_4chars, jog2, jogadastotais);
	coords_de_ficheiro_jog(e, jogo, jog1_4chars, jog2_4chars, jog1, jog2, jogadastotais);

	//imprime(jog2[]);
	//printf("primeiro elemtno ^\n");

	
	mostrar_tabuleiro(e);

	fclose(jogo);

	return number;
}	// -> Lê o ficheiro que contém a última jogada efetuada.
//------------------------------------------------------------------------------------------------------------------------------


/*COORDENADA* jog1_Atualizado (COORDENADA jog1[], int jogada) {

	COORDENADA jog1_Novo[jogada + 1];

	for (int d = 0; d < jogada + 1; d++) {
		jog1_Novo[d] = jog1[d];
	}

	return jog1_Novo;
}
*/




//------------------------------------------------------------------------------------------------------------------------------










//------------------------------------------------------------------------------------------------------------------------------
int interpretador(ESTADO *e) {
	
	char linha[BUF_SIZE];
	char col[2], lin[2], *file, gravar[7], posicao_Lida[3];
	COORDENADA coord2;
	COORDENADA jog1 [65];
	COORDENADA jog2 [65];
	int number = 0;
	posicao_Lida[2] = '\0';
	int guardarJogadaPos =  0;

	do {
		file = (char *) malloc(2);

		prompt_INFO(e);
	
		if (fgets(linha, BUF_SIZE, stdin) == NULL)
			return 0;

		if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {

		//printf("COLUNA %d, LINHA %d\n", *col - 'a', (*lin - '1'));// -> Alterações necessárias face à nossa interpretação da matriz, presente em RASCUNHOS.Ht
		
			COORDENADA coord = {*col - 'a', 7 - (*lin - '1') };
		
			coord2 = coord;			
		
			if (verifica_Posicao_Jogada(e, coord2) && verifica_CASA(e, coord2)) {

				if (obter_jogador_atual(e) == 1)
					jog1 [obter_numero_de_jogadas(e)] = coord2;
			
				else
					jog2 [obter_numero_de_jogadas(e)] = coord2;
			
				number++;
			}



			if (jogar(e, coord)) { // -> O facto de a própria jogada ser argumento do if, não faz com que ele "funcione", em vez de só o verificar??
				mostrar_tabuleiro(e);
				guardarJogadaPos = 0;
//			gr(ficheiro, e); -> Só deve gravar quando se dá o respetivo comando.
			}

			//number++;
		}
	
		else
			if (strlen(linha) == 2 && strcmp(linha, "q\n") == 0)
				Q();
	
			else {
					for (int a = 0; a < 5; a++)
						gravar[a] = linha[a];
					gravar[6] = '\0'; // -> Grava a instrução "gr ", "ler " ou "movs "
				
					if (gravar[0] == 'g' && gravar[1] == 'r' && gravar[2] == ' ') { // SE O COMANDO FOR GRAVAR
						int i = 3; // Contador inicializar a 3 espaços "gr " <- ignora

						int d = 0;

						for (d; (linha[i] >= 'a' && linha[i] <= 'z'); d++) { //|| (linha[i] >= 'A' && linha[i] <= 'Z')); d++) {  
			
							if (file[d]) {
					
								file[d] = linha[i];
								i++;
							}
				
							else { 
				
								file = (char *) realloc(file, d + 10);
								file[d] = linha[i];
								i++;
							}
						}

						//printf("string aqui %s\n", file);

						file[d] = '\0'; //-> Recebe o nome do ficheiro onde é suposto ser guardado o jogo
						
						//printf("%s wow tamanho %d\n", file, strlen(file));
						//	printf("%s\n", file);
						
						gr(e, file); // Não tentar gravar à primeira, porque o jogo nem inicializou! É só uma "visualizacao" do tabuleiro.
						
						movs(e, jog1, jog2, number, file);
						
						free(file);

						if(obter_numero_de_jogadas(e) == 1){
							coord2 = criar_Coordenada(3,4);
						}
						
					}

					else
						if (gravar[0] == 'l' && gravar[1] == 'e' && gravar[2] == 'r' && gravar[3] == ' ') { // -> SE O COMANDO FOR LER
							int i = 4;
							nome_Ficheiro(linha, file, i);
							e = inicializar_estado();
							number = 0;
							number = ler(file,e,jog1,jog2);

							free(file);

							if(obter_numero_de_jogadas(e) == 1){
								coord2 = criar_Coordenada(3,4);
							}



													
						}

						else
							if (gravar[0] == 'm' && gravar[1] == 'o' && gravar[2] == 'v' && gravar[3] == 's')
							{
								printf("%d\n",number );
								movs_Consola(e, jog1, jog2, number);
								if(obter_numero_de_jogadas(e) == 1){
									coord2 = criar_Coordenada(3,4);
								}
							}
							else{
								if (gravar[0] == 'p' && gravar[1] == 'o' && gravar[2] == 's' && gravar[3] == ' ') {

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
										number = 0;
									}
									else if (posicao == 0){
										e = inicializar_estado();
										number = 0;
										mostrar_tabuleiro(e);
									}
									if(obter_numero_de_jogadas(e) == 1){
									coord2 = criar_Coordenada(3,4);
									}
								}
							
								else {
									printf("COMANDO INVALIDO!\n\n");
									
								}
							}
								
			}

	} while (verifica_GANHOU(e, coord2) == 0 && verifica_PERDEU(e, coord2) == 0);
	printf("Acabou\n");

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
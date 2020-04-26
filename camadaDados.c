
#include <stdlib.h>
#include <string.h>
#include "bases.h"
#include "camadaDados.h"

//------------------------------------------------------------------------------------------------------------------------------

ESTADO *inicializar_estado() {

	ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
	char NUM[] = {'8','7','6','5','4','3','2','1', ' '};
    char LTR[] = {'A','B','C','D','E','F','G','H', ' '};
	
	e -> jogador_atual = 1;
	e -> num_jogadas = 0;
	e -> jogadas[32]; // ou 0, e vai, no máximo, até 32 (?).
	e -> ultima_jogada.coluna = 4;
	e -> ultima_jogada.linha = 3;

		for (int i = 0; i < 9; i++) { //Por cada linha

        for (int d = 0; d < 9; d++){     //Verifica o elemento de cada coluna
            if (d == 8){
                e -> tab [i][d] = NUM[i];
            }
            else if ( i == 8){
                e -> tab [i][d] = LTR[d];
            }
            else
            e -> tab[i][d] = VAZIA;    //Atribuindo o valor VAZIA a todos
        }
    }

	e -> tab[0][7] = DOIS;	//Peça Inicial
	e -> tab[7][0] = UM;	//Peça Inicial
	e -> tab[3][4] = BRANCA;   //A posição inicial começa nesta posição com uma peça '*'.

	return e;
} // -> Cria um estado vazia (com o tabuleiro inicializado).
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
int obter_jogador_atual(ESTADO *estado) {

	return estado -> jogador_atual;

} // -> Obtém o número do jogador atual.
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
int obter_numero_de_jogadas(ESTADO *estado) {

	return estado -> num_jogadas;

} // -> Permite obter quantas jogadas já foram efetuadas (cada jogada tem o movimento de 2 jogadores).
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
CASA obter_estado_casa(ESTADO *e, COORDENADA c) {

	return e -> tab[c.linha][c.coluna];
	
} // -> Permite obter o estado atual da casa.
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
int obter_Coluna_Atual (ESTADO *e) {
	
	return e -> ultima_jogada.coluna;

} // -> Devolve a coluna em que a peça está.
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
int obter_Linha_Atual (ESTADO *e) {
	
	return e -> ultima_jogada.linha;

} // -> Devolve a linha em que a peça está.
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
COORDENADA obter_Ultima_Jogada (ESTADO *e) {

	return e -> ultima_jogada;
} // -> Devolve as coordenadas da última jogada registado no ESTADO.
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
COORDENADA criar_Coordenada (int linha, int coluna) {

	COORDENADA *c;
    c = malloc(sizeof(COORDENADA));
	c->linha = linha;
	c->coluna = coluna;
	return *c; 
} // -> Dados dois inteiros, cria uma COORDENADA com esses dados.
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
ESTADO* atualiza_Casas (ESTADO *e, COORDENADA c, CASA qqer) {

	e -> tab[c.linha][c.coluna] = qqer;
	return e;
} // -> Dado um ESTADO, uma coordenada específica e um dado do tipo CASA, atualiza ,no ESTADO, a CASA dessa coordenada para 'qqer' 
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
ESTADO *atualiza_Ultima_Jogada (ESTADO *e, COORDENADA atualizada) {

	e -> ultima_jogada = atualizada;
	return e;
} // -> Devolve um ESTADO com as COORDENADAS da última jogada efetuada devidamente atualizada.
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
ESTADO *atualiza_Jogador (ESTADO *e) {

	if (obter_jogador_atual(e) == 1)
		e -> jogador_atual = 2;
	else
		e -> jogador_atual = 1;

	return e;
} // -> Devolve um ESTADO onde, casa tenha sido o jogador[1] a jogar, atualiza para o jogador[2], e vice-versa.
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
ESTADO *atualiza_Num_Jogadas (ESTADO *e) {

	if (obter_jogador_atual(e) == 1)// || obter_numero_de_jogadas(e) == 0) //Por alguma razão, se o obterjogador fosse 2 dava erro.
		e -> num_jogadas += 1;

	return e;
} // -> Devolve um ESTADO com o número de jogadas atualizado, i.e., caso tenha sido o jogador[2] o último a jogar, adiciona 1 ao num_jogadas.
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
int verifica_Inicio_Jogo (ESTADO *e) {

	if (obter_estado_casa(e, criar_Coordenada(3, 4)) == BRANCA)
		return 1;
	else
		return 0;
}
//------------------------------------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------------------------------------------
void perdeste(int x) {

	if (x == 1)
		printf("A jogada que tentaste fazer e impossivel.\n");
	else
		if (x == 2)
			printf("Esta jogada fez com que perdesses o jogo :c\n");
		}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
char letra_Coordenada (COORDENADA c) {

    char colunaLetra = numero_Letra(c.coluna);

    //printf("%c%d", colunaLetra, (8 - c.linha));
    return colunaLetra;
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
void imprime (COORDENADA c) {

    char colunaLetra = numero_Letra(c.coluna);

    printf("%c%d", colunaLetra, (8 - c.linha));

}

//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
char numero_Letra(int x) {

    char final;
    switch (x) {

        case 0 : final = 'a';
        break;
        case 1 : final = 'b';
        break;
        case 2 : final = 'c';
        break;
        case 3 : final = 'd';
        break;
        case 4 : final = 'e';
        break;
        case 5 : final = 'f';
        break;
        case 6 : final = 'g';
        break;
        case 7 : final = 'h';
        break;
    }
    return final;
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
int letra_Numero(char x) {

    int final;
    switch (x) {

        case 'a' : final = 0;
        break;
        case 'b' : final = 1;
        break;
        case 'c' : final = 2;
        break;
        case 'd' : final = 3;
        break;
        case 'e' : final = 4;
        break;
        case 'f' : final = 5;
        break;
        case 'g' : final = 6;
        break;
        case 'h' : final = 7;
        break;
    }
    return final;
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
int array_To_Int(int posAnterior[]) {

	int x = posAnterior[0];
	int y = posAnterior[1];
	int final;
	
	if (posAnterior[0] >= 0 && posAnterior[1] <= 9 && posAnterior[1] >= 0)
		final = x * 10 + y;
	else
		final = x;

	return x;
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
int verifica_Coordenada (COORDENADA c) {

    char colunaLetra = numero_Letra(c.coluna);
    int linha = 8 - c.linha;

    if (colunaLetra >= 'a' && colunaLetra <= 'h') {
        if (linha >= 1 && linha <= 8)
            return 1;
    }
    else
        return 0;
}
//------------------------------------------------------------------------------------------------------------------------------




//QUESTÃO
//Qual a necessidade de as funções que devolvem ESTADO terem um '*' antes do seu nome??????????
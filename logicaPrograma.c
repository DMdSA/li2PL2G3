#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int jogar(ESTADO *e, COORDENADA c) {
	
	printf("jogar %d %d\n", c.coluna, c.linha);
	return 1;

}
//Recebe o estadoAtual e uma coordenada -> Modifica o estado ao jogar na casa correta SE a jogada for válida.
//Devolve VDD (!= 0) se for possível jogar.
//Devolve F (== 0) caso não seja possível.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "bases.h"
#include "camadaDados.h"
#include "logicaPrograma.h"
#include "interfacePrograma.h"


int main() {

	srand (time (NULL));

    ESTADO *e = inicializar_estado();

    mostrar_tabuleiro(e);

	interpretador(e);

    return 0;
}
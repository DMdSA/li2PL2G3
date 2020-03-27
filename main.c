#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bases.h"
#include "camadaDados.h"
#include "logicaPrograma.h"
#include "interfacePrograma.h"

int main() {
    FILE *jogo;
    ESTADO *e = inicializar_estado();
    gr(jogo, e);


    mostrar_tabuleiro(e);

   	interpretador(e);

    return 0;
}
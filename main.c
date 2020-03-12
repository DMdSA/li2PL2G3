#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "camadaDados.h"
#include "logicaPrograma.h"
#include "interfacePrograma.h"


int main() {

	ESTADO *e = inicializar_estado();

	interpretador(e);
	
	return 0;
}
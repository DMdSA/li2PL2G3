#ifndef INTERFACE_FILE
#define INTERFACE_FILE

void prompt_INFO (ESTADO *e);

void mostrar_tabuleiro(ESTADO *e);

void gr (ESTADO *e, char *ficheiro);

//void ler (char *ficheiro);

int interpretador(ESTADO *e);

void movs(ESTADO *e, COORDENADA jog1[65], COORDENADA jog2[65], int number, char *file);

#endif
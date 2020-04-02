#ifndef INTERFACE_FILE
#define INTERFACE_FILE

void prompt_INFO (ESTADO *e);

void mostrar_tabuleiro(ESTADO *e);

void gr (ESTADO *e, char *file);

void ler (char *file);

int interpretador(ESTADO *e);

void movs(ESTADO *e, COORDENADA jog1[65], COORDENADA jog2[65], int number, char *file);

char* nome_Ficheiro (char linha[], char *file, int i);

void movs_Consola(ESTADO *e, COORDENADA jog1[65], COORDENADA jog2[65], int number);

#endif
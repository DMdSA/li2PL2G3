#ifndef INTERFACE_FILE
#define INTERFACE_FILE

void prompt_INFO (ESTADO *e);

void mostrar_tabuleiro(ESTADO *e);

void gr (FILE *jogadaAtual, ESTADO *e);

void ler (FILE *ficheiro);

int interpretador(ESTADO *e);

#endif

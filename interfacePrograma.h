#ifndef INTERFACE_FILE
#define INTERFACE_FILE

void prompt_INFO (ESTADO *e);

void mostrar_tabuleiro(ESTADO *e);

void gr (ESTADO *e, char *file);

int ler (char *file, ESTADO *e, COORDENADA *jog1, COORDENADA *jog2);

int interpretador(ESTADO *e);

void movs(ESTADO *e, COORDENADA jog1[65], COORDENADA jog2[65], int number, char *file);

char* nome_Ficheiro (char linha[], char *file, int i);

void movs_Consola(ESTADO *e, COORDENADA jog1[65], COORDENADA jog2[65], int number);

void pos (int jogada, COORDENADA jog1[], COORDENADA jog2[], ESTADO *e);

void coords_para_array (FILE *jogo, int jogadastotais, char jog1_4chars[], char jog2_4chars[]);

void coords_de_ficheiro_jog (ESTADO *e, FILE *jogo, char jog1_4chars[], char jog2_4chars[], COORDENADA *jog1, COORDENADA *jog2, int jogadastotais);


int confirmaImpar (FILE *jogo);

void ajuda (ESTADO *e, FILE *jogo, COORDENADA *jog1, COORDENADA *jog2, int jogadastotais);


#endif
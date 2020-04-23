  
#ifndef LOGICA_FILE
#define LOGICA_FILE

int verifica_Posicao_Jogada (ESTADO *e, COORDENADA c);

int verifica_CASA (ESTADO *e, COORDENADA c);

int verifica_PERDEU (ESTADO *e, COORDENADA c);

int verifica_GANHOU (ESTADO *e, COORDENADA c);

void felicitar(ESTADO *e);

void jogada_Intermedia (ESTADO *e, COORDENADA c);

void jogada_Vencedora(ESTADO *e, COORDENADA c);

int antecipa_Possibilidade_Jogada (ESTADO *e, COORDENADA c);

int jogar (ESTADO *e, COORDENADA c);

#endif
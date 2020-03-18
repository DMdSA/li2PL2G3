#ifndef DADOS_FILE
#define DADOS_FILE

ESTADO *inicializar_estado();

int obter_jogador_atual(ESTADO *estado);

int obter_numero_de_jogadas(ESTADO *estado);

CASA obter_estado_casa(ESTADO *e, COORDENADA c);

int obter_Coluna_Atual (ESTADO *e);

int obter_Linha_Atual (ESTADO *e);

COORDENADA criar_Coordenada (int linha, int coluna);

#endif

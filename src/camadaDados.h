/**
@file camadaDados.h
Definição do estado e das unções que o manipulam.
*/
#ifndef DADOS_FILE
#define DADOS_FILE

/**
\brief Inicializa o valor do estado
Esta função inicializa o valor do estado. Isso implica o tabuleiro ser colocado na posição inicial e todos os campos do estado estarem com o valor por omissão.
@returns O novo estado
*/
ESTADO *inicializar_estado();


/**
\brief Devolve o número do jogador atual
@param estado Apontador para o estado
*/
int obter_jogador_atual(ESTADO *estado);


/**
\brief Devolve o número de jogadas que já foram efetuadas
@param estado Apontador para o estado
*/
int obter_numero_de_jogadas(ESTADO *estado);


/**
\brief Devolve o dado do tipo CASA associado a uma coordenada
@param e Apontador para o estado
@param c A coordenada
*/
CASA obter_estado_casa(ESTADO *e, COORDENADA c);


/**
\brief Devolve o valor inteiro da coluna em que o jogador atual se encontra
@param e Apontador para o estado
*/
int obter_Coluna_Atual (ESTADO *e);


/**
\brief Devolve o valor inteiro da linha em que o jogador atual se encontra
@param e Apontador para o estado
*/
int obter_Linha_Atual (ESTADO *e);


/**
\brief Devolve as coordenadas da última jogada guardada no ESTADO
@param e Apontador para o estado
*/
COORDENADA obter_Ultima_Jogada (ESTADO *e);


/**
\brief Cria um dado do tipo COORDENADA com os inteiros linha e coluna associados
@param linha A linha da coordenada
@param coluna A coluna da coordenada
@returns Coordenada com os valores dados
*/
COORDENADA criar_Coordenada (int linha, int coluna);


/**
\brief Atualiza, dentro do estado, o tipo CASA da coordenada associada para 'qqer' 
@param e Apontador para o estado
@param c Coordenada dada
@param qqer Casa atribuída para a substituição
@returns Estado com a CASA da coordenada atualizada
*/
ESTADO* atualiza_Casas (ESTADO *e, COORDENADA c, CASA qqer);


/**
\brief Atualiza o estado substituindo as coordenadas da ultima_jogada
@param e Apontador para o estado
@param atualizada A coordenada atualizada, que vai substituir a antiga
@returns Estado com a ultima_jogada atualizada
*/
ESTADO *atualiza_Ultima_Jogada (ESTADO *e, COORDENADA atualizada);


/**
\brief Atualiza o número do jogador
@param e Apontador para o estado
@returns Estado com o número do jogador devidamente atualizado
*/
ESTADO *atualiza_Jogador (ESTADO *e);


/**
\brief Atualiza o número de jogadas
@param e Apontador para o estado
@returns Estado com o numero de jogadas devidamente atualizado
*/
ESTADO *atualiza_Num_Jogadas (ESTADO *e);


/**
\brief Verifica se o jogo se encontra na sua fase inicial
@param e Apontador para o estado
@returns Verdade (1), se o jogo estiver no seu início, ou Falso (0), caso contrário
*/
int verifica_Inicio_Jogo (ESTADO *e);


/**
\brief Informa o jogador de que perdeu o jogo
@param x Referente ao tipo de frase que deve apresentar
*/
void perdeste(int x);


/**
\brief Transforma o inteiro da coordenada ligado a uma coluna à respetiva letra que lhe está associada
@param c Coordenada a analisar
*/
char letra_Coordenada(COORDENADA c);


/**
\brief Imprime, na consola, uma coordenada
@param c Coordeanda a imprimir
*/
void imprime (COORDENADA c);


/**
\brief Transforma um número na letra que lhe está associado, no tabuleiro
@param x Inteiro a transformar
@returns Letra correspondente ao inteiro
*/
char numero_Letra(int x);


/**
\brief Transforma uma letra do tabuleiro num inteiro referente à matriz criada, por base
@param x Letra a transformar
@returns Letra transformada
*/
int letra_Numero(char x);


/**
\brief Verifica se uma coordenada realmente está dentro da definição utilizada pelo tabuleiro
@param c Coordenada a analisar
@returns 1, caso seja uma coordenada na forma pretendida, 0 caso contrário
*/
int verifica_Coordenada (COORDENADA c);


/**
\brief Devolve o inteiro associado à coluna de uma coordenada
@param c Coordenada a analisar
@returns Inteiro associado à coluna
*/
int coluna_Coord(COORDENADA c);


/**
\brief Devolve o inteiro associado à linha de uma coordenada
@param c Coordenada a analisar
@returns Inteiro associado à linha
*/
int linha_Coord(COORDENADA c);

#endif
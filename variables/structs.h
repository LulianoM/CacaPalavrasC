#include "variables.h"

struct informacoesPalavra
{
    int  iColuna;
    int  iLinha;
    char szPalavra[TAMANHO_MAX_PALAVRA];
    char cOrientacao;
};

struct informacoesPosicao
{
    int  iTamanhoPalavra;
    int  iLinha;
    int  iColuna;
    char cOrientacao;
};
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

#include "../variables/variables.h"
#include "../variables/structs.h"

vector<informacoesPalavra> posiciona_palavras(vector<string> aPalavras, vector<vector<UCHAR>>& aaTabuleiro)
{
    vector<informacoesPalavra> aInformacoesPalavra;
    aInformacoesPalavra.reserve(aPalavras.size());

    for (const string& sPalavra : aPalavras)
    {
        srand(time(NULL));

        informacoesPalavra informacoesPalavra = {0};
        copy(sPalavra.begin(), sPalavra.end(), informacoesPalavra.szPalavra);

        unsigned int iTentativas = 0;
        while (iTentativas++ < 1000000)
        {
            informacoesPalavra.cOrientacao = gera_orientacao();

            int iColuna = rand() % aaTabuleiro.size();
            while (iColuna + sPalavra.length() > aaTabuleiro.size())
                --iColuna;

            int iLinha = iLinha = rand() % aaTabuleiro.size();;
            while (iLinha + sPalavra.length() > aaTabuleiro.size())
                --iLinha;

            informacoesPalavra.iLinha  = iLinha;
            informacoesPalavra.iColuna = iColuna;

            vector<vector<UCHAR>> aaTabuleiroLocal = aaTabuleiro;
            bool bSucesso = false;

            switch (informacoesPalavra.cOrientacao)
            {
                case VERTICAL: bSucesso = posiciona_vertical(aaTabuleiroLocal, sPalavra, iColuna, iLinha); break;
                case HORIZONTAL: bSucesso = posiciona_horizontal(aaTabuleiroLocal, sPalavra, iColuna, iLinha); break;
                case DIAGONAL: bSucesso = posiciona_diagonal(aaTabuleiroLocal, sPalavra, iColuna, iLinha); break;
            }

            if (bSucesso)
            {
                aaTabuleiro = aaTabuleiroLocal;
                break;
            }
        }

        if (iTentativas >= 1000000)
            continue;

        aInformacoesPalavra.push_back(informacoesPalavra);
    }

    return aInformacoesPalavra;
}

char gera_orientacao()
{
    srand(time(NULL));

    int iOrientacao = rand() % 3 + 1;

    switch (iOrientacao)
    {
        case 1: return VERTICAL;
        case 2: return HORIZONTAL;
        case 3: return DIAGONAL;
    }

    return HORIZONTAL;
}


bool posiciona_vertical(vector<vector<UCHAR>>& aaTabuleiro, const string& sPalavra, int iColuna, int iLinha)
{
    for (UCHAR cLetra : sPalavra)
    {
        if (aaTabuleiro[iLinha][iColuna] == 0 || aaTabuleiro[iLinha][iColuna] == cLetra)
            aaTabuleiro[iLinha++][iColuna] = cLetra;
        else
            return false;
    }

    return true;
}

bool posiciona_horizontal(vector<vector<UCHAR>>& aaTabuleiro, string sPalavra, int iColuna, int iLinha)
{
    for (UCHAR cLetra : sPalavra)
    {
        if (aaTabuleiro[iLinha][iColuna] == 0 || aaTabuleiro[iLinha][iColuna] == cLetra)
            aaTabuleiro[iLinha][iColuna++] = cLetra;
        else
            return false;
    }

    return true;
}

bool posiciona_diagonal(vector<vector<UCHAR>>& aaTabuleiro, string sPalavra, int iColuna, int iLinha)
{
    for (UCHAR cLetra : sPalavra)
    {
        if (aaTabuleiro[iLinha][iColuna] == 0 || aaTabuleiro[iLinha][iColuna] == cLetra)
            aaTabuleiro[iLinha++][iColuna++] = cLetra;
        else
            return false;
    }

    return true;
}
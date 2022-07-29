#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

#include "../variables/variables.h"
#include "../variables/structs.h"

using namespace std;

bool valida_parametros(string& sEntrada, const vector<vector<UCHAR>>& aaTabuleiro, informacoesPosicao& stInformacoesPosicao)
{
    if (sEntrada.length() < 4)
        return false;

    int idxEntrada = 0;
    bool bParametroValido = true;

    stInformacoesPosicao.iColuna = toupper(sEntrada[idxEntrada++]) - 65;

    if (sEntrada[idxEntrada] >= 48 && sEntrada[idxEntrada] <= 57)
    {
        string sLinha;
        sLinha += sEntrada[idxEntrada++];

        if (sEntrada[idxEntrada] >= 48 && sEntrada[idxEntrada] <= 57)
        {
            sLinha += sEntrada[idxEntrada++];

            if (sEntrada[idxEntrada] >= 48 && sEntrada[idxEntrada] <= 57)
                return false;
        }

        stInformacoesPosicao.iLinha = stoi(sLinha) - 1;
    }

    stInformacoesPosicao.cOrientacao = toupper(sEntrada[idxEntrada++]);
    stInformacoesPosicao.iTamanhoPalavra = stoi(sEntrada.substr(idxEntrada, sEntrada.length() - idxEntrada));
    
    if (stInformacoesPosicao.iColuna > aaTabuleiro.size())
        bParametroValido = false;
    else if (stInformacoesPosicao.iLinha > aaTabuleiro.size())
        bParametroValido = false;
    else if (stInformacoesPosicao.cOrientacao != 'V' && stInformacoesPosicao.cOrientacao != 'H' && stInformacoesPosicao.cOrientacao != 'D')
        bParametroValido = false;
    else if (stInformacoesPosicao.iTamanhoPalavra > TAMANHO_MAX_PALAVRA)
        bParametroValido = false;

    if (!bParametroValido)
    {
        cout << endl << "Por favor insira parametros validos" << endl;
        getchar();
    }

    return bParametroValido;
}

bool verifica_tabuleiro(const vector<informacoesPalavra>& astInformacoesPalavras)
{
    for (const informacoesPalavra& stInformacoesPalavra : astInformacoesPalavras)
    {
        if (!stInformacoesPalavra.bMarcada)
            return false;
    }

    return true;
}

bool verifica(vector<informacoesPalavra> astInformacoesPalavras, informacoesPosicao stInformacoesPosicao)
{
    for (const informacoesPalavra& stInformacoesPalavra : astInformacoesPalavras)
    {
        if (stInformacoesPalavra.bMarcada)
            continue;

        int a = string(stInformacoesPalavra.szPalavra).length();

        if (stInformacoesPalavra.iLinha                     == stInformacoesPosicao.iLinha      &&
            stInformacoesPalavra.iColuna                    == stInformacoesPosicao.iColuna     &&
            stInformacoesPalavra.cOrientacao                == stInformacoesPosicao.cOrientacao &&
            string(stInformacoesPalavra.szPalavra).length() == stInformacoesPosicao.iTamanhoPalavra)
        {
            return true;
        }
    }

    return false;
}
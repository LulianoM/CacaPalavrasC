#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

#include "../variables/variables.h"
#include "../variables/structs.h"

void marca_horizontal(vector<vector<UCHAR>>& aaTabuleiro, const informacoesPosicao& stInformacoesPosicao, vector<informacoesPalavra>& astInformacoesPalavras)
{
    for (informacoesPalavra& stInformacoesPalavra : astInformacoesPalavras)
    {
        if (stInformacoesPalavra.bMarcada)
            continue;

        if (stInformacoesPalavra.iLinha                     == stInformacoesPosicao.iLinha      &&
            stInformacoesPalavra.iColuna                    == stInformacoesPosicao.iColuna     &&
            stInformacoesPalavra.cOrientacao                == stInformacoesPosicao.cOrientacao &&
            string(stInformacoesPalavra.szPalavra).length() == stInformacoesPosicao.iTamanhoPalavra)
        {
            stInformacoesPalavra.bMarcada = true;
            int iTamanhoPalavra = stInformacoesPosicao.iTamanhoPalavra;

            int idxColuna = stInformacoesPalavra.iColuna;
            int idxLinha  = stInformacoesPalavra.iLinha;

            while (iTamanhoPalavra--)
            {
                aaTabuleiro[idxLinha][idxColuna] = toupper(aaTabuleiro[idxLinha][idxColuna]);
                ++idxColuna;
            }

            break;
        }
    }
}

void marca_vertical(vector<vector<UCHAR>>& aaTabuleiro, const informacoesPosicao& stInformacoesPosicao, vector<informacoesPalavra>& astInformacoesPalavras)
{
    for (informacoesPalavra& stInformacoesPalavra : astInformacoesPalavras)
    {
        if (stInformacoesPalavra.bMarcada)
            continue;

        if (stInformacoesPalavra.iLinha                     == stInformacoesPosicao.iLinha      &&
            stInformacoesPalavra.iColuna                    == stInformacoesPosicao.iColuna     &&
            stInformacoesPalavra.cOrientacao                == stInformacoesPosicao.cOrientacao &&
            string(stInformacoesPalavra.szPalavra).length() == stInformacoesPosicao.iTamanhoPalavra)
        {
            stInformacoesPalavra.bMarcada = true;
            int iTamanhoPalavra = stInformacoesPosicao.iTamanhoPalavra;

            int idxColuna = stInformacoesPalavra.iColuna;
            int idxLinha  = stInformacoesPalavra.iLinha;

            while (iTamanhoPalavra--)
            {
                aaTabuleiro[idxLinha][idxColuna] = toupper(aaTabuleiro[idxLinha][idxColuna]);
                idxLinha++;
            }
        }
    }
}

void marca_diagonal(vector<vector<UCHAR>>& aaTabuleiro, const informacoesPosicao& stInformacoesPosicao, vector<informacoesPalavra>& astInformacoesPalavras)
{
    for (informacoesPalavra& stInformacoesPalavra : astInformacoesPalavras)
    {
        if (stInformacoesPalavra.bMarcada)
            continue;

        if (stInformacoesPalavra.iLinha                     == stInformacoesPosicao.iLinha      &&
            stInformacoesPalavra.iColuna                    == stInformacoesPosicao.iColuna     &&
            stInformacoesPalavra.cOrientacao                == stInformacoesPosicao.cOrientacao &&
            string(stInformacoesPalavra.szPalavra).length() == stInformacoesPosicao.iTamanhoPalavra)
        {
            stInformacoesPalavra.bMarcada = true;
            int iTamanhoPalavra = stInformacoesPosicao.iTamanhoPalavra;

            int idxColuna = stInformacoesPalavra.iColuna;
            int idxLinha  = stInformacoesPalavra.iLinha;

            while (iTamanhoPalavra--)
            {
                aaTabuleiro[idxLinha++][idxColuna++] = toupper(aaTabuleiro[idxLinha][idxColuna]);
                ++idxLinha;
                ++idxColuna;
            }
        }
    }
}
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

#include "../variables/variables.h"
#include "../variables/structs.h"

using namespace std;

#pragma region Defines

#pragma endregion

#pragma region Estruturas

vector<string> le_caca_palavras(string sCaminhoArquivo)
{
    vector<string> aPalavras;

    string sPalavra;
    ifstream arquivo(sCaminhoArquivo);

    while (getline(arquivo, sPalavra))
    {
        if (aPalavras.size() >= NUM_MAX_PALAVRAS)
            break;

        if (sPalavra.length() > TAMANHO_MAX_PALAVRA)
            continue;

        transform(sPalavra.begin(), sPalavra.end(), sPalavra.begin(), tolower);

        aPalavras.push_back(sPalavra);
    }

    return aPalavras;
}

vector<vector<UCHAR>> cria_tabuleiro(vector<string> aPalavras)
{
    size_t tamanhoTabuleiro = 0;

    for (const string& sPalavra : aPalavras)
    {
        if (sPalavra.length() > tamanhoTabuleiro)
            tamanhoTabuleiro = sPalavra.length();
    }

    vector<vector<UCHAR>> aaTabuleiro(tamanhoTabuleiro + 5);

    for (vector<UCHAR>& aTabuleiro : aaTabuleiro)
        aTabuleiro.resize(tamanhoTabuleiro + 5);

    return aaTabuleiro;
}

void imprime(vector<vector<UCHAR>>& aaTabuleiro)
{
    system("clear||cls");

    cout << "     ";
    for (size_t idx = 0; idx < aaTabuleiro.size(); ++idx)
        cout << (UCHAR) (idx + 65) << ' ';

    cout << endl;

    cout << "   --";
    for (size_t idx = 0; idx < aaTabuleiro.size(); ++idx)
        cout << "--";

    cout << endl;

    int idxLinha = 1;
    for (vector<UCHAR>& aTabuleiro : aaTabuleiro)
    {
        cout << idxLinha << ' ';

        if (idxLinha++ < 10)
            cout << ' ';

        cout << "| ";

        for (UCHAR& cLetra : aTabuleiro)
        {
            if (cLetra == 0)
                cLetra = rand() % 25 + 97;

            cout << cLetra << ' ';
        }

        cout << endl;
    }
}
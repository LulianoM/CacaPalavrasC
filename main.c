#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "functions/create_board.c"
#include "functions/mark_words.c"
#include "functions/position_words.c"
#include "functions/show_board_and_words.c"
#include "functions/validate.c"

#include "variables/variables.h"
#include "variables/structs.h"




void inicia_jogo()
{
    vector<string> aPalavras = le_caca_palavras("D:\\palavras.txt");

    vector<vector<UCHAR>> aaTabuleiro = cria_tabuleiro(aPalavras);
    cout << "Gerando Tabuleiro..." << endl;
    vector<informacoesPalavra> astInformacoesPalavras = posiciona_palavras(aPalavras, aaTabuleiro);

    system("clear||cls");

    bool bJogoAcabou = false;

    do
    {
        imprime(aaTabuleiro);
        cout << endl;
        imprime_palavras(astInformacoesPalavras);
        cout << endl;

        cout << endl << "Digite uma Coluna e uma Linha, a Orientacao da palavra ('V', 'H', 'D') e o Tamanho da palavra:" << endl;
        string sEntrada;
        getline(cin, sEntrada);

        sEntrada.erase(remove_if(sEntrada.begin(), sEntrada.end(), [] (char c) {return c == ' ';} ), sEntrada.end());

        informacoesPosicao stInformacoesPosicao = {0};
        if (!valida_parametros(sEntrada, aaTabuleiro, stInformacoesPosicao))
            continue;

        bool bAchouPalavra = verifica(astInformacoesPalavras, stInformacoesPosicao);

        if (!bAchouPalavra)
        {
            cout << endl << "Errou! Tente novamente!" << endl;
            getchar();
            continue;
        }

        switch (stInformacoesPosicao.cOrientacao)
        {
            case VERTICAL  : marca_vertical  (aaTabuleiro, stInformacoesPosicao, astInformacoesPalavras); break;
            case HORIZONTAL: marca_horizontal(aaTabuleiro, stInformacoesPosicao, astInformacoesPalavras); break;
            case DIAGONAL  : marca_diagonal  (aaTabuleiro, stInformacoesPosicao, astInformacoesPalavras); break;
        }

        bool bGanhou = verifica_tabuleiro(astInformacoesPalavras);
        if (bGanhou)
        {
            cout << endl;
            cout << "Parabens, voce ganhou!!!" << endl;
            cout << "Deseja jogar novamente? (S/N)" << endl;

            char cResposta = 0;
            cin >> cResposta;

            bJogoAcabou = cResposta == 'N';
        }

    } while (!bJogoAcabou);
}

int main()
{
    inicia_jogo();

    return 0;
}
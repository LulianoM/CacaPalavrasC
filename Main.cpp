#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

#pragma region Defines

#define UCHAR unsigned char

#define TAMANHO_MAX_PALAVRA  20
#define NUM_MAX_PALAVRAS 10

#define VERTICAL   'V'
#define HORIZONTAL 'H'
#define DIAGONAL   'D'

#pragma endregion

#pragma region Estruturas

struct informacoesPalavra
{
    int  iColuna;
    int  iLinha;
    char szPalavra[TAMANHO_MAX_PALAVRA];
    char cOrientacao;
    bool bMarcada;
};

struct informacoesPosicao
{
    int  iTamanhoPalavra;
    int  iLinha;
    int  iColuna;
    char cOrientacao;
};

#pragma endregion

#pragma region Metodos Auxiliares

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

#pragma endregion

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


void imprime_palavras(vector<informacoesPalavra> astInformacoesPalavras)
{
    for (const informacoesPalavra& stInformacoesPalavra : astInformacoesPalavras)
    {
        if (stInformacoesPalavra.bMarcada)
            continue;

        string sPalavra = stInformacoesPalavra.szPalavra;
        transform(sPalavra.begin(), sPalavra.end(), sPalavra.begin(), toupper);

        cout << sPalavra << "  ";
    }
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
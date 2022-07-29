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
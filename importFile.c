#include <stdio.h>
 
#define MAX_LINE_LENGTH 256

char le_caca_palavra(char arquivo) {
    FILE* file = fopen(arquivo, "r");
    int numberofWords = 0
    char strings[numberofWords][MAX_LINE_LENGTH];

    if (!file)
    {
        printf( "Arquivo invalido\n" );
        return false;
    }

    while(fgets(line, MAX_LINE_LENGTH, textfile)){
        strings[numberofWords] = line;
        numberofWords++;
    }
   return result; 
}

int main()
{
    char list; 
    list = le_caca_palavra("palavras.txt");
    printf(list);
    return 0;
}

#include<stdio.h>
#include<string.h>

int main() {
    int p, l, d, m;
    strlista strlista[p];
    for (l=0, l=> len(strlista), ++l){
        for (p=0, p=> len (strlista[p]), ++p){
            for (m=0, m=> len(strlista[p][m]))
            for (d=0, d=>len(strlista[p][d])){
                if (strlista[p][d] == strlista[p][m]);
                printf("%s", letra);}}}

    return 0; 
}

 \\declarando variáveis que serão utilizadas\\
   int p, l, d, m;

\\ separando as palavras da lista em strings\\
   strlista;

\\separando a palavra selecionada da lista, por letras\\
   strlista[p]

\\p= contador de palavras\\
 \\l= contador de letras\\

 \\percorre a lista\\
for (l=0, l=> len(strlista), ++l){

\\percorre as palavras da lista\\
   for (p=0, p=> len (strlista[p]), ++p){

\\percorre as letras da palavra\\
      for (m=0, m=> len(strlista[p][m])
\\percorre as letras da palavra\\
     for (d=0, d=>len(strlista[p][d]){

\\compara as letras\\
     if (strlista[p][d] == 
      strlista[p][m])

\\imprime as letras que estão presentes em ambas as palavras\\
        printf("%s", letra) 

      return 0; 
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../variables/variables.h"

/* Acessa o código completo no github para baixar estou atualizando via Git-> https://github.com/LulianoM/CacaPalavrasC
- Foi definido que -> As palavras marcadas serão aquelas MAIÚSCULAS
 */

char   line[MAX_LINE_LENGTH];
char   words[MAX_NUM_PALAVRAS][MAX_LINE_LENGTH];

void le_caca_palavras(char *arquivo) {
    FILE* f;
    
    f = fopen(arquivo, "r");

    if(f == NULL) {
        printf("Banco de dados de palavras não disponível\n\n");
        exit(1);
    }

    int num_palavra = 0;
    while(fgets(line, MAX_LINE_LENGTH, f)){
        if(num_palavra == MAX_NUM_PALAVRAS){
            printf("Limite máximo de palavras atingido.\n\n");
            break;
        }
        strcpy(words[num_palavra], line);
        num_palavra++;
    }
     
    fclose(f);
}

void sanitize_words(){
    tolower();
}

void encontra_intersecao(){
    /* nao precisa receber a lista (words) pois ela ja é global */
    int positionalLetterOne, positionalLetterTwo, positionalWordOne, positionalWordTwo = 0;

    for(positionalWordOne=0; positionalWordOne<10; positionalWordOne++){
        for(positionalWordTwo=0; positionalWordTwo<10; positionalWordTwo++){
            if (positionalWordTwo==positionalWordOne){
                break;
            }
            /* refactor para uma func no futuro */
            for(positionalLetterOne=0; positionalLetterOne<strlen(words[positionalWordOne]); positionalLetterOne++){
                
                for (positionalLetterTwo=0; positionalLetterTwo<strlen(words[positionalWordTwo]);positionalLetterTwo++){
                    
                    if (words[positionalWordOne][positionalLetterOne]==words[positionalWordTwo][positionalLetterTwo]){
                        
                        printf("%c in %s and %s (%d - %d)\n", words[positionalWordOne][positionalLetterOne], words[positionalWordOne],words[positionalWordTwo], positionalLetterOne+1, positionalLetterTwo+1);
                    }
                }
            }
        }
    }
}

int max_number_words(){
    int positionalLetter, maxLenWord = 0;
    for(positionalLetter = 0; positionalLetter<MAX_NUM_PALAVRAS; positionalLetter++){
        if(strlen(words[positionalLetter])>maxLenWord){
            maxLenWord = strlen(words[positionalLetter]);
        }
    }
    return maxLenWord-1;
}

int calculate_size_of_board(){
    int    lenWords    = max_number_words();
    int    sizeOfBoard = (lenWords*2);
    return sizeOfBoard;
}

char cria_tabuleiro(){
    int sizeOfBoard = calculate_size_of_board();
    char   bord[sizeOfBoard][sizeOfBoard];
    return bord;
}

void imprime(char T){
    int row, column=0;
    int sizeOfBoard = calculate_size_of_board();
    char board[sizeOfBoard][sizeOfBoard];
    {
        for (column = 0; column < sizeOfBoard; column++)
        {
            printf("%d\t", board[row][column]);
        }
        printf("\n");
    }
}

int main(){
  le_caca_palavras("palavras.txt");
  encontra_intersecao();
  cria_tabuleiro();
}
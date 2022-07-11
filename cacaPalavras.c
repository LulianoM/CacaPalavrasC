#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "variables.h"

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

void cria_tabuleiro(){
    int    lenWords    = max_number_words();
    int    sizeOfBoard = (lenWords*2);
    char   bord[sizeOfBoard][sizeOfBoard];
}

int main(){
  le_caca_palavras("palavras.txt");
  encontra_intersecao();
  cria_tabuleiro();
  /* int** tabuleiro = malloc(N*sizeof(int*))
  for append  tabuleiro no malloc */
}
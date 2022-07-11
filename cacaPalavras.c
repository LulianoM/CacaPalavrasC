#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "variables.h"

char   line[MAX_LINE_LENGTH];
char   words[MAX_NUM_PALAVRAS][MAX_LINE_LENGTH];
char   tabuleiro[N][N];

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
        printf("%s\n", line);
        strcpy(words[num_palavra], line);
        printf("%s\n", words[num_palavra]);
        num_palavra++;
        printf("%d\n", num_palavra);
    }
     
    fclose(f);
}

/*
void encontra_intersecao(){
    /* Fazer um looping pelas palavras 
    int positionWordOne, positionWordTwo = 0;
    char word;
    for(word )

}

void cria_tabuleiro(){
     O tamanho do tabuleiro será dado pelo len da maior palavras*2 
}


int letraexiste(char letra) {

    for(int j = 0; j < strlen(word); j++) {
        if(letra == word[j]) {
            return 1;
        }
    }

    return 0;
}
*/

int main(){
  le_caca_palavras("palavras.txt");
  /* int** tabuleiro = malloc(N*sizeof(int*))
  for append  tabuleiro no malloc */
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "variables.h"

void marcar_palavra(){
    ch = 'g';
    printf("%c in uppercase is represented as  %c",
           ch, toupper(ch));
    int tolower(int argument);
}


void marca_horizontal(char T, int P,int K,char C){
    /* T = Tabuleiro P = posi palavra K = len palavra C info palavras marcadas  */ 

    int column = P[0]
    int row = P[1] 
    int lenOfWord = K

    {
        for (posWord = 0; posWord < lenOfWord; posWord++)
        {
            printf("%d\t", T[row][column]);
            column++;
        }
        printf("\n");
    }
}


void marca_vertical(char T, int P,int K,char C){
    /* T = Tabuleiro P = posi palavra K = len palavra C info palavras marcadas  */
    int column = P[0]
    int row = P[1] 
    int lenOfWord = K

    {
        for (posWord = 0; posWord < lenOfWord; posWord++)
        {
            printf("%d\t", T[row][column]);
            row++;
        }
        printf("\n");
    }
}

void marca_diagonal(char T, int P,int K,char C){
    /* T = Tabuleiro P = posi palavra K = len palavra C info palavras marcadas  */
    int column = P[0]
    int row = P[1] 
    int lenOfWord = K

    {
        for (posWord = 0; posWord < lenOfWord; posWord++)
        {
            printf("%d\t", T[row][column]);
            row++;
            column++;
        }
        printf("\n");
    } 
}
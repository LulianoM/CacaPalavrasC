#include <stdio.h>
 
#define MAX_LINE_LENGTH 1000
 
int main() {
    FILE    *textfile;
    char    line[MAX_LINE_LENGTH];
     
    textfile = fopen("palavras.txt", "r");
    if(textfile == NULL)
        return 1;
     
    while(fgets(line, MAX_LINE_LENGTH, textfile)){
        printf(line);
    }
     
    fclose(textfile);
    return 0;
}
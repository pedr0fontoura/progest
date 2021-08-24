#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

char *compactar(char *s){

    int i, countPrimeira = 0, countUltima = 0, tamTotal = 0, tam = 0, count;

    tamTotal = strlen(s);

    for(i = 0; s[i] == ' '; i++){
        countPrimeira++;
    }
    for(i = strlen(s)-1; s[i] == ' '; i--){
        countUltima++;
    }

    tam = tamTotal - countPrimeira - countUltima;

    char* compact = (char*)malloc((tam+1) * sizeof(char));

    count = 0;
    for(i = countPrimeira; i < strlen(s) - countUltima; i++){
        compact[count] = s[i];
        count++;
    }
    compact[count] = '\0';

    return compact;

}

int main(){

    char s[MAX];
    char *compactado;
    int i;

    gets(s);

    compactado = compactar(s);

    printf("%s", compactado);

    return 0;
}
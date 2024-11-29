#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int trova_max_ricorsivo(char stringhe[][100], int n, int massimo){
    if(n == 0){
        return massimo;
    }
    int len = strlen(stringhe[n-1]);
    if(len > massimo){
        massimo = len;
    }
    return trova_max_ricorsivo(stringhe, n-1, massimo);
}

int trova_max_iterativo(char stringhe[][100], int n){
    int massimo = 0;
    for(int i = 0; i < n; i++){
        int len = strlen(stringhe[i]);
        if(len > massimo){
            massimo = len;
        }
    }
    return massimo;
}

int main(){
    char stringhe[10][100];
    for(int i = 0; i < 10; i++){
        printf("Inserisci la stringa %d: ", i+1);
        
        fgets(stringhe[i], 100, stdin);
        int len = strlen(stringhe[i]);
        if(stringhe[i][len-1] == '\n'){
            stringhe[i][len-1] = '\0';
        }
    }

    int massimo = trova_max_ricorsivo(stringhe, 10, 0);
    printf("La lunghezza massima e' %d\n", massimo);
}
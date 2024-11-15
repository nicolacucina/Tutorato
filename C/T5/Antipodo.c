/*
Scrivere una funzione che riceve due stringhe s1 e s2 come parametro e
restituisce 1 (cioè vero) se s2 è l'antipodo di s1, 0 (cioè falso) in caso contrario. 
L'antipodo di una parola si ottiene spostando la prima lettera in fondo e leggendo il tutto a rovescio. 
Ad esempio, l'antipodo di "battello" è "bolletta". 
Scrivere poi un programma che legge due stringhe dall'utente e dice all'utente se la seconda stringa è 
l'antipodo della prima. [Prove: "monotono/monotono", "ballo/bolla"]
*/

#include <stdio.h>
#include <string.h>

void inserisci_stringa(char *s1, int n){
    printf("Inserisci la prima stringa: \n");
    
    fgets(s1, n, stdin);
    int len = strlen(s1);
    if(s1[len-1] == '\n'){
        s1[len-1] = '\0';
    }
}

int is_antipodo(char *s1, char *s2){
    int antipodo = 1;
    int n = strlen(s1);
    char temp[n];

    printf("Dimensione S1: %d\n", n);
    printf("S1: %s\n", s1);
    
    temp[0] = s1[0];
    int index = 1;
    for(int i = n-1; i > 0; i--){
        temp[index] = s1[i];
        index++;
    }
    temp[index] = '\0';
    
    printf("Temp: %s\n", temp);
    printf("S2: %s\n", s2);

    if(strlen(s2) != n){
        antipodo = 0;
    }else{
        for(int i = 0; temp[i] != '\0'; i++){
            if(temp[i] != s2[i]){
                antipodo = 0;
            }
        }
    }

    return antipodo;
}

int main(){
    int n = 100;
    char s1[n], s2[n];
    
    inserisci_stringa(s1, n);
    inserisci_stringa(s2, n);
    
    if(is_antipodo(s1, s2)){
        printf("Le stringhe sono antipodi\n");
    } else {
        printf("Le stringhe non sono antipodi\n");
    }
}
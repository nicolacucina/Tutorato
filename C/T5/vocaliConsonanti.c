/*
Scrivere una funzione con il seguente prototipo:
void inserisci(char *s1, char *s2);
La funzione riceve in ingresso due stringhe s1 e s2 e modifica s2 nel seguente modo:
- inserisce un ^ dopo ogni vocale di s1
- inserisce un * dopo ogni consonante di s1.
Ad esempio, se s1 fosse "ciao mare", la funzione dovrebbe modificare s2 in modo da ottenere
"c*i^a^o^ m*a^r*e^". Scrivere poi un programma che usa la funzione scritta.
*/

#include <stdio.h>
#include <string.h>

void inserisci_stringa(char *s1, int n){
    printf("Inserisci la stringa: \n");

    fgets(s1, n, stdin);
    int len = strlen(s1);
    if(s1[len-1] == '\n'){
        s1[len-1] = '\0';
    }
}

int is_vocale(char c){
    char vocali[] = "aeiou";
    int risultato = 0;
    for(int i = 0; vocali[i] != '\0'; i++){
        if(c == vocali[i]){
            risultato = 1;
        }
    }
    return risultato;
}

void inserisci(char *s1, char *s2){
    int index = 0;
    for(int i = 0; s1[i] != '\0'; i++){
        s2[index] = s1[i];
        index++;
        if(is_vocale(s1[i])){
            s2[index] = '^';
            index++;
        } else if(s1[i] != ' '){
            s2[index] = '*';
            index++;
        }
    }
    s2[index] = '\0';
}

int main(){
    int n = 100;
    char s1[n], s2[n];

    inserisci_stringa(s1, n);
    inserisci(s1, s2);

    printf("S1: %s\n", s1);
    printf("S2: %s\n", s2);
}
// Scrivere un programma C che fa inserire all'utente un numero intero compreso 
// tra 1 e 21 che rappresenta una lettera dell'alfabeto italiano (1=A, 2=B, ecc.) e visualizza all’utente 1 
// se la lettera inserita è una vocale, 0 altrimenti. Per esempio, se l'utente inserisse 5 (=E) il programma 
// dovrebbe restituire 1; se l'utente inserisse 18 (=T) il programma dovrebbe restituire 0
#include <stdio.h>

int main(){
    int x, vocale;
    printf("Inserire un numero intero tra 1 e 21 che rappresenta un carattere dell'alfabeto italiano: ");
    scanf("%d", &x);
    // Cerchiamo le vocali:
    // a=1
    // e=5
    // i=9
    // o=15
    // u=21
    // Operatori logici
    // && AND 
    // || OR
    // ! NOT
    vocale = (x == 1) || (x == 5) || (x == 9) || (x == 15) || (x == 21);
    printf("Il numero inserito rappresenta una vocale? 0) No 1) Si -> %d\n", vocale);
    // Utilizzando gli if
    if(vocale == 1){
        printf("E' una vocale");
    }else{
        printf("Non e' una vocale");
    }

    // Soluzione alternativa che usa il char 
    // non richiesta dato che l'esercizio specifica come devono essere rappresentati i caratteri
    
    // char c;
    // printf("Inserire un carattere: ");
    // scanf("%c", &c);
    // if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
    //     printf("Il carattere inserito e' una vocale");
    // }else{
    //     printf("Il carattere inserito non e' una vocale");
}
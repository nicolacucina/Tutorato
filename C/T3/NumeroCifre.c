/*
Scrivere un programma in C che chiede all'utente di inserire una sequenza di numeri interi positivi e visualizza:
- il numero che è composto da più cifre 
- il numero k di cifre che lo compongono 
- la somma delle cifre che lo compongono. 

Se ci sono più numeri composti da k cifre, il programma deve restituire il numero le cui cifre danno una somma maggiore. 
Il programma deve continuare a leggere valori finché l’utente non inserisce -1.

Se, ad esempio, l'utente inserisse 126, 14, 3334, 2122, -1, il programma dovrebbe stampare 3334, 4 e 13. 
L'esercizio deve essere risolto scrivendo due funzioni. 
La prima deve ricevere come parametro un numero intero e restituire il numero di cifre che lo compongono, 
mentre la seconda funzione deve ricevere come parametro un numero intero e restituire la somma delle cifre che lo compongono.
*/

#include <stdio.h>

int numero_cifre(int n){
    int cifre = 0;
    while(n != 0){
        n = n / 10;
        cifre++;
    }
    return cifre;
}

int somma_cifre(int n){
    int somma = 0;
    while(n != 0){
        somma += n % 10;
        n = n / 10;
    }
    return somma;
}

int main(){
    int numero, max_numero, max_cifre, max_somma;
    max_numero = 0;
    max_cifre = 0;
    max_somma = 0;
    printf("Inserisci un numero: ");
    scanf("%d", &numero);
    while(numero != -1){
        int cifre = numero_cifre(numero);
        int somma = somma_cifre(numero);
        // Sto cercando il numero con più cifre, se ce ne sono più di uno con lo stesso numero di cifre,
        // cerco quello con la somma delle cifre maggiore
        if (cifre > max_cifre || (cifre == max_cifre && somma > max_somma)){
            max_numero = numero;
            max_cifre = cifre;
            max_somma = somma;
        }
        printf("Inserisci un numero: ");
        scanf("%d", &numero);
    }
    printf("Il numero con piu' cifre e' %d, composto da %d cifre e la somma delle cifre e' %d\n", max_numero, max_cifre, max_somma);
}
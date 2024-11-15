/*
Siano p e q due puntatori a variabili intere. 
Si scriva un programma C che, tramite apposite funzioni, soddisfi le seguenti richieste:
- Alloca dinamicamente in memoria le due variabili (Consiglio: si utilizzi l’istruzione malloc(sizeof(int) per l’allocazione);
- Memorizza nelle due variabili intere dei valori inseriti tramite tastiera dall’utente;
- Stampa il contenuto delle variabili e i loro indirizzi di memoria;
- Scambia gli indirizzi di memoria delle variabili p e q, ristampa il contenuto delle variabili e i loro indirizzi dopo tale scambio
*/

#include <stdio.h>
#include <stdlib.h>

int* alloca_variabile(){
    int* p = (int*)malloc(sizeof(int));
    if (p == NULL){
        printf("Errore nell'allocazione della memoria\n");
        exit(1);
    }
    return p;
}

int dealloca_variabile(int* p){
    free(p);
}

int input_utente(int* p){
    printf("Inserisci un valore: ");
    scanf("%d", p);
}

int stampa_variabile(int* p){
    printf("Valore: %d\n", *p);
    printf("Indirizzo: %p\n", p);
}

int scambia_valori(int* p, int* q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

int scambia_variabili(int** p, int** q){
    int* temp = *p;
    *p = *q;
    *q = temp;
}

int main(){
    int* a = alloca_variabile();
    int* b = alloca_variabile();

    input_utente(a);
    input_utente(b);

    printf("Variabili lette:\n");
    stampa_variabile(a);
    stampa_variabile(b);

    scambia_valori(a, b);

    printf("Variabili scambiate di valore:\n");
    stampa_variabile(a);
    stampa_variabile(b);

    scambia_variabili(&a, &b);

    printf("Variabili scambiate di indirizzo:\n");
    stampa_variabile(a);
    stampa_variabile(b);

    dealloca_variabile(a);
    dealloca_variabile(b);
}
/*
    Definire una struttura di nome mese, caratterizzata dai campi nome e giorni:
    - nome è una stringa di dimensione 30
    - giorni è un intero che rappresenta il numero di giorni del mese. 
    
    Scrivere una funzione seleziona che, ricevuto come parametro di ingresso un array di
    strutture mese e la dimensione di tale array, stampi a video i nomi dei mesi che hanno 31 giorni.

    Scrivere infine un programma che chiede 12 volte all’utente di inserire il nome di un mese ed il
    numero di giorni che lo compongono e stampa i mesi di 31 giorni
*/
#include <stdio.h>
#include <string.h>

struct mese {
    char nome[30];
    int giorni;
};

void stampa(int n, struct mese mesi[]) {
    for (int i = 0; i < n; i++) {
        if (mesi[i].giorni == 31) {
            printf("%s\n", mesi[i].nome);
        }
    }
}

int main(){
    struct mese mesi[12];
    for (int i = 0; i < 12; i++) {
        printf("Inserisci il nome del mese %d: ", i + 1);
        // In questo caso usiamo scanf per leggere una stringa perchè sappiamo essere una singola parola
        scanf("%s", mesi[i].nome);
        printf("Inserisci il numero di giorni del mese %d: ", i + 1);
        scanf("%d", &mesi[i].giorni);
    }
    stampa(12, mesi);
}
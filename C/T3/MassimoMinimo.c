/*
Scrivi un programma in C che chieda all'utente di
inserire una sequenza di numeri interi e visualizzi il numero massimo e il numero minimo inseriti.
Utilizza due funzioni separate per calcolare il massimo e il minimo
*/

#include <stdio.h>

/*
// Se non usassi le funzioni
int main(){
    int n, max, min;
    printf("Inserisci un numero: ");
    scanf("%d", &n);
    max = n;
    min = n;
    while(n != 0){
        printf("Inserisci un numero: ");
        scanf("%d", &n);
        if (n > max){
            max = n;
        }
        if (n < min){
            min = n;
        }
    }
    printf("Il numero massimo e': %d\n", max);
    printf("Il numero minimo e': %d\n", min);
}
*/

int f_massimo(int n, int max){
    if (n > max){
        max = n;
    }
    return max;
}

int f_minimo(int n, int min){
    if (n < min){
        min = n;
    }
    return min;
}

int main(){
    int n, max, min;
    printf("Inserisci un numero: ");
    scanf("%d", &n);
    // Inizializzo max e min con il primo numero inserito perchè avendo un solo valore, questo è sia il massimo che il minimo
    // e non ho garanzie che il ciclo while venga eseguito
    max = n;
    min = n;
    while(n != 0){
        /*
        printf("Inserisci un numero: ");
        scanf("%d", &n);
        
        Se lasciassi qua l'input utente se viene inserito 0, prima vengono eseguite le funzioni 
        f_massimo e f_minimo e poi il ciclo while si interrompe quando ricontrolla la condizione,
        questo fa in modo che 0 sia considerato come un numero valido per la sequenza, ma noi lo stiamo 
        usando come un simbolo che segnala la fine della sequenza
        */
        max = f_massimo(n, max);
        min = f_minimo(n, min);
        printf("Inserisci un numero: ");
        scanf("%d", &n);
    }
    printf("Il numero massimo e': %d\n", max);
    printf("Il numero minimo e': %d\n", min);
}
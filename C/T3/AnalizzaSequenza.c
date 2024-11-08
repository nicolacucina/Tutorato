/*
Scrivere:
- una funzione che riceve un parametro intero n e determina se n è positivo 
- una funzione che riceve un parametro intero n e determina se n è pari. 

Scrivere poi un programma che chiede all’utente di inserire una sequenza di numeri interi e
che termina quando l’utente inserisce 0. Il programma deve stampare su schermo il numero di
interi positivi, negativi, pari e dispari. Dire anche se la sequenza di numeri inserita è crescente o no
*/

#include <stdio.h>

/*
// Se non usassi le funzioni
int main(){
    int numero, numPositivi, numNegativi, numPari, numDispari, precedente, crescente;
    numPositivi = 0;
    numNegativi = 0;

    numPari = 0;
    numDispari = 0;

    precedente = 0;
    crescente = 1;
    printf("Inserisci un numero: ");
    scanf("%d", &numero);
    while(numero != 0){
        if (numero > 0){
            numPositivi++;
        } else {
            numNegativi++;
        }
        if (numero % 2 == 0){
            numPari++;
        } else {
            numDispari++;
        }
        if (numero < precedente){
            crescente = 0;
        }
        precedente = numero;
        printf("Inserisci un numero: ");
        scanf("%d", &numero);
    }
}
*/

int f_positivo(int n){
    if (n > 0){
        return 1;
    } else {
        return 0;
    }
}

int f_pari(int n){
    if (n % 2 == 0){
        return 1;
    } else {
        return 0;
    }
}

int main(){
    int numero, numPositivi, numNegativi, numPari, numDispari, precedente, crescente;
    numPositivi = 0;
    numNegativi = 0;

    numPari = 0;
    numDispari = 0;

    // Inizializzo precedente a 0 come valore di default, non ha un significato particolare
    precedente = 0;
    // crescente = 1 rappresenta una sequenza crescente, il valore di default è 1 ma potrebbe essere 0
    crescente = 1;
    printf("Inserisci un numero: ");
    scanf("%d", &numero);
    while(numero != 0){
        if (f_positivo(numero)){
            numPositivi++;
        } else {
            numNegativi++;
        }

        if (f_pari(numero)){
            numPari++;
        } else {
            numDispari++;
        }
        
        // Una volta che crescente diventa 0 non c'è modo che torni 1
        if (numero < precedente){
            crescente = 0;
        }
        precedente = numero;
        printf("Inserisci un numero: ");
        scanf("%d", &numero);
    }
    // Quando esco dal ciclo while stampo i risultati
    printf("Numeri positivi: %d\n", numPositivi);
    printf("Numeri negativi: %d\n", numNegativi);
    printf("Numeri pari: %d\n", numPari);
    printf("Numeri dispari: %d\n", numDispari);
    if (crescente){
        printf("La sequenza e' crescente\n");
    } else {
        printf("La sequenza non e' crescente\n");
    }
}
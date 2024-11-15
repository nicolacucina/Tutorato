// Sia dato un array di interi di dimensione pari a 4 con elementi inseriti a tastiera dall'utente. 
// Si scriva un programma C che stampi in almeno 5 modi diversi gli elementi
// dell’array. Nello specifico:
// 1. Stampa con ciclo for degli elementi dell'array;
// 2. Stampa con puntatore e aritmetica dei puntatori;
// 3. Stampa con puntatore e indici;
// 4. Stampa con array e aritmetica dei puntatori;
// 5. Con puntatore, aritmetica dei puntatori e incrementando il puntatore al posto dell'indice

#include <stdio.h>

int parte_1(int array[], int size){
    printf("Stampa con ciclo for degli elementi dell'array:\n");
    for(int i = 0; i < size; i++){
        printf("%d\n", array[i]);
    }
}

int parte_2(int array[], int size){
    printf("Stampa con puntatore e aritmetica dei puntatori:\n");
    for(int i = 0; i < size; i++){
        printf("%d\n", *(array + i));
    }
}

int parte_3(int array[], int size){
    int *temp = array;
    printf("Stampa con puntatore e indici:\n");
    for(int i = 0; i < size; i++){
        printf("%d\n", temp[i]);
    }
}

int parte_4(int array[], int size){
    printf("Stampa con array e aritmetica dei puntatori:\n");
    for(int i = 0; i < size; i++){
        printf("%d\n", *(array + i));
    }
}

int parte_5(int array[], int size){
    printf("Con puntatore, aritmetica dei puntatori e incrementando il puntatore al posto dell'indice:\n");
    int *temp, i;
    for(temp = array, i= 0; i < size; i++, temp++){
        printf("%d\n", *temp);
    }
}

int main(){
    int array[4];

    for(int i = 0; i < 4; i++){
        printf("Inserisci il valore %d: ", i);
        scanf("%d", &array[i]);
    }

    parte_1(array, 4);
    parte_2(array, 4);
    parte_3(array, 4);
    parte_4(array, 4);
    parte_5(array, 4);
}
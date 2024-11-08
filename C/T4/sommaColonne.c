/*
Scrivere una funzione C che riceve come parametro una matrice di numeri reali, le sue dimensioni 
e un indice di colonna j e restituisce la somma degli elementi nella colonna j. 
Scrivere poi un programma che fa inserire all'utente una matrice di numeri reali. 
Il programma deve visualizzare la matrice inserita e, scelta una colonna, la somma
degli elementi su tale colonna
*/

#include <stdio.h>

double somma_colonna(int righe, int colonne, double matrice[][colonne], int j){
    double somma = 0;
    for(int i = 0; i < righe; i++){
        somma += matrice[i][j];
    }
    return somma;
}

int main(){
    int righe, colonne;
    printf("Inserisci il numero di righe: ");
    scanf("%d", &righe);
    printf("Inserisci il numero di colonne: ");
    scanf("%d", &colonne);

    double matrice[righe][colonne];
    for(int i=0; i<righe; i++){
        for(int j=0; j<colonne; j++){
            printf("Inserisci il valore per la cella [%d][%d]: ", i, j);
            scanf("%lf", &matrice[i][j]);
        }
    }

    printf("Matrice inserita: \n");
    for(int i=0; i<righe; i++){
        for(int j=0; j<colonne; j++){
            printf("%lf ", matrice[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    int colonna_j;
    printf("Inserisci l'indice della colonna di cui vuoi calcolare la somma: ");
    scanf("%d", &colonna_j);
    if (colonna_j >= colonne || colonna_j < 0){
        printf("Indice di colonna non valido\n");
    }else{
        double somma = somma_colonna(righe, colonne, matrice, colonna_j);
        printf("La somma degli elementi nella colonna %d e': %lf\n", colonna_j, somma);
    }
}
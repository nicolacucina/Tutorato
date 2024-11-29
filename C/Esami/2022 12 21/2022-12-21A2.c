/*
    Il sudoku è un gioco di logica nel quale al giocatore o solutore viene proposta una griglia di 9×9 celle,
    ciascuna delle quali può contenere un numero da 1 a 9, oppure essere vuota; 
    la griglia è suddivisa in 9 righe orizzontali, 9 colonne verticali e in 9 "sottogriglie" di 3×3 celle contigue chiamate regioni.
    Lo scopo del gioco è quello di riempire le caselle bianche con numeri da 1 a 9 in modo tale che in ogni riga, in ogni
    colonna e in ogni regione siano presenti tutte le cifre da 1 a 9, quindi senza ripetizioni.

    Scrivere una funzione verificaRegione per verificare che una regione di uno schema del Sudoku dato sia
    riempita correttamente (cioè contenga tutti e soli i numeri da 1 a 9). 
    Più precisamente, la funzione verificaRegione riceve in ingresso un array bidimensionale di dimensione 9 × 9 
    (si può assumere che le dimensioni siano corrette) che rappresenta uno schema del Sudoku riempito, 
    e due indici che denotano la regione di interesse (Regione 0,0 Regione 0,3, Regione 0,6 etc.), e restituisce 1 (cioè true) se la regione in
    questione è stata riempita correttamente, 0 (cioè false) in caso contrario.

    Dopo aver scritto la funzione, scrivere un main che permetta di testarla. A tale scopo è sufficiente definire
    una matrice 9 × 9 tramite un letterale array e passarla alla funzione (insieme agli altri parametri necessari).
*/

#include <stdio.h>

int trovato(int n, int sudoku[9][9], int riga, int colonna){
    for(int i = riga; i < riga+3; i++){
        for(int j = colonna; j < colonna+3; j++){
            if(sudoku[i][j] == n){
                return 1;
            }
        }
    }
    return 0;
}

int verificaRegione(int sudoku[9][9], int riga, int colonna){
    int trovati[9] = {0,0,0,0,0,0,0,0,0};
    for(int i = 0; i<9; i++){
        if(trovato(i+1, sudoku, riga, colonna)){
            trovati[i] = 1;
        }
    }
    for(int i = 0; i<9; i++){
        if(trovati[i] == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int sudoku[9][9] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {4, 5, 6, 7, 8, 9, 1, 2, 3},
        {7, 8, 9, 1, 2, 3, 4, 5, 6},
        {2, 3, 4, 5, 6, 7, 8, 9, 1},
        {5, 6, 7, 8, 9, 1, 2, 3, 4},
        {8, 9, 1, 2, 3, 4, 5, 6, 7},
        {3, 4, 5, 6, 7, 8, 9, 1, 2,},
        {6, 7, 8, 9, 1, 2, 3, 4, 5},
        {9, 1, 2, 3, 4, 5, 6, 7, 8}
    };
    
    int corretto = verificaRegione(sudoku, 0, 0);
    if(corretto){
        printf("La regione e' corretta.\n");
    }else{
        printf("La regione non e' corretta.\n");
    }
}
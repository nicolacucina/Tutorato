/*
    Nel gioco degli scacchi l’alfiere può muoversi in diagonale di un numero qualsiasi di caselle. 
    Data un alfiere A, un pezzo che si trovi su una delle due diagonali passanti per A risulta minacciato da A

    Scrivere una funzione contaMinacciati per contare il numero di pezzi minacciati da un alfiere. 
    Più precisamente, la funzione riceve in ingresso una array bidimensionale di char di dimensione 
    8 × 8 (si può assumere che le dimensioni siano corrette) 
    che rappresenta una scacchiera su cui sono posizionati dei pezzi e, individuato l’alfiere, 
    conta il numero di pezzi da esso minacciati; 
    per semplicità si assuma che tutti i pezzi siano dello stesso colore e che l’alfiere minacci i pezzi del suo stesso colore.
    Ogni pezzo è rappresentato da un carattere che indica il tipo di pezzo 
    (R per il re, D per la regina, T per la torre, A per l’alfiere, C per il cavallo e P per il pedone).

    Dopo aver scritto la funzione, scrivere un main che permetta di testarla. 
    A tale scopo è sufficiente definire una matrice 8 × 8 tramite un letterale array e passarla alla funzione
*/

#include <stdio.h>

void trova_alfieri(char scacchiera[8][8], int posizioni[2][2]){
    int index = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(scacchiera[i][j] == 'A'){
                posizioni[index][0] = i;
                posizioni[index][1] = j;
                index++;
            }
        }
    }
}

int contaMinacciati(char scacchiera[8][8], int x, int y){

    int minacciato = 0;
    for(int j = 1; x+j < 8 && y+j < 8; j++){
        // diag principale inferiore
        if(scacchiera[x+j][y+j] != ' '){
            minacciato++;
        }
    }
    for(int j = 1; x-j >= 0 && y-j >= 0; j++){
        // diag principale superiore
        if(scacchiera[x-j][y-j] != ' '){
            minacciato++;
        }
    }
    for(int j = 1; x+j < 8 && y-j >= 0; j++){
        // anti-diag inferiore
        if(scacchiera[x+j][y-j] != ' '){
            minacciato++;
        }
    }
    for(int j = 1; x-j >= 0 && y+j < 8; j++){
        // anti-diag superiore
        if(scacchiera[x-j][y+j] != ' '){
            minacciato++;
        }
    }
    return minacciato;    
}

int main(){
    char scacchiera[8][8] = {
        {'T', 'C', 'A', 'D', 'R', 'A', 'C', 'T'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', ' ',' ',' ',' ',' ',' ',' '},
        {' ', ' ',' ',' ',' ',' ',' ',' '},
        {' ', ' ',' ',' ',' ',' ',' ',' '},
        {' ', ' ',' ',' ',' ',' ',' ',' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'T', 'C', 'A', 'D', 'R', 'A', 'C', 'T'}
    };

    int posizioni[4][2];
    trova_alfieri(scacchiera, posizioni);
    for(int i = 0; i < 4; i++){
        printf("Alfiere in posizione %d, %d\n", posizioni[i][0], posizioni[i][1]);
    }
    int minacciati[2];
    for(int i = 0; i < 4; i++){
        int x = posizioni[i][0];
        int y = posizioni[i][1];
        minacciati[i] = contaMinacciati(scacchiera, x, y);
    }
    for(int i = 0; i < 4; i++){
        printf("L'alfiere in posizione %d, %d minaccia %d pezzi.\n", posizioni[i][0], posizioni[i][1], minacciati[i]);
    }
}
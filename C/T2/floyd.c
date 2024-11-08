// Scrivere un programma C per il calcolo delle prime n righe del triangolo di Floyd. 
// Il triangolo di Floyd è un triangolo rettangolo che contiene numeri naturali,
// definito riempiendo le righe del triangolo con numeri consecutivi e partendo da 1 nell’angolo in alto
// a sinistra. Se, ad esempio, l’utente inserisse 5, il programma dovrebbe stampare:
// 1
// 2 3
// 4 5 6
// 7 8 9 10
// 11 12 13 14 15
#include <stdio.h>

int main(){
    int n, counter;
    printf("Inserisci il numero di righe del triangolo di Floyd: ");
    scanf("%d", &n);
    counter = 1;
    // i rappresenta il numero di righe, j rappresenta il numero di colonne
    // Per stampare un triangolo, ogni riga ha un numero di colonne pari all'indice della riga
    // 1° riga: 1 colonna, 2° riga: 2 colonne, 3° riga: 3 colonne, ecc.
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            // Dentro alle celle del triangolo di Floyd, stampo il contatore
            printf("%d ", counter);
            counter++;
        }
        printf("\n");
    }
}
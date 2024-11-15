/*
Scrivere un programma C che simuli una partita del gioco del tris. 
Il gioco prevede la presenza di una griglia 3x3 sulla quale i giocatori posizionano, 
ciascuno rispettando il proprio turno, un 1 o un 2. 
La partita termina quando uno dei due giocatori riesce a mettere tre simboli uguali sulla stessa riga, 
sulla stessa colonna oppure su una delle due diagonali della griglia. 
Se nessuna di queste condizioni si verifica e la griglia è piena, la partita termina con un pareggio.
*/

#include <stdio.h>

void inizializza_griglia(int griglia[][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            griglia[i][j] = 0;
        }
    }
}

void input_giocatore(int griglia[][3], int giocatore){
    int riga, colonna;
    // Chiediamo all'utente di fornire riga e colonna di dove vuole posizionare il simbolo
    printf("Giocatore %d, inserisci la riga: ", giocatore);
    scanf("%d", &riga);
    printf("Giocatore %d, inserisci la colonna: ", giocatore);
    scanf("%d", &colonna);

    // Controlliamo se la mossa scelta può essere effettuata. Nella cella scelta dobbiamo trovare uno 0.
    // Se la cella è già occupata, l'utente deve riprovare.
    int riprova=1;
    // if (griglia[riga][colonna] != 0){
    //     printf("Cella gia' occupata, riprova\n");
    //     riprova=1;
    // } else {
    //     griglia[riga][colonna] = giocatore;
    // }
    while (riprova==1){
        printf("Giocatore %d, inserisci la riga: ", giocatore);
        scanf("%d", &riga);
        printf("Giocatore %d, inserisci la colonna: ", giocatore);
        scanf("%d", &colonna);
        if (griglia[riga][colonna] != 0){
            printf("Cella gia' occupata, riprova\n");
        } else {
            // Se finiamo in questo blocco, la cella conteneva uno 0 e quindi possiamo inserire il simbolo del giocatore
            griglia[riga][colonna] = giocatore;
            riprova=0;
        }
    }
}

int controlla_vittoria(int griglia[][3]){
    // Vengono controllate tutte le righe, colonne e diagonali per vedere se c'è un vincitore.
    // Se viene trovata una combinazione vincente, viene restituito il giocatore che ha vinto.
    // Avendo controllato tutte le combinazioni, se non c'è un vincitore viene restituito 0.

    // Controllo righe
    for(int i = 0; i < 3; i++){
        if(griglia[i][0] != 0 && griglia[i][0] == griglia[i][1] && griglia[i][1] == griglia[i][2]){
            return griglia[i][0];
        }
    }
    // Controllo colonne
    for(int i = 0; i < 3; i++){
        if(griglia[0][i] != 0 && griglia[0][i] == griglia[1][i] && griglia[1][i] == griglia[2][i]){
            return griglia[0][i];
        }
    }
    // Controllo diagonali
    if(griglia[0][0] != 0 && griglia[0][0] == griglia[1][1] && griglia[1][1] == griglia[2][2]){
        return griglia[0][0];
    }
    if(griglia[0][2] != 0 && griglia[0][2] == griglia[1][1] && griglia[1][1] == griglia[2][0]){
        return griglia[0][2];
    }
    return 0;
}

void stampa_griglia(int griglia[][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", griglia[i][j]);
        }
        printf("\n");
    }
}

int main(){
    // Inizializzazione delle variabili necessarie
    int griglia[3][3];
    // La griglia di gioco viene inizialmente riempita con zeri per indicare che nessuna cella è stata occupata
    inizializza_griglia(griglia);

    // Variabili di supporto che utilizziamo per tenere traccia dello stato del gioco
    int giocatore = 1;
    int partita_finita = 0;
    int vincitore = 0;
    
    // All'interno del ciclo while abbiamo i vari turni di gioco
    while(partita_finita == 0){
        // La prima cosa da fare è visualizzare la griglia di gioco per consentire al giocatore di fare la sua mossa
        stampa_griglia(griglia);

        // Dopo aver visualizzato la griglia, chiediamo al giocatore corrente di fare la sua mossa
        input_giocatore(griglia, giocatore);

        // Dopo che il giocatore ha fatto la sua mossa, controlliamo se c'è un vincitore
        vincitore = controlla_vittoria(griglia);

        // Se il metodo controlla_vittoria restituisce un valore diverso da 0, c'è un vincitore e la partita termina
        if(vincitore != 0){
            partita_finita = 1;
        } else {
            if (giocatore == 1){
                giocatore = 2;
            } else {
                giocatore = 1;
            }
        }
    }
    // Se si esce dal ciclo while, la partita è terminata e viene visualizzata la griglia finale
    stampa_griglia(griglia);
    if(vincitore == 1){
        printf("Ha vinto il giocatore 1\n");
    } else if(vincitore == 2){
        printf("Ha vinto il giocatore 2\n");
    } else {
        printf("Pareggio\n");
    }
}
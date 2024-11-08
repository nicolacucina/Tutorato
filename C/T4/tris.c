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

void input_giocatore(int griglia[][3], int giocatore, int riga, int colonna){
    printf("Giocatore %d, inserisci la riga: ", giocatore);
    scanf("%d", &riga);
    printf("Giocatore %d, inserisci la colonna: ", giocatore);
    scanf("%d", &colonna);
    int riprova=0;
    if (griglia[riga][colonna] != 0){
        printf("Cella gia' occupata, riprova\n");
        riprova=1;
    } else {
        griglia[riga][colonna] = giocatore;
    }
    while (riprova==1){
        printf("Giocatore %d, inserisci la riga: ", giocatore);
        scanf("%d", &riga);
        printf("Giocatore %d, inserisci la colonna: ", giocatore);
        scanf("%d", &colonna);
        if (griglia[riga][colonna] != 0){
            printf("Cella gia' occupata, riprova\n");
        } else {
            griglia[riga][colonna] = giocatore;
            riprova=0;
        }
    }
}

int controlla_vittoria(int griglia[][3]){
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
    int griglia[3][3];
    inizializza_griglia(griglia);

    int giocatore = 1;
    int partita_finita = 0;
    int vincitore = 0;
    
    int riga, colonna;
    while(partita_finita == 0){
        stampa_griglia(griglia);
        input_giocatore(griglia, giocatore, riga, colonna);
        vincitore = controlla_vittoria(griglia);
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
    stampa_griglia(griglia);
    if(vincitore == 1){
        printf("Ha vinto il giocatore 1\n");
    } else if(vincitore == 2){
        printf("Ha vinto il giocatore 2\n");
    } else {
        printf("Pareggio\n");
    }
}
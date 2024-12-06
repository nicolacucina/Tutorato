/*
    https://wiki.pokemoncentral.it/Gira_Voltorb
    https://bulbapedia.bulbagarden.net/wiki/Voltorb_Flip
    
    GiraVoltorb è un minigioco presente in Pokemon HearthGold e SoulSilver.
    In questo gioco bisogna voltare dei pannelli e trovare dei numeri nascosti. Dietro ai pannelli possono essere trovati:
    - Se viene scoperto un Voltorb (0) si perde immediatamente
    - Numeri da 1 a 3 sono validi e vengono utilizzati come moltiplicatori del punteggio
    Per completare un livello bisogna individuare tutti i numeri validi senza trovare un voltorb.
    Ai lati dei pannelli sono presenti dei numeri che indicano la somma totale dei numeri nascosti e dei voltorb presenti in quella riga o colonna.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initRandomMatrix(int n, int m, int matrice[][m]){
    /*
        0 -> voltorb
        1,2,3 -> numeri validi
    */
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matrice[i][j] = rand() % 4;
        }
    }
}

void stampaSoluzione(int n, int m, int matrice[][m]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

void initCelleMancanti(int n, int m, int matrice[][m], int soluzione[][m]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matrice[i][j] = soluzione[i][j];
        }
    }
}

void initConteggio(int n, int m, int conteggioRighe[], int conteggioColonne[]){
    for(int i = 0; i < n; i++){
        conteggioRighe[i] = 0;
    }
    for(int i = 0; i < m; i++){
        conteggioColonne[i] = 0;
    }
}

void initMatriceUtente(int n, int m, int matrice[][m]){
    /*
        Inizialmente tutti i valori sono -1 così non si confondono con i valori validi 0, 1, 2, 3
    */
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matrice[i][j] = -1;
        }
    }
}

void contaPunti(int n, int m, int matrice[][m], int conteggioRighe[], int conteggioColonne[]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrice[i][j] != 0){
                conteggioRighe[i] += matrice[i][j];
                conteggioColonne[j] += matrice[i][j];
            }
        }
    }
}

void contaVoltorb(int n, int m, int matrice[][m], int conteggioRighe[], int conteggioColonne[]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrice[i][j] == 0){
                conteggioRighe[i]++;
                conteggioColonne[j]++;
            }
        }
    }
}

void stampaMatriceUtente(int n, int m, int matrice[][m], int conteggioRighe[], int conteggioColonne[], int conteggioVoltorbRighe[], int conteggioVoltorbColonne[]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrice[i][j] == -1){
                printf("X ");
            }else{
                printf("%d ", matrice[i][j]);
            }
        }
        printf("| %d, %d\n", conteggioRighe[i], conteggioVoltorbRighe[i]);
    }
    for(int i = 0; i < m; i++){
        printf("--");
    }
    printf("\n");
    for(int i = 0; i < m; i++){
        printf("%d ", conteggioColonne[i]);
    }
    printf("\n");
    for(int i = 0; i < m; i++){
        printf("%d ", conteggioVoltorbColonne[i]);
    }
    printf("\n");
}

int scopriCella(int n, int m, int matrice[][m], int i, int j){
    if(matrice[i][j] == 0){
        printf("Hai perso! Hai trovato un voltorb!\n");
        return 0;
    }else{
        printf("Hai trovato un %d!\n", matrice[i][j]);
        return matrice[i][j];
    }
}

int controllaVittoria(int n, int m, int matrice[][m]){
    int continua = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrice[i][j] == 2 || matrice[i][j] == 3){
                continua = 1;
            }
        }
    }
    return continua;
}

int main(){
    srand(time(0));
    int n = 5;
    int m = 5;
    int soluzione[n][m];
    int matriceUtente[n][m];
    int celleMancanti[n][m];

    int conteggioRighe[n];
    int conteggioColonne[m];

    int conteggioVoltorbRighe[n];
    int conteggioVoltorbColonne[m];

    initRandomMatrix(n, m, soluzione);
    initCelleMancanti(n, m, celleMancanti, soluzione);
    //stampaSoluzione(n, m, soluzione);
    initConteggio(n, m, conteggioRighe, conteggioColonne);
    initConteggio(n, m, conteggioVoltorbRighe, conteggioVoltorbColonne);

    contaPunti(n, m, soluzione, conteggioRighe, conteggioColonne);
    contaVoltorb(n, m, soluzione, conteggioVoltorbRighe, conteggioVoltorbColonne);
    
    initMatriceUtente(n, m, matriceUtente);

    int continua = 1;
    int punteggio = 1;

    while(continua == 1){
        stampaMatriceUtente(n, m, matriceUtente, conteggioRighe, conteggioColonne, conteggioVoltorbRighe, conteggioVoltorbColonne);
        int i, j;
        printf("Inserisci la riga e la colonna della cella da scoprire: ");
        scanf("%d", &i);
        scanf("%d", &j);
        
        int temp = scopriCella(n, m, soluzione, i, j);
        
        matriceUtente[i][j] = temp;
        celleMancanti[i][j] = -1;
        stampaMatriceUtente(n, m, matriceUtente, conteggioRighe, conteggioColonne, conteggioVoltorbRighe, conteggioVoltorbColonne);

        if(temp == 0){
            continua = 0;
        }else{
            punteggio *= temp;
            printf("Il tuo punteggio attuale e': %d\n", punteggio);
            continua = controllaVittoria(n, m, celleMancanti);
            if(continua == 0){
                printf("Hai vinto!\n");
            }else{
                printf("Ci sono ancora celle da scoprire!\n");
            }
        }
    }
}
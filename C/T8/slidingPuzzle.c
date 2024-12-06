#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initMatrice(int n, int m, int matrice[][m]){
    int index = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matrice[i][j] = index;
            index++;
        }
    }
}

void mischiaMatrice(int n, int m, int matrice[][m]){
    for(int i = 0; i < 10000; i++){
        int x = rand() % n;
        int y = rand() % m;

        int a = rand() % n;
        int b = rand() % m;

        int temp = matrice[x][y];
        matrice[x][y] = matrice[a][b];
        matrice[a][b] = temp;
    }
}

void stampaMatrice(int n, int m, int matrice[][m]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

void trovaposizioneZero(int n, int m, int matrice[][m], int coordinateZero[2]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrice[i][j] == 0){
                coordinateZero[0] = i;
                coordinateZero[1] = j;
            }
        }
    }
}

int mossaUtente(int n, int m, int matrice[][m], int direzione, int posizioneZero[]){
    int x = posizioneZero[0];
    int y = posizioneZero[1];
    int valida = 1;
    if(direzione == 0){
        if(x + 1 < n){
            matrice[x][y] = matrice[x + 1][y];
            matrice[x + 1][y] = 0;
            posizioneZero[0] = x + 1;
        }else{
            printf("Mossa non valida\n");
            valida = 0;
        }
    }else if(direzione == 1){
        if(y + 1 < n){
            matrice[x][y] = matrice[x][y + 1];
            matrice[x][y + 1] = 0;
            posizioneZero[1] = y + 1;
        }else{
            printf("Mossa non valida\n");
            valida = 0;
        }
    }else if(direzione == 2){
        if(x - 1  >= 0){
            matrice[x][y] = matrice[x - 1][y];
            matrice[x - 1][y] = 0;
            posizioneZero[0] = x - 1;
        }else{
            printf("Mossa non valida\n");
            valida = 0;
        }
    }else if(direzione == 3){
        if(y - 1 >= 0){
            matrice[x][y] = matrice[x][y - 1];
            matrice[x][y - 1] = 0;
            posizioneZero[1] = y - 1;
        }else{
            printf("Mossa non valida\n");
            valida = 0;
        }
    }else{
        printf("Mossa non valida\n");
        valida = 0;
    }
}

int controllaVittoria(int n, int m, int matrice[][m]){
    int vittoria = 1;
    int index;
    if(matrice[0][0] == 0){
        index = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // printf("matrice[%d][%d]: %d, index: %d\n", i, j, matrice[i][j], index);
                if(matrice[i][j] != index){
                    vittoria = 0;
                }
                index++;
            }
        }
    }else if(matrice[n-1][m-1] == 0){
        index = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrice[i][j] != index && index != n * m){
                    vittoria = 0;
                }
                index++;
            }
        }
    }
    return vittoria;
}

int main(){
    srand(time(0));
    int n = 4;
    int m = 4;

    // int matrice[n][m];

    // initMatrice(n, m, matrice);
    // mischiaMatrice(n, m, matrice);

    // int matrice[4][4] = {
    //     {1, 2, 3, 4},
    //     {5, 6, 7, 8},
    //     {9, 10, 11, 12},
    //     {13, 14, 15, 0}
    // };

    int matrice[4][4] = {
        {4, 1, 2, 3},
        {0, 5, 6, 7},
        {8, 9, 10, 11},
        {12, 13, 14, 15}
    };

    stampaMatrice(n, m, matrice);

    int coordinateZero[2];
    trovaposizioneZero(n, m, matrice, coordinateZero);

    int continua = 1;
    int direzione;
    while(continua == 1){
        printf("Inserisci dove vuoi spostare lo zero:\n 0: sposta verso il basso\n 1: sposta verso destra\n 2: sposta verso l'alto\n 3: sposta verso sinistra\n ");
        scanf("%d", &direzione);

        int valida = mossaUtente(n, m, matrice, direzione, coordinateZero);
        stampaMatrice(n, m, matrice);
        int vittoria = controllaVittoria(n, m, matrice);
        printf("vittoria: %d\n", vittoria);
        if(vittoria == 1){
            continua = 0;
        }
    }
}
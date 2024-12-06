#include <stdio.h>
#include <stdlib.h>

void initMatrice(int n, int m, int matrice[][m]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matrice[i][j] = 0;
        }
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

int inserisciNave(int n, int m, int posizioneNaviGiocatoreUno[][m], int x, int y, int direzione, int dim){
    printf("n: %d, m: %d, x: %d, y: %d, direzione: %d, dim: %d\n", n, m, x, y, direzione, dim);
    int valido = 1;
    if(direzione == 0){
        printf("direzione 0\n");
        for(int i = 0; i < dim; i++){
            if(x + i >= n || posizioneNaviGiocatoreUno[x + i][y] != 0){
                valido = 0;
            }else{
                posizioneNaviGiocatoreUno[x + i][y] = 1;
            }
        }
    }else if(direzione == 1){
        for(int j = 0; j < dim; j++){
            if(y + j >= m || posizioneNaviGiocatoreUno[x][y + j] != 0){
                valido = 0;
            }else{
                posizioneNaviGiocatoreUno[x][y + j] = 1;
            }
        }
    }else if(direzione == 2){
        for(int i = 0; i < dim; i++){
            if(x - i < 0 || posizioneNaviGiocatoreUno[x - i][y] != 0){
                valido = 0;
            }else{
                posizioneNaviGiocatoreUno[x - i][y] = 1;
            }
        }
    }else if(direzione == 3){
        for(int j = 0; j < dim; j++){
            if(y - j < 0 || posizioneNaviGiocatoreUno[x][y - j] != 0){
                valido = 0;
            }else{
                posizioneNaviGiocatoreUno[x][y - j] = 1;
            }
        }
    }else{
        printf("la direzione non è valida\n");
        valido = 0;
    }
    return valido;
}

void giocatoreInserisceNavi(int n, int m, int posizioneNaviGiocatoreUno[][m], int giocatore){
    int x, y, direzione;
    int dim = 2;
    for(int i = 0; i < 5; i++){
        int continua = 1;
        while(continua == 1){
            stampaMatrice(n, m, posizioneNaviGiocatoreUno);
            printf("Inserisci la posizione iniziale della nave %d del giocatore 1: ", i);
            scanf("%d %d", &x, &y);
            printf("Inserisci la direzione della nave %d del giocatore %d (0 -> sud, 1 -> est, 2 -> nord, 3 -> ovest): ", i, giocatore);
            scanf("%d", &direzione);
            int temp = inserisciNave(n, m, posizioneNaviGiocatoreUno, x, y, direzione, dim);
            if(temp == 1){
                printf("Nave inserita correttamente\n");
                dim++;
                continua = 0;
            }else{
                printf("Nave non inserita correttamente\n");
            }
        }
        
    }
}

int controllaAffondata(int n, int m, int posizioniNavi[][m], int naviColpite[][m], int x, int y){
    int affondata = 0;
    int contatoreColpite = 0;
    int contatoreNavi = 0;
    // Devo prima determnanre la direzione della nave
    if((y+1 < m && posizioniNavi[x][y+1] == 1) || (y-1 >= 0 && posizioniNavi[x][y-1] == 1)){
        // printf("Nave orizzontale\n");
        // Nave orizzonale
        for(int j = 0; j < m; j++){
            if(posizioniNavi[x][j] == 1){
                contatoreNavi++;
            }
            if(naviColpite[x][j] == 1){
                contatoreColpite++;
            }
        }
    }else if((x+1 < n && posizioniNavi[x+1][y] == 1 )|| (x-1 >= 0 && posizioniNavi[x-1][y] == 1)){
        // Nave verticale
        // printf("Nave verticale\n");
        for(int i = 0; i < n; i++){
            if(posizioniNavi[i][y] == 1){
                contatoreNavi++;
            }
            if(naviColpite[i][y] == 1){
                contatoreColpite++;
            }
        }
    }
    // printf("contatoreColpite: %d, contatoreNavi: %d\n", contatoreColpite, contatoreNavi);
    if (contatoreColpite == contatoreNavi){
        affondata = 1;
    }
    return affondata;
}

void turnoGiocatore(int n, int m, int posizioniNavi[][m], int naviColpite[][m]){
    stampaMatrice(n, m, naviColpite);
    int x, y;
    printf("Inserisci la posizione della cella da colpire: ");
    scanf("%d %d", &x, &y);
    if(posizioniNavi[x][y] == 1){
        naviColpite[x][y] = 1;
        printf("Nave colpita\n");
        int affondata = controllaAffondata(n, m, posizioniNavi, naviColpite, x, y);
        if(affondata == 1){
            printf("Nave affondata\n");
        }
    }else{
        naviColpite[x][y] = -1;
        printf("Nave non colpita\n");
    }
}

int controlloVittoria(int n, int m, int posizioniNavi[][m], int naviColpite[][m]){
    int vittoria = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(posizioniNavi[i][j] == 1 && naviColpite[i][j] != 1){
                vittoria = 0;
            }
        }
    }
    return vittoria;
}

int main(){
    int n = 10;
    int m = 10;
    int giocatore = 1;
    
    // int posizioneNaviGiocatoreUno[n][m];
    // int posizioneNaviGiocatoreDue[n][m];

    // initMatrice(n, m, posizioneNaviGiocatoreUno);
    // initMatrice(n, m, posizioneNaviGiocatoreDue);

    // giocatoreInserisceNavi(n, m, posizioneNaviGiocatoreUno, 1);
    // giocatoreInserisceNavi(n, m, posizioneNaviGiocatoreDue, 2);
    
    int posizioneNaviGiocatoreUno[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 1, 1, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };


    int posizioneNaviGiocatoreDue[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 1, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 1, 1, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    int naviColpiteDelGiocatoreUno[n][m];
    int naviColpiteDelGiocatoreDue[n][m];

    initMatrice(n, m, naviColpiteDelGiocatoreUno);
    initMatrice(n, m, naviColpiteDelGiocatoreDue);

    int vittoria = 0;
    while(vittoria == 0){
        printf("Turno del giocatore %d\n", giocatore);
        if(giocatore == 1){
            turnoGiocatore(n, m, posizioneNaviGiocatoreDue, naviColpiteDelGiocatoreDue);
            vittoria = controlloVittoria(n, m, posizioneNaviGiocatoreDue, naviColpiteDelGiocatoreDue);
            if(vittoria == 0){
                giocatore = 2;
            }
        }else{
            turnoGiocatore(n, m, posizioneNaviGiocatoreUno, naviColpiteDelGiocatoreUno);
            vittoria = controlloVittoria(n, m, posizioneNaviGiocatoreUno, naviColpiteDelGiocatoreUno);
            if(vittoria == 0){
                giocatore = 1;
            }
        }
    }
    printf("Il giocatore %d ha vinto!\n", giocatore);
}
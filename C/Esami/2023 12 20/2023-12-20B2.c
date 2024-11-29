/*
    Il gioco della dama si svolge tra due giocatori che muovono alternativamente i propri pezzi, 
    detti pedine, su una  scacchiera  8 x 8; 
    Un  giocatore  ha  le  pedine  bianche, l'altro quelle nere.
    Le pedine si muovono diagonalmente, solo sulle caselle scure non occupate da altri pezzi
    ed  hanno  la  possibilità  di  catturare  (familiarmente, "mangiare") quelli avversari, scavalcandoli. 
    Le pedine possono muoversi di una sola casella alla volta, diagonalmente e in avanti; 
    possono inoltre prendere un pezzo avversario facendo un movimento  di  due  caselle  
    nella  stessa  direzione,  saltando  sopra  il  pezzo  avversario  nella  casella  intermedia.  
    Se  nella casella di arrivo la pedina è in grado di effettuare una nuova presa,
    si è in presenza di una presa multipla, che va completata nello stesso turno di gioco

    Scrivere una funzione controllaMossa() che prende in ingresso: 
    - una  matrice  di  interi  schema  di  dimensione  8× 8  che  rappresenta  una  scacchiera: 
    la  cella  (i,j)  conterrà  il  valore  0  se  è  vuota,
    conterrà  il  valore  1  se  contiene  una  pedina  nera,  e  il  valore  -1  se contiene una pedina bianca. 
    - una matrice di interi mosse di dimensione 𝑘×2, con 2≤𝑘 ≤4, che rappresenta una sequenza di 
    mosse  che  una  pedina  esegue  consecutivamente  in  unico  turno  di  gioco.
    Ogni  riga  della  matrice mosse contiene gli indici di una cella: 
        -la prima riga contiene gli indici della cella di partenza, la riga i-esima contiene 
        gli indici della cella in cui si arriva partendo dalla cella memorizzata nella riga (i-1)-esima. 
        Se 𝑘 =2 la matrice mosse descrive una mossa semplice (mossa di base o presa semplice), se 
        𝑘 >2 la matrice mosse descrive una presa multipla. 
    - la dimensione 𝑘 della matrice mosse. 
    
    La funzione deve restituire 1 (cioè true) se la sequenza di mosse è valida, 0 (cioè false) in caso contrario.  
    Si assuma che le pedine nere muovano dall’alto verso il basso e quelle bianche dal basso verso l’alto. 
    
    Dopo aver scritto la funzione, scrivere un main che permetta di testarla.
    A tale scopo è sufficiente definire le matrici necessarie tramite letterali array.
*/

#include <stdio.h>
#include <stdlib.h>

int controllaCoordinate(int x, int y){
    if(x < 0 || x > 7 || y < 0 || y > 7){
        return 0;
    }else{
        return 1;
    }
}

int controllaDiagonale(int x_p, int y_p, int x_a, int y_a){
    if(abs(x_a - x_p) != abs(y_a - y_p)){
        return 0;
    }else{
        return abs(x_a - x_p);
    }
}

int controllaMovimentoColore(int schema[8][8], int x_p, int y_p, int x_a, int y_a){
    int colore = schema[x_p][y_p];
    if(colore == 1){
        printf("Pedina nera\n");
    }else if(colore == -1){
        printf("Pedina bianca\n");
    }else{
        printf("Casella vuota\n");
    }
    printf("Partenza: (%d, %d)\n", x_p, y_p);
    printf("Arrivo: (%d, %d)\n", x_a, y_a);
    if(colore == 1 && x_a <= x_p){
        return 0;
    }else if(colore == -1 && x_a >= x_p){
        return 0;
    }else if(colore == 0){
        return 0;
    }else{
        return 1;
    }
}

int controllaMossa(int schema[8][8], int mosse[][2], int k){
    int valido = 1;

    for(int i=0; i < k-1; i++){
        int x_p = mosse[i][0];
        int y_p = mosse[i][1];
        int x_a = mosse[i+1][0];
        int y_a = mosse[i+1][1];

        int partenzaValida = controllaCoordinate(x_p, y_p);
        int arrivoValido = controllaCoordinate(x_a, y_a);
        if(!partenzaValida || !arrivoValido){
            printf("Coordinate non valide\n");
            valido = 0;
            break;
        }else{
            int diag = controllaDiagonale(x_p, y_p, x_a, y_a);
            if(diag == 0){
                printf("Movimento non diagonale\n");
                valido = 0;
                break;
            }else if(diag >= 1){
                // Controllo che la direzione del movimento sia corretta
                int movimentoValido = controllaMovimentoColore(schema, x_p, y_p, x_a, y_a);
                
                if(movimentoValido == 0){
                    printf("Direzione di movimento non valida\n");
                    valido = 0;
                    break;
                }

                // Controllo che la casella di arrivo sia vuota
                if(schema[x_a][y_a] != 0){
                    printf("Casella di arrivo non vuota\n");
                    valido = 0;
                    break;
                }
                // Controllo tipo di mossa
                if(diag == 1){
                    // Mossa semplice
                    printf("Mossa semplice\n");
                }else if(diag == 2){
                    // Presa
                    // Controllo che la casella intermedia contenga una pedina avversaria
                    int x_m = (x_p + x_a) / 2;
                    int y_m = (y_p + y_a) / 2;
                    if(schema[x_m][y_m] == 0){
                        printf("Presa non valida\n");
                        valido = 0;
                        break;
                    }else{
                        printf("Presa\n");
                    }
                }else{
                    printf("Movimento diagonale troppo lungo\n");
                    valido = 0;
                    break;
                }
            }
        }
    }
    return valido;
}

int main(){
    int schema[8][8] = {
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, -1, 0, -1, 0, -1, 0, -1},
        {-1, 0, -1, 0, -1, 0, -1, 0},
        {0, -1, 0, -1, 0, -1, 0, -1}
    };

    int mosse1[2][2] = {
        {2, 1},
        {3, 0}
    };

    int mossa1 = controllaMossa(schema, mosse1, 2);
    printf("Mossa 1: %d\n", mossa1);
}
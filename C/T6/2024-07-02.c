/*
    Si supponga di aver definito una struttura intervallo i cui campi sono a e b entrambi di tipo double. 
    Un elemento di tipo intervallo rappresenta l’intervallo di numeri reali [a, b] (con a < b). 
    Scrivere un programma che legge dall’utente una sequenza di intervalli 
    (il numero di intervalli e gli intervalli stessi sono scelti dall’utente) 
    e mostra all’utente per ogni intervallo I tutti gli intervalli con cui I si sovrappone. 
    Due intervalli si sovrappongono se la loro intersezione è non nulla. 
*/

#include <stdio.h>
#include <stdlib.h>

struct intervallo{
    double a;
    double b;
};

int sovrapposizione(struct intervallo i_1, struct intervallo i_2){
    int sovrapposto = 0;
    
    if(i_1.a <= i_2.a && i_1.b >= i_2.a){
    /*
    i_1 __________
        |   _____|_____ i_2
        |   |    |    |
        |   |    |    |
        a   a    b    b
    */
        sovrapposto = 1;
    }else if(i_2.a <= i_1.a && i_2.b >= i_1.a){
    /*
    i_2 __________
        |   _____|_____ i_1
        |   |    |    |
        |   |    |    |
        a   a    b    b
    */
        sovrapposto = 1;
    }else if(i_1.a <= i_2.a && i_1.b >= i_2.b){
    /*
    i_1 _____________________
        |   __________ i_2  |
        |   |        |      |
        |   |        |      |
        a   a        b       b
    */
        sovrapposto = 1;
    }else if(i_2.a <= i_1.a && i_2.b >= i_1.b){
    /*
    i_2 _____________________
        |   __________ i_1  |
        |   |        |      |
        |   |        |      |
        a   a        b       b
    */
        sovrapposto = 1;
    }
    return sovrapposto;
}

int main(){
    int n;
    printf("Quanti intervalli vuoi inserire?");
    scanf("%d", &n);

    struct intervallo intervalli[n];
    for(int i = 0; i < n; i++){
        int continua = 1;
        while(continua == 1){
            printf("Inserisci gli estremi dell'intervallo\n", i);
            scanf("%lf %lf", &intervalli[i].a, &intervalli[i].b);
            if (intervalli[i].a >= intervalli[i].b){
                printf("Estremi non validi, reinserisci\n");
            } else {
                continua = 0;
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("Intervallo %d: [%.2lf, %.2lf]\n", i, intervalli[i].a, intervalli[i].b);
        // Per ogni intervallo, controllo se si incrocia con tutti gli altri
        // Per evitare ripeitizioni, controllo solo gli intervalli successivi
        for(int j = i+1; j < n; j++){
            if(sovrapposizione(intervalli[i], intervalli[j])){
                printf("Sovrapposizione con intervallo %d: [%.2lf, %.2lf]\n", j, intervalli[j].a, intervalli[j].b);
            }
        }
    }

}
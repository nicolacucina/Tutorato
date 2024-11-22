/*
    Si vuole realizzare un programma che simuli un gioco di domino. 
    A tale fine si scriva:
        - una struttura tessera con campi lato1 e lato2. 
        Entrambi i campi sono di tipo intero e può assumere un valore da 0 a 6.
        
        - Una funzione inizializzaTessere che riceve in ingresso un array di tipo tessera di dimensione 28 e 
        lo inizializza memorizzando in esso le possibili 28 tessere del domino. 
        Le tessere devono essere create generando per il lato1 tutti i possibili valori da 0 a 6 e 
        per il secondo tutti i valori maggiori o uguali a quello assegnato al lato 1. 
        Le coppie possibili sono cioè (0,0), (0,1), (0,2), (0,3), (0,4), (0,5), (0,6), (1,1), (1,2),..., (5,6), (6,6).
        
        - Una funzione mischiaTessere che riceve in ingresso un array di tipo tessera di dimensione 28 e lo
        mischia, cioè ne permuta casualmente gli elementi. 
        Per mischiare gli elementi utilizzare la seguente procedura: 
            per 10000 volte estrarre casualmente due indici i e j e scambiare gli elementi dell’array in posizione i e j.

        - La funzione main che crea un array di tipo tessera di dimensione 28, 
        lo inizializza e lo mischia (usando le funzioni precedenti) e poi esegue il seguente processo:
            -- scandisce le tessere nell’ordine in cui compaiono nell’array; 
            per ogni tessera (dalla seconda  in poi) verifica se la tessera corrente ha 
            almeno un lato in comune con la tessera precedente;
            se sì continua, altrimenti la scansione termina.
            -- se tutte le tessere sono state scandite, stampa un messaggio all’utente indicando che 
            le tessere sono state esaurite; 
            se le tessere non sono state tutte scandite viene stampato un messaggio che indica la cosa all’utente
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// enum valori_tessere{
//     ZERO,
//     UNO,
//     DUE,
//     TRE,
//     QUATTRO,
//     CINQUE,
//     SEI
// };

struct tessera{
    int lato1;
    int lato2;
};

void inizializzaTessere(struct tessera *tessere){
    // dovendo genere tutte le coppie di numeri da 0 a 6, possiamo usare due cicli for annidati
    // per evitare di generare coppie dove il secondo numero è minore del primo, il secondo ciclo parte da i
    int index = 0;
    for(int i = 0; i <= 6; i++){
        for(int j = i; j <= 6; j++){
            tessere[index].lato1 = i;
            tessere[index].lato2 = j;
            index++;
        }
    }
}

void mischiaTessere(struct tessera *tessere){
    for(int i = 0; i < 10000; i++){
        // rand() % 28 genera un numero casuale tra 0 e 27, non abbiamo problemi di indici
        int index1 = rand() % 28;
        int index2 = rand() % 28;
        // scambio delle tessere, quindi la variabile temp deve essere di tipo tessera
        struct tessera temp = tessere[index1];
        tessere[index1] = tessere[index2];
        tessere[index2] = temp;
    }
}

int main(){
    srand(time(0));
    struct tessera tessere[28];
    
    inizializzaTessere(tessere);
    mischiaTessere(tessere);
    
    int valore_precedente = -1;
    int tutte_tessere_scandite = 1;
    
    for(int i = 0; i < 28; i++){
        printf("Tessera %d: %d %d\n", i, tessere[i].lato1, tessere[i].lato2);
        if(i == 0){
            valore_precedente = tessere[i].lato2;
        }else{
            if(tessere[i].lato1 != valore_precedente && tessere[i].lato2 != valore_precedente){
                tutte_tessere_scandite = 0;
                break;
            }else if(tessere[i].lato1 == valore_precedente){
                valore_precedente = tessere[i].lato2;
            }else{
                printf("La tessera %d viene ruotata\n", i);
                valore_precedente = tessere[i].lato1;
            }
        }
    }
    if(tutte_tessere_scandite == 1){
        printf("Tutte le tessere sono state scandite\n");
    }else{
        printf("Le tessere non sono state tutte scandite\n");
    }
}
/*
    Si vuole realizzare un programma che simuli un gioco di carte. 
    
    A tale fine si scriva:
    
    - Una struttura carta con campi seme e valore. 
    Per semplicità entrambi i campi saranno di tipo intero; 
    il campo valore assumerà valori da 1 a 10, mentre il campo seme assumerà valori da 1 a 4 (1=bastoni, 2=coppe, 3=denari, 4=spade).
    
    - Una funzione inizializzaMazzo che riceve in ingresso un array di tipo carta di dimensione 40 e lo
    inizializza memorizzando in esso per ogni seme tutte le carte da 1 a 10.
    
    - Una funzione mischiaMazzo che riceve in ingresso un array di tipo carta di dimensione 40 e lo mischia, 
    cioè ne permuta casualmente gli elementi. 
    Per mischiare gli elementi utilizzare la seguente procedura: 
        per 10000 volte estrarre casualmente due indici i e j e scambiare gli elementi dell’array in posizion i e j.
    
    - La funzione main che crea un array di tipo carta di dimensione 40, lo inizializza e lo mischia 
    (usando le funzioni precedenti) e poi simula il gioco della carta più alta:
        -- chiede all’utente di indicare un indice da 0 a 39 e mostra all’utente la carta corrispondente
        (che rappresenta la carta estratta dall’utente);
        -- estrae un indice da 0 a 39 e mostra all’utente la carta corrispondente 
        (che rappresenta la carta estratta dal computer);
        -- dice all’utente chi ha vinto, cioè chi ha estratto la carta di valore più alto.

Nota: Per visualizzare le carte il seme può essere indicato come valore intero, non è cioè necessario indicare
bastoni, coppe, denari e spade, ma basta 1, 2, 3 e 4.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct carta{
    int seme;
    int valore;
};

void inizializzaMazzo(struct carta *mazzo){
    int index = 0;
    for(int i = 1; i <= 4; i++){
        for(int j = 1; j <= 10; j++){
            mazzo[index].seme = i;
            mazzo[index].valore = j;
            index++;
        }
    }
}

void mischiaMazzo(struct carta *mazzo){
    for(int i = 0; i < 10000; i++){
        int index1 = rand() % 40;
        int index2 = rand() % 40;

        struct carta temp = mazzo[index1];
        mazzo[index1] = mazzo[index2];
        mazzo[index2] = temp;
    }
}

int vincitore(struct carta carta_utente, struct carta carta_computer){
    int vincitore = 0;
    if(carta_utente.valore > carta_computer.valore){
        vincitore = 1;
    }else if(carta_utente.valore < carta_computer.valore){
        vincitore = -1;
    }else{
        vincitore = 0;
    }
    return vincitore;
}

int main(){
    srand(time(0));

    struct carta mazzo[40];

    inizializzaMazzo(mazzo);
    mischiaMazzo(mazzo);

    int indice_utente;
    int continua = 1;
    while(continua == 1){
        printf("Inserisci un indice da 0 a 39: ");
        scanf("%d", &indice_utente);
        if (indice_utente < 0 || indice_utente >= 40){
            printf("Indice non valido\n");
        }else{
            printf("Hai pescato la carta %d di seme %d\n", mazzo[indice_utente].valore, mazzo[indice_utente].seme);
            continua = 0;
        }
    }

    int indice_computer = rand() % 40;
    printf("Il computer ha pescato la carta %d di seme %d\n", mazzo[indice_computer].valore, mazzo[indice_computer].seme);

    int risultato = vincitore(mazzo[indice_utente], mazzo[indice_computer]);
    if(risultato == 1){
        printf("Hai vinto!\n");
    }else if(risultato == -1){
        printf("Hai perso!\n");
    }else{
        printf("Pareggio!\n");
    }
}
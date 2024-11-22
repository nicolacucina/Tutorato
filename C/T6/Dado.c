/*
    Si consideri il seguente gioco a due giocatori. 
    In una partita vengono lanciati un dado per ogni giocatore ed una moneta. 
    Se lanciando la moneta esce testa, la partita è vinta dal giocatore che ha ottenuto il punteggio più alto nel lancio del proprio dado. 
    Se invece esce croce, la partita è vinta dal giocatore che ha ottenuto il punteggio più basso. 
    Se i dadi hanno lo stesso valore, si ha un pareggio.


    Si consideri la definizione della seguente struttura:
        struct { char moneta; int dado1; int dado2; } partita;
    che rappresenta il risultato dei lanci associati ad una partita. 
    I campi dado1 e dado2 hanno un valore compreso tra 1 e 6, 
    il campo moneta ha valore ‘t’ (testa) oppure ‘c’ (croce). 
    
    Scrivere una funzione che prende come parametro una partita e restituisce:
        - 1 se ha vinto il giocatore 1
        - 2 se ha vinto il giocatore 2
        - 0 in caso di pareggio. 
        
    Scrivere poi un programma che chiede all’utente quante partite vuole fare. 
    Per ogni partita il programma deve lanciare due dadi e una moneta ed indicare chi ha vinto. 
    Il programma deve infine indicare il numero di partite vinte da ciascun giocatore ed il numero di pareggi
*/

#include <stdio.h>
#include <stdlib.h>

struct partita {
    char moneta;
    int dado1;
    int dado2;
};

int vittoria(struct partita p){
    int risultato = 0;
    if (p.moneta == 't') {
        if (p.dado1 > p.dado2) {
            risultato = 1;
        } else if (p.dado1 < p.dado2) {
            risultato = 2;
        } else {
            risultato = 0;
        }
    } else {
        if (p.dado1 < p.dado2) {
            risultato = 1;
        } else if (p.dado1 > p.dado2) {
            risultato = 2;
        } else {
            risultato = 0;
        }
    }
    return risultato;
}

int main(){
    int n;
    printf("Quante partite vuoi fare?");
    scanf("%d", &n);

    int vittorie1 = 0;
    int vittorie2 = 0;
    int pareggi = 0;
    for(int i = 0; i<n; i++){
        struct partita p;
        // la funziona rand() genera un numero casuale tra 0 e RAND_MAX, per ottenere un numero compreso tra 1 e 6
        // prima genero un numero casuale tra 0 e 5 utilizzando l'operatore di resto % e poi sommo 1
        p.dado1 = 1 + rand() % 6;
        p.dado2 = 1 + rand() % 6;
        // genero un numero casuale tra 0 e 1, se il numero è 0 la moneta è testa, altrimenti è croce
        int m = rand() % 2;
        if (m == 0) {
            p.moneta = 't';
        } else {
            p.moneta = 'c';
        }

        int risultato = vittoria(p);
        if (risultato == 1) {
            vittorie1++;
        } else if (risultato == 2) {
            vittorie2++;
        } else {
            pareggi++;
        }
    }
    printf("Giocatore 1 ha vinto %d partite\n", vittorie1);
    printf("Giocatore 2 ha vinto %d partite\n", vittorie2);
    printf("Ci sono stati %d pareggi\n", pareggi);
}
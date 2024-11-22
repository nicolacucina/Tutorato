/*
    Si supponga di aver definito la struttura data dotata dei campi giorno, mese ed anno tutti di tipo int. 
    Si scriva un programma che legge dall’utente una sequenza di date di nascita 
    (sia il numero delle date che il loro valore sono scelti dall’utente) 
    e la data odierna e mostra all’utente le età in anni corrispondenti a ciascuna data. 
    Gli anni da mostrare sono quelli già compiuti. 
    Un esempio di interazione tra l’utente e il programma è mostrato di seguito
        Quante date vuoi inserire?  
        3
        Inserisci la data n. 0 (campi separati da spazi)
        2 3 2003
        Inserisci la data n. 1 (campi separati da spazi)
        4 7 2004
        Inserisci la data n. 2 (campi separati da spazi)
        20 9 2004
        Inserisci la data di oggi
        16 7 2024
        La persona nata il 2/3/2003 ha 21 anni
        La persona nata il 4/7/2004 ha 20 anni
        La persona nata il 20/9/2004 ha 19 anni
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    int giorno;
    int mese;
    int anno;
};

int calcola_eta(struct data nascita, struct data oggi){
    int eta = oggi.anno - nascita.anno;
    if(nascita.mese > oggi.mese || (nascita.mese == oggi.mese && nascita.giorno > oggi.giorno)){
        eta--;
    }
    return eta;
}

int main(){
    int n;
    printf("Quante date vuoi inserire? ");
    scanf("%d", &n);

    struct data date[n];
    for(int i = 0; i < n; i++){
        printf("Inserisci la data n. %d (campi separati da spazi)\n", i);
        scanf("%d %d %d", &date[i].giorno, &date[i].mese, &date[i].anno);
    }

    struct data oggi;
    printf("Inserisci la data di oggi\n");
    scanf("%d %d %d", &oggi.giorno, &oggi.mese, &oggi.anno);

    for(int i = 0; i<n; i++){
        int eta = calcola_eta(date[i], oggi);
        printf("La persona nata il %d/%d/%d ha %d anni\n", date[i].giorno, date[i].mese, date[i].anno, eta);
    }
}
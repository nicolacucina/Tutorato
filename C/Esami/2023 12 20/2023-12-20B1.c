/*
    In enigmistica una zeppa doppia è una coppia di parole tale che la seconda può essere ottenuta 
    dalla prima inserendo due lettere (in due posizioni qualsiasi). 
    Un esempio di scambio di consonanti è dato dalle parole abito / arbitro. 
    Scrivere un programma che fa inserire all’utente due stringhe e dice all'utente 
    se le due stringhe formano una zeppa doppia.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input_utente(char *s){
    printf("Inserisci una stringa: ");

    fgets(s, 100, stdin);
    int len = strlen(s);
    if(s[len-1] == '\n'){
        s[len-1] = '\0';
    }    
}

int zeppa_doppia(char *s1, char *s2){
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int risultato = 0;
    if(len1 != len2-2){
        printf("Le due stringhe non formano una zeppa doppia\n");
        risultato = 0;
    }else{
        int i = 0;
        int j = 0;
        char diff[2];
        int diff_index = 0;
        while(i < len1 && j < len2){
            // printf("i: %d, j: %d\n", i, j);
            // printf("s1[i]: %c, s2[j]: %c\n", s1[i], s2[j]);
            if(s1[i] == s2[j]){
                i++;
                j++;
            }else{
                diff[diff_index] = s2[j];
                diff_index++;
                j++;
            }
        }
        // printf("Diff: %c\n", diff[0]);
        // printf("Diff: %c\n", diff[1]);

        if(diff[0] == diff[1]){
            printf("Le due stringhe formano una zeppa doppia\n");
            risultato = 1;
        }else{
            printf("Le due stringhe non formano una zeppa doppia\n");
            risultato = 0;
        }
    }

    return risultato;
}

int main(){
    char s1[100], s2[100];
    input_utente(s1);
    input_utente(s2);

    int risultato = zeppa_doppia(s1, s2);
    printf("Risultato: %d\n", risultato);
}
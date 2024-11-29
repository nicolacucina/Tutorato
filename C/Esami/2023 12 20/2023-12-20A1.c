/*
    In enigmistica uno scambio di consonanti è una coppia di parole che possono essere ottenute l'una
    dall'altra scambiando si posto due consonanti. 
    Un esempio di scambio di consonanti è dato dalle parole maschera / marchesa. 
    Scrivere un programma che fa inserire all’utente due stringhe e dice all’utente se le 
    due stringhe formano uno scambio di consonanti
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input_utente(char *s){
    printf("Inserisci la stringa: ");

    fgets(s, 100, stdin);
    int len = strlen(s);
    if(s[len-1] == '\n'){
        s[len-1] = '\0';
    }
}

int scambio_consontanti(char *s1, char *s2){
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int risultato;
    if(len1 != len2){
        risultato = 0;
    }else{
        char scambiare[2];
        int primo_scambio = 0;
        for(int i = 0; i<len1; i++){
            if(s1[i] != s2[i]){
                if(primo_scambio == 0){
                    primo_scambio++;
                    scambiare[0] = s1[i];
                    scambiare[1] = s2[i];
                }else if(primo_scambio == 1){
                    if(s1[i] == scambiare[1] && s2[i] == scambiare[0]){
                        risultato = 1;
                    }else{
                        risultato = 0;
                        break;
                    }
                }else{
                    risultato = 0;
                    break;
                }
            }
        }
    }
}

int main(){
    char s1[100], s2[100];
    input_utente(s1);
    input_utente(s2);

    int risultato = scambio_consontanti(s1, s2);
    if(risultato){
        printf("Le due stringhe formano uno scambio di consonanti\n");
    }else{
        printf("Le due stringhe non formano uno scambio di consonanti\n");
    }
}
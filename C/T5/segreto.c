/*
Scrivere un programma che, date due stringhe di caratteri tutti minuscoli denominate msg e secret 
(non più lunga di msg),  stabilisca se tutti i caratteri di secret sono contenuti nello stesso ordine 
(ma eventualmente intervallati da altri caratteri) nella stringa msg. 
In caso positivo, il programma deve restituire una copia di msg dove ad ogni lettera
riconosciuta come facente parte di secret viene sostituita la lettera maiuscola. Ad esempio, se msg
fosse "ma che bel castello" e secret fosse "cestello", il programma dovrebbe dare un risultato
positivo e restituire "ma ChE bel caSTELLO"
*/

#include <stdio.h>
#include <string.h>

void inserisci_stringa(char *s1, int n){
    printf("Inserisci la stringa: \n");

    fgets(s1, n, stdin);
    int len = strlen(s1);
    if(s1[len-1] == '\n'){
        s1[len-1] = '\0';
    }
}

void cerca_secret(char *msg, char *secret){
    int index = 0;
    int trovato = 0;
    for(int i = 0; msg[i] != '\0'; i++){
        if(msg[i] == secret[index]){
            index++;
            if(secret[index] == '\0'){
                trovato = 1;
                break;
            }
        }
    }


    if(trovato){
        index = 0;
        for(int i = 0; msg[i] != '\0'; i++){
            if(msg[i] == secret[index]){
                // A = 65
                // a = 97
                msg[i] = msg[i] - 32;
                index++;
                if(secret[index] == '\0'){
                    break;
                }
            }
        }
        printf("La stringa segreta è contenuta\n");
        printf("Stringa modificata: %s\n", msg);
    }else{
        printf("La stringa segreta non è contenuta\n");
    }
}

int main(){
    int n = 100;
    char msg[n], secret[n];

    inserisci_stringa(msg, n);
    inserisci_stringa(secret, n);

    cerca_secret(msg, secret);
}
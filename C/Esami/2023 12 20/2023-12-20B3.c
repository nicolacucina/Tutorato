/*
    Si vuole realizzare un programma che realizza un semplice motore database di persone. 
    Per ogni persona vengono memorizzati il nome, il cognome e il padre. 
    A tal fine si definisca una struttura persona che permetta di memorizzare:
        nome (max 20 caratteri), 
        cognome (max 20 caratteri) 
        nome_padre (max 20 caratteri) 
    
    Si scriva un programma che: 
    - utilizza un array di dimensione 10 di tipo persone che viene inizializzato con 10 persone all’atto della creazione; 
    - permette all’utente di eseguire le seguenti operazioni (tramite un opportuno menu): 
        -- cerca persone per cognome: il programma chiede all’utente di inserire due nome n1 e n2 
        e stampa tutte le persone con nome n1 e il cui padre si chiama n2; 
        -- cerca fratelli di: il programma chiede all’utente di inserire un nome n e cerca per ogni 
        persona che si chiama n tutti i suoi fratelli, cioè persone che hanno lo stesso cognome e un 
        padre con lo stesso nome;  
        -- stampa persone: il programma mostra all’utente tutte le persone; 
        -- esci: il programma termina
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct persona{
    char nome[20];
    char cognome[20];
    char nome_padre[20];
};

void init_persone(struct persona *persone){
    strcpy(persone[0].nome, "Mario");
    strcpy(persone[0].cognome, "Rossi");
    strcpy(persone[0].nome_padre, "Giovanni");

    strcpy(persone[1].nome, "Luca");
    strcpy(persone[1].cognome, "Rossi");
    strcpy(persone[1].nome_padre, "Giovanni");

    strcpy(persone[2].nome, "Giovanni");
    strcpy(persone[2].cognome, "Rossi");
    strcpy(persone[2].nome_padre, "Giuseppe");

    strcpy(persone[3].nome, "Giuseppe");
    strcpy(persone[3].cognome, "Rossi");
    strcpy(persone[3].nome_padre, "NULL");

    strcpy(persone[4].nome, "Mario");
    strcpy(persone[4].cognome, "Verdi");
    strcpy(persone[4].nome_padre, "Giovanni");

    strcpy(persone[5].nome, "Luca");
    strcpy(persone[5].cognome, "Verdi");
    strcpy(persone[5].nome_padre, "Giovanni");

    strcpy(persone[6].nome, "Giovanni");
    strcpy(persone[6].cognome, "Verdi");
    strcpy(persone[6].nome_padre, "Giuseppe");

    strcpy(persone[7].nome, "Giuseppe");
    strcpy(persone[7].cognome, "Verdi");
    strcpy(persone[7].nome_padre, "NULL");

    strcpy(persone[8].nome, "Mario");
    strcpy(persone[8].cognome, "Bianchi");
    strcpy(persone[8].nome_padre, "Giovanni");

    strcpy(persone[9].nome, "Luca");
    strcpy(persone[9].cognome, "Bianchi");
    strcpy(persone[9].nome_padre, "Giovanni");
}

void stampa_per_cognome(struct persona *persone, char *nome, char *nome_padre){
    for(int i = 0; i<10; i++){
        if(strcmp(persone[i].nome, nome) == 0 && strcmp(persone[i].nome_padre, nome_padre) == 0){
            printf("Nome: %s, Cognome: %s, Nome Padre: %s\n", persone[i].nome, persone[i].cognome, persone[i].nome_padre);
        }
    }
}

void stampa_fratelli(struct persona *persone, char *nome){
    for(int i = 0; i<10; i++){
        if(strcmp(persone[i].nome, nome) == 0){
            for(int j = 0; j<10; j++){
                if(strcmp(persone[j].cognome, persone[i].cognome) == 0 && strcmp(persone[j].nome_padre, persone[i].nome_padre) == 0){
                    printf("Nome: %s, Cognome: %s, Nome Padre: %s\n", persone[j].nome, persone[j].cognome, persone[j].nome_padre);
                }
            }
        }
    }

}

void stampa_persone(struct persona *persone){
    for(int i = 0; i<10; i++){
        printf("Nome: %s, Cognome: %s, Nome Padre: %s\n", persone[i].nome, persone[i].cognome, persone[i].nome_padre);
    }
}

int main(){
    struct persona persone[10];
    init_persone(persone);
    
    char comando[100];
    int continua = 1;
    while(continua){
        printf("Inserisci il comando: \n cerca persone per cognome\n cerca fratelli di\n stampa persone\n esci\n");

        fgets(comando, 100, stdin);
        int len = strlen(comando);
        if(comando[len-1] == '\n'){
            comando[len-1] = '\0';
        }

        printf("Comando: %s\n", comando);

        if(strcmp(comando, "cerca persone per cognome") == 0){
            char n1[20], n2[20];
            printf("Inserisci il nome\n");
            scanf("%s", n1);
            printf("Inserisci il nome del padre\n");
            scanf("%s", n2);
            stampa_per_cognome(persone, n1, n2);
        } else if(strcmp(comando, "cerca fratelli di") == 0){
            char n[20];
            printf("Inserisci il nome\n");
            scanf("%s", n);
            stampa_fratelli(persone, n);
        } else if(strcmp(comando, "stampa persone") == 0){
            stampa_persone(persone);
        } else if(strcmp(comando, "esci") == 0){
            continua = 0;
        }
    }
}
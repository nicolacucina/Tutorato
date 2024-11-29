#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contatto{
    char nome[20];
    char cognome[20];
    char numero[10];
};

void init_rubrica(struct contatto *rubrica){
    for(int i = 0; i < 100; i++){
        strcpy(rubrica[i].nome, "");
        strcpy(rubrica[i].cognome, "");
        strcpy(rubrica[i].numero, "");
    }
}

void inserisci_contatto(struct contatto *rubrica, char *nome, char *cognome, char *numero){
    for(int i = 0; i < 100; i++){
        if(strcmp(rubrica[i].nome, "") == 0){
            strcpy(rubrica[i].nome, nome);
            strcpy(rubrica[i].cognome, cognome);
            strcpy(rubrica[i].numero, numero);
            printf("Contatto inserito.\n");
            return;
        }
    }
    printf("Rubrica piena.\n");
}

int trova_contatto(struct contatto *rubrica, char *nome, char *cognome){
    for(int i = 0; i < 100; i++){
        if(strcmp(rubrica[i].nome, nome) == 0 && strcmp(rubrica[i].cognome, cognome) == 0){
            return i;
        }
    }
    return -1;
}

void cerca_contatto(struct contatto *rubrica, char *nome, char *cognome){
    int indice = trova_contatto(rubrica, nome, cognome);
    if(indice != -1){
        printf("Contatto trovato:\n");
        printf("Nome: %s\n", rubrica[indice].nome);
        printf("Cognome: %s\n", rubrica[indice].cognome);
        printf("Numero: %s\n", rubrica[indice].numero);
    }else{
        printf("Contatto non trovato.\n");
    }
}

void cancella_contatto(struct contatto *rubrica, char *nome, char *cognome){
    int indice = trova_contatto(rubrica, nome, cognome);
    if(indice != -1){
        strcpy(rubrica[indice].nome, "");
        strcpy(rubrica[indice].cognome, "");
        strcpy(rubrica[indice].numero, "");    
        printf("Contatto cancellato.\n");
    }else{
        printf("Contatto non trovato.\n");
    }
}

int main(){
    struct contatto rubrica[100];
    init_rubrica(rubrica);

    char comando[50];
    int continua = 1;
    while(continua == 1){
        printf("Inserisci un comando: \n");
        fgets(comando, 50, stdin);
        int len = strlen(comando);
        comando[len-1] = '\0';

        if(strcmp(comando, "inserisci contatto") == 0){
            char nome[20];
            char cognome[20];
            printf("Inserisci il nome del contatto: \n");
            fgets(nome, 20, stdin);
            len = strlen(nome);
            nome[len-1] = '\0';
            printf("Inserisci il cognome del contatto: \n");
            fgets(cognome, 20, stdin);
            len = strlen(cognome);
            cognome[len-1] = '\0';
            printf("Inserisci il numero del contatto: \n");
            char numero[10];
            fgets(numero, 10, stdin);
            len = strlen(numero);
            numero[len-1] = '\0';

            inserisci_contatto(rubrica, nome, cognome, numero);
        }else if(strcmp(comando, "cerca contatto") == 0){
            char nome[20];
            char cognome[20];
            printf("Inserisci il nome del contatto da cancellare: ");
            fgets(nome, 20, stdin);
            len = strlen(nome);
            nome[len-1] = '\0';
            printf("Inserisci il cognome del contatto da cancellare: ");
            fgets(cognome, 20, stdin);
            len = strlen(cognome);
            cognome[len-1] = '\0';

            cerca_contatto(rubrica, nome, cognome);
        }else if(strcmp(comando, "cancella contatto") == 0){
            char nome[20];
            char cognome[20];
            printf("Inserisci il nome del contatto da cancellare: ");
            fgets(nome, 20, stdin);
            len = strlen(nome);
            nome[len-1] = '\0';
            printf("Inserisci il cognome del contatto da cancellare: ");
            fgets(cognome, 20, stdin);
            len = strlen(cognome);
            cognome[len-1] = '\0';

            cancella_contatto(rubrica, nome, cognome);
        }else if(strcmp(comando, "esci") == 0){
            printf("Arrivederci.\n");
            continua = 0;
        }else{
            printf("Comando non riconosciuto.\n");
        }
    }
}
/*
    Si vuole realizzare un programma che realizza un semplice motore di ricerca di voli aerei. 
    Per ogni volo vengono memorizzati città di partenza e di arrivo e numero del volo. 
    A tal fine si definisca una struttura volo che permetta di memorizzare:
        -partenza (max 20 caratteri), 
        -arrivo (max 20 caratteri)
        -numero (stringa di 5 caratteri)
        
    Si scriva un programma che:
    • utilizza un array di dimensione 10 di tipo volo che viene inizializzato con 10 voli all’atto della creazione;
    • permette all’utente di eseguire le seguenti operazioni (tramite un opportuno menu):
        o cerca voli: il programma chiede all’utente di inserire una città di partenza cp e una di
        destinazione cd e stampa i dati di tutti i voli che partono da cp e arrivano a cd;
        o cerca voli con uno scalo: il programma chiede all’utente di inserire una città di partenza cp e
        una di destinazione cd e stampa tutte le soluzioni di volo che partono da cp e arrivano a cd
        facendo un solo scalo nel mezzo;
        o stampa voli: il programma mostra all’utente tutti i voli disponibili;
        o esci: il programma termina.
*/

#include <stdio.h>
#include <string.h>

struct volo{
    char partenza[20];
    char arrivo[20];
    char numero[5];
};

void init_voli(struct volo *voli){
    struct volo volo1 = {"Roma", "Milano", "12345"};
    struct volo volo2 = {"Milano", "Venezia", "54321"};
    struct volo volo3 = {"Roma", "Torino", "67890"};
    struct volo volo4 = {"Milano", "Roma", "09876"};
    struct volo volo5 = {"Torino", "Milano", "54321"};
    struct volo volo6 = {"Milano", "Palermo", "12345"};
    struct volo volo7 = {"Palermo", "Perugia", "09876"};
    struct volo volo8 = {"Firenze", "Roma", "67890"};
    struct volo volo9 = {"Bari", "Milano", "54321"};
    struct volo volo10 = {"Milano", "Cagliari", "12345"};
    voli[0] = volo1;
    voli[1] = volo2;
    voli[2] = volo3;
    voli[3] = volo4;
    voli[4] = volo5;
    voli[5] = volo6;
    voli[6] = volo7;
    voli[7] = volo8;
    voli[8] = volo9;
    voli[9] = volo10;
}

void cerca_volo(struct volo *voli, char *cp, char *cd){
    for(int i = 0; i<10; i++){
        if(strcmp(voli[i].partenza, cp) == 0 && strcmp(voli[i].arrivo, cd) == 0){
            printf("Volo %d: %s -> %s, numero: %s\n", i, voli[i].partenza, voli[i].arrivo, voli[i].numero);
        }
    }
}

void cerca_volo_con_scalo(struct volo *voli, char *cp, char *cd){
    printf("Citta di partenza: %s\n", cp);
    printf("Citta di destinazione: %s\n", cd);
    for(int i = 0; i<10; i++){
        if(strcmp(voli[i].partenza, cp) == 0){
            for(int j = 0; j<10; j++){
                if(strcmp(voli[j].partenza, voli[i].arrivo) == 0 && strcmp(voli[j].arrivo, cd) == 0){
                    printf("Volo %d: %s -> %s, numero: %s\n", i, voli[i].partenza, voli[i].arrivo, voli[i].numero);
                    printf("Volo %d: %s -> %s, numero: %s\n", j, voli[j].partenza, voli[j].arrivo, voli[j].numero);
                }
            }
        }
    }
}

void stampa_voli(struct volo *voli){
    for(int i = 0; i<10; i++){
        printf("Volo %d: %s -> %s, numero: %s\n", i, voli[i].partenza, voli[i].arrivo, voli[i].numero);
    }
}

int main(){
    struct volo voli[10];
    init_voli(voli);

    char comando[100];
    int continua = 1;
    while(continua == 1){
        printf("Inserisci un comando:\n");
        fgets(comando, 100, stdin);
        int len = strlen(comando);
        if(comando[len-1] == '\n'){
            comando[len-1] = '\0';
        }

        if(strcmp(comando, "cerca voli") == 0){
            char cp[50];
            char cd[50];
            printf("Inserisci la città di partenza:\n ");
            fgets(cp, 50, stdin);
            len = strlen(cp);
            if(cp[len-1] == '\n'){
                cp[len-1] = '\0';
            }

            printf("Inserisci la città di destinazione:\n ");
            fgets(cd, 50, stdin);
            len = strlen(cd);
            if(cd[len-1] == '\n'){
                cd[len-1] = '\0';
            }
            
            cerca_volo(voli, cp, cd);
        }else if(strcmp(comando, "cerc voli con uno scalo") == 0){
            char cp[50];
            char cd[50];
            printf("Inserisci la città di partenza:\n ");
            fgets(cp, 50, stdin);
            len = strlen(cp);
            if(cp[len-1] == '\n'){
                cp[len-1] = '\0';
            }

            printf("Inserisci la città di destinazione:\n ");
            fgets(cd, 50, stdin);
            len = strlen(cd);
            if(cd[len-1] == '\n'){
                cd[len-1] = '\0';
            }
            
            cerca_volo_con_scalo(voli, cp, cd);
        }else if(strcmp(comando, "stampa voli") == 0){
            stampa_voli(voli);
        }else if(strcmp(comando, "esci") == 0){
            printf("Arrivederci\n");
            continua = 0;
        }else{
            printf("Comando non riconosciuto\n");
        }
    }
}
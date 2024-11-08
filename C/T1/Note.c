// Scrivere un programma C che fa inserire all'utente tre numeri interi compresi tra 
// 1 e 7, ognuno dei quali rappresenta una nota musicale (1=Do, 2=Re, ecc.) e visualizza all’utente 1 
// se le tre note inserite formano l'accordo di Do maggiore, 0 altrimenti. Si ricorda che l’accordo di Do 
// maggiore è formato dalle note Do, Mi e Sol. Ad esempio, se l’utente inserisse 5 (=Sol), 1 (=Do) e 3 
// (=Mi)  il  programma  dovrebbe  restituire  1;  se  l’utente  inserisse  1  (=Do),  4  (=Fa)  e  2  (=Re)  il 
// programma dovrebbe restituire 0; se l’utente inserisse  1  (=Do),  1  (=Do)  e  3  (=Mi)  il  programma 
// dovrebbe restituire 0
#include <stdio.h>

int main(){
    int primaNota, secondaNota, terzaNota, primoAccordo, secondoAccordo, terzoAccordo, quartoAccordo, quintoAccordo, sestoAccordo, accordo;
    printf("Inserire tre valori interi: ");
    // In modo compatto
    // scanf("%d %d %d", &primaNota, &secondaNota, &terzaNota);
    scanf("%d", &primaNota);
    scanf("%d", &secondaNota);
    scanf("%d", &terzaNota);
    // Sono valide tutte le configurazioni del DoMaggiore, quindi
    // Do Mi Sol --> 1 3 5
    // Do Sol Mi --> 1 5 3
    // Mi Do Sol --> 3 1 5
    // Mi Sol Do --> 3 5 1
    // Sol Do Mi --> 5 1 3
    // Sol Mi Do --> 5 3 1
    // In modo compatto
    // accordo = (primaNota == 1 && secondaNota == 3 && terzaNota == 5) || (primaNota == 1 && secondaNota == 5 && terzaNota == 3) || (primaNota == 3 && secondaNota == 1 && terzaNota == 5) || (primaNota == 3 && secondaNota == 5 && terzaNota == 1) || (primaNota == 5 && secondaNota == 3 && terzaNota == 1) || (primaNota == 5 && secondaNota == 1 && terzaNota == 3);
    primoAccordo = (primaNota == 1 && secondaNota == 3 && terzaNota == 5); 
    secondoAccordo = (primaNota == 1 && secondaNota == 5 && terzaNota == 3);
    terzoAccordo = (primaNota == 3 && secondaNota == 1 && terzaNota == 5);
    quartoAccordo = (primaNota == 3 && secondaNota == 5 && terzaNota == 1);
    quintoAccordo = (primaNota == 5 && secondaNota == 3 && terzaNota == 1);
    sestoAccordo = (primaNota == 5 && secondaNota == 1 && terzaNota == 3);
    accordo = primoAccordo || secondoAccordo || terzoAccordo || quartoAccordo || quintoAccordo || sestoAccordo;
    printf("Le note inserite formano un accordo DoMaggiore? 0) No 1) Si -> %d\n", accordo);
    // Utilizzando gli if
    if(primaNota == 1){
        if(secondaNota == 3){
            if(terzaNota == 5){
                printf("Le note formano un accordo DoMaggiore");
            }else{
                printf("Le note non formano un accordo DoMaggiore");
            }
        }else if(secondaNota == 5){
            if(terzaNota == 3){
                printf("Le note formano un accordo DoMaggiore");
            }else{
                printf("Le note non formano un accordo DoMaggiore");
            }
        }else{
            printf("Le note non formano un accordo DoMaggiore");
        }
    }else if(primaNota == 3){
        if(secondaNota == 1){
            if(terzaNota == 5){
                printf("Le note formano un accordo DoMaggiore");
            }else{
                printf("Le note non formano un accordo DoMaggiore");
            }
        }else if(secondaNota == 5){
            if(terzaNota == 1){
                printf("Le note formano un accordo DoMaggiore");
            }else{
                printf("Le note non formano un accordo DoMaggiore");
            }
        }else{
            printf("Le note non formano un accordo DoMaggiore");
        }
    }else if(primaNota == 5){
        if(secondaNota == 1){
            if(terzaNota == 3){
                printf("Le note formano un accordo DoMaggiore");
            }else{
                printf("Le note non formano un accordo DoMaggiore");
            }
        }else if(secondaNota == 3){
            if(terzaNota == 1){
                printf("Le note formano un accordo DoMaggiore");
            }else{
                printf("Le note non formano un accordo DoMaggiore");
            }
        }else{
            printf("Le note non formano un accordo DoMaggiore");
        }
    }else{
        printf("Le note non formano un accordo DoMaggiore");
    }
}

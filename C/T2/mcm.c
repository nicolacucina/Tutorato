// Scrivere un programma C che calcoli il
// minimo comune multiplo (MCM) tra due numeri interi positivi.
// [Nota: dati due numeri n1 e n2, il loro mcm è il più piccolo numero m che è divisibile (ovvero, la divisione da resto 0)
// sia per n1 che per n2].

#include <stdio.h>

int main(){
    int n1, n2, mcm, i;
    printf("Inserisci un numero intero: ");
    scanf("%d", &n1);
    printf("Inserisci un altro numero intero: ");
    scanf("%d", &n2);
    if (n1 < 0 || n2 < 0){
        printf("I numeri devono essere positivi\n");
    } else{
        for (i = 1; i <= n1 * n2; i++){
            if (i % n1 == 0 && i % n2 == 0){
                mcm = i;
                break;
            }
        }
        printf("Il minimo comune multiplo tra %d e %d e' %d\n", n1, n2, mcm);
    }

}
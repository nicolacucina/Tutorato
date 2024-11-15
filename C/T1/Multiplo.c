// Scrivere un programma in C che legga due interi e determini e stampi se il 
// primo è un multiplo del secondo
#include <stdio.h>

int main(){
    int a, b, resto, multiplo;
    printf("Inserire due numeri interi: ");
    // In modo compatto
    // scanf("%d %d", &a, &b);
    scanf("%d", &a);
    scanf("%d", &b);
    resto = a % b;
    multiplo = (resto == 0);
    printf("Il resto della divisione tra %d e %d e': %d\n", a, b, resto);
    printf("Sono multipli? 0) No 1) Si -> %d", multiplo);
    // Utilizzando gli if
    if(resto == 0){
        printf("\nSono multipli");
    }else{
        printf("\nNon sono multipli");
    }
}
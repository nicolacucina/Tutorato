// Data l'equazione  ax +b = 0, con a e b inseriti da tastiera,
// scrivere un programma C per determinare il valore di che, se esiste, risolve l’equazione
#include <stdio.h>

int main(){
    double a, b, x;
    printf("Inserisci il valore di a: ");
    scanf("%lf", &a);
    printf("Inserisci il valore di b: ");
    scanf("%lf", &b);
    if (a == 0){
        if (b == 0){
            printf("L'equazione ha infinite soluzioni\n");
        } else {
            printf("L'equazione non ha soluzioni\n");
    }else{
        x = -b / a;
        printf("Il valore di x e' %f\n", x);
    }
}
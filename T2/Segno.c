// Scrivere un programma C che acquisisce da tastiera un numero
// e stampa un messaggio per indicare se tale numero è positivo o negativo
#include <stdio.h>

int main() {
    double n;
    printf("Inserisci un numero: ");
    scanf("%lf", &n);
    if (n == 0) {
        printf("Il numero %f e' 0\n", n);
    } else if (n > 0) {
        printf("Il numero %f e' positivo\n", n);
    } else {
        printf("Il numero %f e' negativo\n", n);
    }
}
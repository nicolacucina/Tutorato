#include <stdio.h>

int somma_cifre_ricorsiva(int n, int somma){
    if(n == 0){
        return somma;
    }
    somma += n % 10;
    return somma_cifre_ricorsiva(n / 10, somma);
}

int somma_cifre_iterativa(int n){
    int somma = 0;
    while(n > 0){
        somma += n % 10;
        n /= 10;
    }
    return somma;
}

int main(){
    int n;
    printf("Inserisci un numero: ");
    scanf("%d", &n);
    printf("La somma delle cifre di %d e' %d\n", n, somma_cifre_ricorsiva(n, 0));
}
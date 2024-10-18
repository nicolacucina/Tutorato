// Scrivere un programma in C che riceve in ingresso un numero 
// di quattro cifre, separi il numero nelle sue cifre individuali e stampi le cifre ciascuna separata dall'altra 
// da tre spazi. [Suggerimento: usare divisioni intere e resti.] Per esempio, se il numero fosse 2024, 
// l'output del programma dovrebbe essere 2   0   2   4
#include <stdio.h>

int main(){
    int valore, primaCifra, secondaCifra, terzaCifra, quartaCifra;
    printf("Inserire un valore intero a 4 cifre: ");
    scanf("%d", &valore);
    primaCifra = valore / 1000;
    secondaCifra = (valore % 1000) / 100;
    terzaCifra = (valore % 100) / 10;
    quartaCifra = valore % 10;
    printf("%d   %d   %d   %d", primaCifra, secondaCifra, terzaCifra, quartaCifra);
}
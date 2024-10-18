//  Si scriva un programma in linguaggio C che legga un valore 
// intero e visualizzi l'intero a esso precedente e l'intero a esso successivo
#include <stdio.h>

int main(){
    int num;
    printf("Inserire un numero intero: ");
    scanf("%d", &num);
    // Scrittura compatta
    // printf("Il numero fornito e': %d, il precedente e': %d, il successivo e': %d", num, num-1, num+1);
    printf("Il numero fornito e': %d\n", num);
    printf("Il precedente e': %d\n", num-1);
    printf("Il successivo e': %d", num+1);
}
// Si scriva un programma in linguaggio C che, dopo aver ricevuto 
// due  numeri  reali  x, y inseriti  da  tastiera, compia le operazioni di somma x+y,
// sottrazione x-y, moltiplicazione x*y, divisione x/y e media (x+y)/2 tra di essi.
//  Per semplicità, si consideri il caso in cui y≠0
#include <stdio.h>

int main(){
    float x, y, somma, sottrazione, moltiplicazione, divisione, media;
    printf("Inserire due numeri reali:");
    // In modo compatto
    // scanf("%f %f", &x, &y);
    scanf("%f", &x);
    scanf("%f", &y);
    // In modo compatto
    // printf("La somma e': %f, la sottrazione e': %f, la moltiplicazione e': %f, la divisione e': %f, la media e': %f", x+y, x-y, x*y, x/y, (x+y)/2);    
    somma = x + y;
    sottrazione = x - y;
    moltiplicazione = x * y;
    divisione = x / y;
    media = (x + y) / 2;
    printf("La somma e': %f\n", somma);
    printf("La sottrazione e': %f\n", sottrazione);
    printf("La moltiplicazione e': %f\n", moltiplicazione);
    printf("La divisione e': %f\n", divisione);
    printf("La media e': %f", media);    
}
/*
Scrivi un programma in C che permetta all'utente di
inserire una temperatura in gradi Celsius e poi la converta in gradi Fahrenheit utilizzando due
funzioni separate. Una funzione dovrebbe accettare la temperatura in gradi Celsius come
argomento e restituire la temperatura equivalente in gradi Fahrenheit, mentre l'altra funzione
dovrebbe gestire l'input/output dell'utente
*/

#include <stdio.h>

/*
// Se non usassi le funzioni inserisco tutto nel main
int main(){
    double celsius;
    printf("Inserisci la temperatura in gradi Celsius: ");
    scanf("%lf", &celsius);
    double fahrenheit = celsius * 9 / 5 + 32;
    printf("La temperatura in gradi Fahrenheit e': %lf\n", fahrenheit);
}
*/

double converti_temp(double celsius){
    double fahrenheit = celsius * 9 / 5 + 32;
    return fahrenheit;
}

double input_temp(){
    double celsius;
    printf("Inserisci la temperatura in gradi Celsius: ");
    scanf("%lf", &celsius);
    return celsius;
}

int main(){
    double celsius = input_temp();
    double fahrenheit = converti_temp(celsius);
    printf("La temperatura in gradi Fahrenheit e': %lf\n", fahrenheit);
}
/*
    Definire una struttura di nome complesso dotata di due campi:
    re, im di tipo double per rappresentare numeri complessi. 
    
    Scrivere una funzione prodotto che riceve come parametri due numeri complessi e restituisce il prodotto dei due numeri. 
    
    Scrivere poi un programma che fa inserire all'utente la parte reale e la parte immaginaria di due numeri complessi 
    e stampa il prodotto dei due numeri inseriti.
    
    [Nota: il prodotto di due numeri complessi 𝑎 + 𝑖𝑏 e 𝑐 + 𝑖𝑑 è dato da (𝑎𝑐 − 𝑏𝑑) + 𝑖(𝑏𝑐 + 𝑎𝑑)]
*/

#include <stdio.h>

struct complesso {
    double re;
    double im;
};

struct complesso prodotto(struct complesso a, struct complesso b) {
    struct complesso risultato;
    risultato.re = a.re * b.re - a.im * b.im;
    risultato.im = a.im * b.re + a.re * b.im;
    return risultato;
}

int main(){
    double re, im;
    struct complesso a, b, c;

    printf("Inserisci la parte reale del primo numero complesso: ");
    scanf("%lf", &re);
    printf("Inserisci la parte immaginaria del primo numero complesso: ");
    scanf("%lf", &im);
    a.re = re;
    a.im = im;

    printf("Inserisci la parte reale del secondo numero complesso: ");
    scanf("%lf", &re);
    printf("Inserisci la parte immaginaria del secondo numero complesso: ");
    scanf("%lf", &im);
    b.re = re;
    b.im = im;

    c = prodotto(a, b);
    printf("Il prodotto dei due numeri complessi e': %.2lf + %.2lfi\n", c.re, c.im);
}
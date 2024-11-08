// Scrivere un programma C che legge da tastiera i valori
// delle lunghezze dei tre lati di un triangolo detti A, B e C (si assuma che i valori dei lati inseriti
// rappresentino correttamente un triangolo). Verificare, nell'ordine, se il triangolo è equilatero,
// isoscele, scaleno o rettangolo.
// [Osservazione: come si fa a verificare se i lati inseriti da tastiera rappresentino effettivamente un
// triangolo?] 
// Suggerimento: un triangolo è rettangolo se il quadrato del lato più lungo è uguale alla somma dei quadrati degli altri due lati.
// https://www.wikihow.it/Determinare-se-una-Figura-Geometrica-a-Tre-Lati-%C3%A8-un-Triangolo
#include <stdio.h>
#include <math.h>

int main(){
    double A, B, C, pitagora;
    printf("Inserisci la lunghezza del lato A: ");
    scanf("%lf", &A);
    printf("Inserisci la lunghezza del lato B: ");
    scanf("%lf", &B);
    printf("Inserisci la lunghezza del lato C: ");
    scanf("%lf", &C);
    // Prima di verificare il tipo di triangolo, occorre verificare se i lati inseriti formano effettivamente un triangolo
    // La somma di due lati deve essere maggiore del terzo
    if ((A + B > C) && (A + C > B) && (B + C > A)){
        printf("I lati inseriti formano un triangolo\n");
        // Il triangolo equilatero è il più semplice da verificare
        // Il triangolo è isocele se due lati sono uguali e il terzo diverso
        // Il triangolo è scaleno se tutti i lati sono diversi
        if (A == B && B == C){
            printf("Il triangolo e' equilatero\n");
        } else if((A == B && B != C) || (A == C && C != B) || (B == C && C != A)){
            printf("Il triangolo e' isoscele\n");
        } else {
            printf("Il triangolo e' scaleno\n");
        }
        // Il triangolo può anche essere rettangolo
        // Il triangolo è rettangolo se il quadrato del lato più lungo è uguale alla somma dei quadrati degli altri due lati
        if (A > B && A > C){
            pitagora = B * B + C * C;
            if (A * A == pitagora){
                printf("Il triangolo e' rettangolo\n");
            }else{
                printf("Il triangolo non e' rettangolo\n");
            }
        } else if (B > A && B > C){
            pitagora = A * A + C * C;
            if (B * B == pitagora){
                printf("Il triangolo e' rettangolo\n");
            }else{
                printf("Il triangolo non e' rettangolo\n");
            }
        } else if (C > A && C > B){
            pitagora = A * A + B * B;
            if (C * C == pitagora){
                printf("Il triangolo e' rettangolo\n");
            }else{
                printf("Il triangolo non e' rettangolo\n");
            }
        }
    } else {
        printf("I lati inseriti non formano un triangolo\n");
    }
}
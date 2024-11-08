/*Uno dei procedimenti usati per stimare il valore di 𝜋 si basa sul rapporto che
esiste tra l’area di un cerchio e l’area del quadrato ad esso circoscritto. Indichiamo con Q il
quadrato definito dai punti (0,0), (1,0), (1,1), (0,1), e con C il settore circolare ottenuto
dall’intersezione del cerchio di centro (0,0) e raggio unitario con il primo quadrante.

Se indichiamo con r il raggio di C, l’area A_Q del quadrato Q è pari a r^2, mentre l’area A_C del
settore circolare C è pari a 𝜋/4 r^2 ; 
ne segue che A_C/A_Q = 𝜋/4.

Per stimare sperimentalmente il valore di 𝜋 si può quindi procedere come segue:
- si generano n punti (x, y) con 0 ≤ x ≤ 1 e 0 ≤ y ≤ 1;
- tutti i punti generati si trovano all’interno del quadrato Q, ma solo alcuni di essi si
trovano all’interno del settore circolare C;
- se il numero di punti generati è sufficientemente alto e i punti sono distribuiti
uniformemente, il numero n_Q di punti all’interno di Q è una buona stima dell’area A_Q; 
allo stesso modo il numero di punti n_C all’interno di C è una buona stima dell’area A_C.
• Ciò significa che 4 n_C / n_Q ≅ 𝜋.

Scrivere una funzione che dato il valore di n stima il valore di 𝜋 usando il procedimento
descritto e restituisce il valore 4 n_C / n_Q.

Scrivere poi un programma che utilizza la funzione scritta per stimare il valore di 𝜋 per diversi
valori di n. Più precisamente, il programma deve stimare il valore di 𝜋 per 𝑛 che assume i
valori 10, 100, 1000, 10000, 100000, 1000000, 10000000.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double stima_pi_greco(int n){
    double stima;
    int contatore_q = 0;
    int contatore_c = 0;
    srand(time(0));
    for(int i = 0; i < n; i++){
        // rand() genera un numero casuale tra 0 e RAND_MAX, se lo divido per RAND_MAX ottengo un numero tra 0 e 1
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;
        
        printf("x: %lf, y: %lf\n", x, y);
        // I punti generati cadono sempre dentro al quadrato
        contatore_q++;
        // Per controllare se il punto cada dentro al cerchio uso l'eq. del cerchio x^2 + y^2 = r^2
        if (x*x + y*y <= 1){
            contatore_c++;
        }
    }
    printf("Contatore q: %d\n", contatore_q);
    printf("Contatore c: %d\n", contatore_c);
    stima = (double)(4 * contatore_c) / (double)contatore_q;
    printf("Stima: %lf\n", stima);
    return stima;
}

int main(){
    double a = stima_pi_greco(10);
    double b = stima_pi_greco(100);
    double c = stima_pi_greco(1000);
    double d = stima_pi_greco(10000);
    // double e = stima_pi_greco(100000);
    // double f = stima_pi_greco(1000000);
    // double g = stima_pi_greco(10000000);
    printf("Il valore di pi greco e': %lf\n", M_PI);
    printf("Stime di pi greco tramite MonteCarlo:\n");
    printf("Stima con 10 punti: %lf\n", a);
    printf("Stima con 100 punti: %lf\n", b);
    printf("Stima con 1000 punti: %lf\n", c);
    printf("Stima con 10000 punti: %lf\n", d);
    // printf("Stima con 100000 punti: %lf\n", e);
    // printf("Stima con 1000000 punti: %lf\n", f);
    // printf("Stima con 10000000 punti: %lf\n", g);
}
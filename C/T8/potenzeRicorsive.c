/*
    Scrivi una funzione ricorsiva in linguaggio C che prenda in input un intero n e
    restituisca 1 (true) se n è una potenza di due. 
    Scrivi anche una funzione per l'avvio della ricorsione.
    - Ripeti l’esercizio se n è una potenza di tre.
    - Ripeti l’esercizio se n è una potenza di un numero x. 
    In questo caso il metodo ricorsivo deve prendere due parametri, n e x.
*/
#include <stdio.h>

int potenzaDiDueIterativa(int n){
    int risultato = 1;
    while(n > 1){
        if(n % 2 != 0){
            risultato = 0;
        }
        n = n / 2;
    }
    return risultato;
}

int potenzaDiDueRicorsiva(int n){
    if(n == 1){
        return 1;
    }else if(n % 2 != 0){
        return 0;
    }else{
        return potenzaDiDueRicorsiva(n / 2);
    }
}

int potenzaDiTreIterativa(int n){
    int risultato = 1;
    while(n > 1){
        if(n % 3 != 0){
            risultato = 0;
        }
        n = n / 3;
    }
    return risultato;
}

int potenzaDiTreRicorsiva(int n){
    if(n == 1){
        return 1;
    }else if(n % 3 != 0){
        return 0;
    }else{
        return potenzaDiTreRicorsiva(n / 3);
    }
}

int potenzaDiXIterativa(int n, int x){
    int risultato = 1;
    while(n > 1){
        if(n % x != 0){
            risultato = 0;
        }
        n = n / x;
    }
    return risultato;
}

int potenzaDiXRicorsiva(int n, int x){
    if(n == 1){
        return 1;
    }else if(n % x != 0){
        return 0;
    }else{
        return potenzaDiXRicorsiva(n / x, x);
    }
}

int main(){
    int n;
    printf("Inserisci un numero: ");
    scanf("%d", &n);

    int x;
    printf("Quale potenza vuoi controllare?: ");
    scanf("%d", &x);

    if(potenzaDiDueIterativa(n)){
        printf("%d e' una potenza di due\n", n);
    }else{
        printf("%d non e' una potenza di due\n", n);
    }

    if(potenzaDiDueRicorsiva(n)){
        printf("%d e' una potenza di due\n", n);
    }else{
        printf("%d non e' una potenza di due\n", n);
    }

    if(potenzaDiTreIterativa(n)){
        printf("%d e' una potenza di tre\n", n);
    }else{
        printf("%d non e' una potenza di tre\n", n);
    }

    if(potenzaDiTreRicorsiva(n)){
        printf("%d e' una potenza di tre\n", n);
    }else{
        printf("%d non e' una potenza di tre\n", n);
    }

    if(potenzaDiXIterativa(n, x)){
        printf("%d e' una potenza di %d\n", n, x);
    }else{
        printf("%d non e' una potenza di %d\n", n, x);
    }

    if(potenzaDiXRicorsiva(n, x)){
        printf("%d e' una potenza di %d\n", n, x);
    }else{
        printf("%d non e' una potenza di %d\n", n, x);
    }
    
}
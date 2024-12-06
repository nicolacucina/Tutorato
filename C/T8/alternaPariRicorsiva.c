/*
    Scrivi una funzione ricorsiva in linguaggio C che prenda in input un array di interi e
    restituisca 1 (true) se gli elementi dell'array sono alternativamente pari e dispari, cioè se ogni
    elemento pari è seguito da un dispari e viceversa.
    
    Ad esempio, se a fosse l’array {1,4,5,10,15,6}, il metodo dovrebbe restituire true.
    Scrivere anche un metodo per l’avvio della ricorsione.
*/
#include <stdio.h>

int alternaParieDispariIterativa(int n, int numeri[]){
    int trova_pari;
    if(numeri[0] % 2 == 0){
        trova_pari = 0;
    }else{
        trova_pari = 1;
    }

    int risultato = 1;
    for(int i = 1; i < n; i++){
        if(trova_pari == 1){
            if(numeri[i] % 2 != 0){
                risultato = 0;
            }
            trova_pari = 0;
        }else{
            if(numeri[i] % 2 == 0){
                risultato = 0;
            }
            trova_pari = 1;
        }
    }
    return risultato;
}

int alternaParieDispariRicorsiva(int n, int numeri[], int trovaPari, int risultato){
    // printf("n: %d, trovaPari: %d,risultato: %d\n", n, trovaPari, risultato);
    if(n == 0){
        return risultato;
    }else{
        if(trovaPari == 1){
            if(numeri[n] % 2 != 0){
                risultato = 0;
            }
            return alternaParieDispariRicorsiva(n - 1, numeri, 0, risultato);
        }else{
            if(numeri[n] % 2 == 0){
                risultato = 0;
            }
            return alternaParieDispariRicorsiva(n - 1, numeri, 1, risultato);
        }
    }
}

int avviaRicorsione(int n, int numeri[]){
    if(numeri[0] % 2 == 0){
        return alternaParieDispariRicorsiva(n - 1, numeri, 0, 1);
    }else{
        return alternaParieDispariRicorsiva(n - 1, numeri, 1, 1);
    }
}

int main(){
    int n = 6;
    int a[6] = {1,4,5,10,15,7};

    printf("%d\n", alternaParieDispariIterativa(n, a));
    printf("%d\n", avviaRicorsione(n, a));
}
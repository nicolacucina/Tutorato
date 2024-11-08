/*
Scrivere due funzioni C che ricevono come parametro un array di interi e la sua dimensione (deve essere pari). 
Nello specifico, la prima funzione deve𝑎 𝑠𝑖𝑧𝑒
restituire 1 se tutti gli elementi dell'array sono numeri pari, mentre la seconda funzione deve
restituire 1 se almeno la metà dei valori nell’array sono pari. Scrivere poi un programma che
richiede all’utente di inserire un array di interi e testa le due funzioni.
Esempio per Funzione 1.
Input 1 : [1, 2, 3, 4, 5] test = False;
Input 2 : [2, 4, 6, 8] test = True
Esempio per Funzione 2.
Input 1 : [1, 2, 3, 4] test = True; 
Array2: [1, 2, 3, 5] test = False
*/

#include <stdio.h>

void input_utente(int array[], int n){
    for(int i = 0; i < n; i++){
        printf("Inserisci il valore %d: ", i);
        scanf("%d", &array[i]);
    }
    
    printf("Array iniziale: \n"); 
    for(int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int tutti_pari(int array[], int n){
    int pari = 1;
    for(int i = 0; i < n; i++){
        if(array[i] % 2 != 0){
            pari = 0;
            break;
        }
    }
    return pari;
}

int meta_pari(int array[], int n){
    int contatore = 0;
    for(int i = 0; i < n; i++){
        if(array[i] % 2 == 0){
            contatore++;
        }
    }
    if(contatore >= n/2){
        return 1;
    } else {
        return 0;
    }
}

int main(){
    int n;
    printf("Inserisci la dimensione dell'array: ");
    scanf("%d", &n);
    
    if (n % 2 != 0){
        printf("La dimensione dell'array deve essere pari\n");
        return 1;
    } else{
        int input_array[n];
        input_utente(input_array, n);

        if(tutti_pari(input_array, n)){
            printf("Tutti i numeri sono pari\n");
        } else {
            printf("Non tutti i numeri sono pari\n");
        }

        if(meta_pari(input_array, n)){
            printf("Almeno la meta' dei numeri sono pari\n");
        } else {
            printf("Meno della meta' dei numeri sono pari\n");
        }
    }
}
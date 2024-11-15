/*
Scrivere due funzioni C che ricevono come parametro un array di interi a e la sua dimensione size(deve essere pari). 
Nello specifico, la prima funzione deve restituire 1 se tutti gli elementi dell'array sono numeri pari, 
mentre la seconda funzione deve restituire 1 se almeno la metà dei valori nell’array sono pari. 
Scrivere poi un programma che richiede all’utente di inserire un array di interi e testa le due funzioni.
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
    // Dato che basta un singolo valore dispari affinchè l'array non contenga solo numeri pari,
    // cerco un singolo valore dispari e se lo trovo mi fermo.
    // Se trovo solo valori pari, la variabile "pari" rimane 1 e restituisco 1.
    // Se incontro un valore dispari, la variabile "pari" diventa 0, il ciclo si interrompe e restituisco 0.
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
    // In questo caso, per sapere se almeno la metà dei valori dell'array sono pari, prima devo scorrete tutto l'array
    // e contare quanti valori pari ci sono, poi potrò fare un confronto e decidere se restituire 1 oppure 0.
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
        // L'input dell'utente viene inserito all'interno di una funzione per organizzare il codice e renderlo più leggibile

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
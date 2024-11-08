/*
Scrivere un programma C che riceve dall'utente un array di interi e la sua dimensione. 
Il programma deve visualizzare un sottoinsieme dei numeri dell'array secondo le seguenti regole:
- ogni numero che compare ripetuto nell'array non deve essere stampato
- ogni numero uguale a zero presente nell’array non deve essere stampato.
Esempio | Input = [1, 18, 3, 0, 24, 3, 6, 0] | Output = [1, 18, 3, 24, 6]
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

int controlla_ripetizioni(int array[], int n, int numero){
    int contatore = 0;
    for(int i = 0; i < n; i++){
        if(array[i] == numero){
            contatore = 1;
            break;
        }
    }
    return contatore;
}

void print_risultato(int array[], int n){
    printf("Array finale: \n");
    for(int i = 0; i < n; i++){
        if(array[i] !=0){
            printf("%d ", array[i]);
        }
    }
}

int main(){
    int n;
    printf("Inserisci la dimensione dell'array: ");
    scanf("%d", &n);
    
    int input_array[n];
    input_utente(input_array, n);

    // Inizializzazione soluzione
    int array_finale[n];
    for (int i = 0; i < n; i++){
        array_finale[i] = 0;
    }
    
    int indice = 0;
    for (int i = 0; i < n; i++){
        if(input_array[i] != 0 && (controlla_ripetizioni(array_finale, n, input_array[i]) == 0)){
            array_finale[indice] = input_array[i];
            indice++;
        }
    }

    print_risultato(array_finale, n);
}
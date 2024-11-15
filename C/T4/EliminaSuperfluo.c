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
    /*
    La funzione controlla se un numero è già presente all'interno dell'array
    Se il numero è presente, all'interno del ciclo for la condizione array[i] == numero sarà vera almeno una volta,
    cambiando il valore di contatore ad 1.
    Se il numero non è presente, il valore di contatore rimarrà 0.
    */
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

    // Gestisco l'input dell'utente in una funzione a parte
    input_utente(input_array, n);

    /*
    Inizializzazione della soluzione, sapendo che la dimensione dell'array finale sarà minore o uguale 
    a quella dell'array di input, posso utilizzare la dimensione n come dimensione dell'array finale.
    Inizializzo tutti gli elementi dell'array finale a 0, in modo da poterli scartare successivamente.
    */
    int array_finale[n];
    for (int i = 0; i < n; i++){
        array_finale[i] = 0;
    }
    
    for (int i = 0; i < n; i++){
        /*
        Abbiamo scritto una funzione controlla_ripetizioni che ci permette di verificare se un numero è già presente
        all'interno dell'array finale. 
        Andremo a copiare ogni elemento dell'array di input all'interno dell'array finale.
        Se provassimo ad inserire un valore che è già stato copiato in precendenza, la funzione controlla_ripetizioni
        restituirebbe 1 e l'elemento deve essere scartato.
        Considerando l'esempio fornito [1, 18, 3, 0, 24, 3, 6, 0]
        - 1 non è presente nell'array finale, quindi viene copiato,
        - 18 non è presente nell'array finale, quindi viene copiato,
        - il primo 3 non è presente nell'array finale, quindi viene copiato,
        - 0 viene scartato,
        - 24 non è presente nell'array finale, quindi viene copiato,
        - il secondo 3 è già presente nell'array finale perchè inserito sopra, quindi viene scartato
        ...
        */

        if(input_array[i] != 0 && (controlla_ripetizioni(array_finale, n, input_array[i]) == 0)){
            array_finale[i] = input_array[i];
        }
    }

    print_risultato(array_finale, n);
}
/*
    Scrivere un programma che fa inserire all’utente una sequenza di interi, 
    la cui lunghezza può essere chiesta all’utente prima dell’inserimento, 
    e dice all’utente se gli elementi della sequenza sono tutti distinti.
*/

#include <stdio.h>

int controllo_distinti(int arr[], int n){
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] == arr[j]){
                printf("Gli elementi della sequenza non sono tutti distinti.\n");
                return 0;
            }
        }
    }
    printf("Gli elementi della sequenza sono tutti distinti.\n");
    return 1;
}

int main(){
    int n;
    printf("Inserisci la lunghezza della sequenza: ");
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++){
        printf("Inserisci il %d numero: ", i+1);
        scanf("%d", &arr[i]);
    }

    int distinti = controllo_distinti(arr, n);
}
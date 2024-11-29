#include <stdio.h>

int conta_zeri_ricorsivo(int array[], int n){
    if(n == 0){
        return 0;
    }else{       
        return (array[n-1] == 0) || (conta_zeri_ricorsivo(array, n-1));
    }
    
}

int main(){
    int n;
    printf("Inserisci un numero: ");
    scanf("%d", &n);

    int array[n];
    for(int i = 0; i < n; i++){
        printf("Inserisci il numero %d: ", i+1);
        scanf("%d", &array[i]);
    }

    int zeri = conta_zeri_ricorsivo(array, n);
    if(zeri == 0){
        printf("Non ci sono zeri\n");
    }else{
        printf("C'e' almeno uno zero\n");
    }
}
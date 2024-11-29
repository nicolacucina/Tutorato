/*
    Un seam verticale di una matrice consiste di un insieme di celle della matrice tali che: 
    - ogni riga contiene una sola cella; 
    - celle su righe consecutive occupano la stessa colonna o colonne consecutive. 
         
    Scrivere una funzione che riceve in ingresso una matrice di interi di dimensione n x m, 
    le sue dimensioni e un array di interi seam di dimensione n che rappresenta un seam e
    restituisce  il  valore  del  seam,  cioè  la somma degli elementi che lo compongono.

    L'array seam è strutturato nel seguente modo: 
    - la cella seam[0] contiene l'indice dell'elemento del seam sulla prima riga; 
    - l'elemento seam[i] contiene un valore nell’insieme {-1,0,1};
    seam[i] sarà uguale a:
    - 0 se l’elemento del seam sulla riga i si trova sulla stesa colonna dell'elemento sulla riga i-1,
    - -1 se l’elemento sulla riga i si trova sulla colonna precedente la colonna dell’elemento della riga i-1, 
    - 1 se l’elemento sulla riga i si trova sulla colonna successivo alla colonna dell’elemento della riga i-1.
     
    Ad esempio, il seam della figura precedente sarebbe rappresentato dal seguente array {3,0,1,1,-1,1,0,0,1}.

    Dopo aver scritto la funzione, scrivere un main che permetta di testarla. 
    A tale scopo è sufficiente definire la matrice e l’array seam tramite letterali array
*/

#include <stdio.h>

int somma_seam(int n, int m, int matrice[n][m], int seam[]){
    int somma = 0;
    int colonna = seam[0];
    for(int i = 0; i<n; i++){
        somma += matrice[i][colonna];
        colonna += seam[i+1];
    }
    return somma;
}

int main(){
    int n = 9;
    int m = 9;
    int matrice[9][9] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {1, 2, 3, 4, 5, 6, 7, 8, 9}
    };
    // 4, 4, 5, 6, 5, 6, 6, 6, 7
    int seam[9] = {3, 0, 1, 1, -1, 1, 0, 0, 1};
                
    int risultato = somma_seam(n, m, matrice, seam);
    printf("Risultato: %d\n", risultato);
}
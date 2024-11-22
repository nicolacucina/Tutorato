/*
    Si supponga di aver definito una struttura tempo i cui campi sono ore, minuti e secondi tutti di tipo int.

    Scrivere una funzione convertiTempo di tipo void che riceve in ingresso
    - un array di int a i cui elementi rappresentano intervalli di tempo espressi in secondi;
    - un array b di tipo tempo della stessa dimensione di a;
    - la dimensione n_a di a e b.
    La funzione scrive nell’elemento b[i] l’intervallo a[i] espresso in ore, minuti e secondi. 
    Ad esempio, la funzione dovrebbe restituire:
    (a)                 (b) 
    3600            ore: 1, minuti: 0, secondi: 0
    176             ore: 0, minuti: 2, secondi: 56
    3723            ore: 1, minuti: 2, secondi: 3
    180             ore: 0, minuti: 3, secondi: 0

    Dopo aver scritto la funzione, scrivere un main che permetta di testarla. 
    A tale scopo è sufficiente definire gli array necessari tramite letterali array
*/

#include <stdio.h>
#include <stdlib.h>

struct tempo{
    int ore;
    int minuti;
    int secondi;
};

void convertiTempo(int *a, struct tempo *b, int n_a){
    for(int i = 0; i < n_a; i++){
        b[i].ore = a[i] / 3600;
        b[i].minuti = (a[i] % 3600) / 60;
        b[i].secondi = a[i] % 60;
    }
}

int main(){
    int a[] = {3600, 176, 3723, 180};
    struct tempo b[4];
    convertiTempo(a, b, 4);
    for(int i = 0; i < 4; i++){
        printf("Intervallo: %d -> ore: %d, minuti: %d, secondi: %d\n", a[i], b[i].ore, b[i].minuti, b[i].secondi);
    }
}
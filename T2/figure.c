// Scrivere un programma C per disegnare ciascuna delle figure riportate di seguito:
// * * * * *        - + + + +
// *       *        - - + + +
// *       *        - - - + +
// *       *        - - - - +
// * * * * *        - - - - -
#include <stdio.h>

int main(){
    printf("Approccio Non-Iterativo\n");
    printf("* * * * *\n");
    printf("*       *\n");
    printf("*       *\n");
    printf("*       *\n");
    printf("* * * * *\n");
    
    int numRighe = 5;
    int numColonne = 5;
    printf("Approccio Iterativo\n");
    int i, j; // i rappresenta le righe, j rappresenta le colonne
    for (i = 0; i < numRighe; i++){
        // Ogni riga può essere stampata in due modi: * * * * * oppure *       *
        // La prima e l'ultima riga sono sempre * * * * *
        if(i == 0 || i == 4){
            for (j = 0; j < numColonne; j++){
                printf("* ");
            }
        } else {
            // Le righe intermedie devono stampare un * nella prima e nell'ultima colonna
            for (j = 0; j < numColonne; j++){
                if (j == 0 || j == 4){
                    printf("* ");
                } else {
                    printf("  ");
                }
            }
        }
        printf("\n");
    }

    printf("Approccio Non-Iterativo\n");
    printf("- + + + +\n");
    printf("- - + + +\n");
    printf("- - - + +\n");
    printf("- - - - +\n");
    printf("- - - - -\n");

    printf("Approccio Iterativo\n");
    // Ogni riga viene stampata diversamente ma possiamo vedere che:
    // 1° riga: 1 segno - e 4 segni +
    // 2° riga: 2 segni - e 3 segni +
    // 3° riga: 3 segni - e 2 segni +
    // 4° riga: 4 segni - e 1 segno +
    // 5° riga: 5 segni -
    // Il numero di segni - è sempre uguale al numero di riga
    // Il numero di segni + è sempre uguale a 5 - numero di riga
    for (i = 0; i < numRighe; i++){
        for (j = 0; j < numColonne; j++){
            if (j <= i){
                printf("- ");
            } else {
                printf("+ ");
            }
        }
        printf("\n");
    }
}
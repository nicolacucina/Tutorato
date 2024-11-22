/*
    Scriviamo un programma in C che crea un file di testo di nome “student_card.txt” e 
    inserisce gli esami svolti.
    
    La struttura del record per l’ esame è la seguente:
        exam_code exam_name exam_credits grade date
    
    Il file di testo così generato sarà del tipo:
        Exam code: 0
        Exam name: Fondamenti
        Exam credits: 9
        Exam grade: 29
        Exam date: 12/20/2023

    Il programma, chiamato student_card_writer.c, 
    dovrà automaticamente inserire e aggiornare il codice dell’esame per ogni nuovo esame inserito 
    e chiedere all’utente di popolare i diversi campi riportati in precedenza. 
    All’utente, viene anche richiesto iterativamente di inserire nuovi esami tramite una domanda da terminale
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct exam {
    int exam_code;
    char exam_name[30];
    int exam_credits;
    int grade;
    char date[11];
};

int main(){
    FILE *f = fopen("student_card.txt", "a");
    if (f == NULL) {
        printf("Errore nell'apertura del file\n");
        return 1;
    }
    int continua = 1;
    while(continua == 1){
        struct exam e;
        
        // Input
        printf("Inserisci il codice dell'esame: ");
        scanf("%d", &e.exam_code);
        printf("Inserisci il nome dell'esame: ");
        scanf("%s", e.exam_name);
        printf("Inserisci i crediti dell'esame: ");
        scanf("%d", &e.exam_credits);
        printf("Inserisci il voto dell'esame: ");
        scanf("%d", &e.grade);
        printf("Inserisci la data dell'esame (gg/mm/aaaa): ");
        scanf("%s", e.date);

        // Terminale
        printf("Exam code: %d\n", e.exam_code);
        printf("Exam name: %s\n", e.exam_name);
        printf("Exam credits: %d\n", e.exam_credits);
        printf("Exam grade: %d\n", e.grade);
        printf("Exam date: %s\n", e.date);

        // File
        fprintf(f, "Exam code: %d\n", e.exam_code);
        fprintf(f, "Exam name: %s\n", e.exam_name);
        fprintf(f, "Exam credits: %d\n", e.exam_credits);
        fprintf(f, "Exam grade: %d\n", e.grade);
        fprintf(f, "Exam date: %s\n", e.date);
            
        printf("Vuoi inserire un nuovo esame? (1 = si, 0 = no): ");
        scanf("%d", &continua);
    }

    fclose(f);
}
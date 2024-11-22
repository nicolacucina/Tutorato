
/*
    Scriviamo ora un programma C che legge il file precedentemente creato di nome “student_card.txt”. 
    Questo programma, oltre a leggere i file attualmente inseriti all’interno del libretto, 
    deve restituire la media delle valutazioni.
    
    Bonus:
    - Scrivere una funzione per calcolare la media ponderata.
    - Scrivere una funzione per calcolare il mese con le valutazioni più alte
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

double media(struct exam *exams, int n){
    int somma = 0;
    for(int i = 0; i < n; i++){
        somma += exams[i].grade;
    }
    return (double)somma / n;
}

double media_ponderata(struct exam *exams, int n){
    int somma = 0;
    int crediti = 0;
    for(int i = 0; i < n; i++){
        somma += exams[i].grade * exams[i].exam_credits;
        crediti += exams[i].exam_credits;
    }
    return (double)somma / crediti;
}

int main(){
    FILE *f = fopen("student_card.txt", "r");
    if (f == NULL) {
        printf("Errore nell'apertura del file\n");
        return 1;
    }
    struct exam exams[100];
    int index = 0;
    /*
        fscanf legge dal file stringhe di testo formattate. Questo è importante perchè ci contente di leggere
        non solo testo ma anche numeri e altri tipi di dati sfruttando i formati dei dati %d, %s, %f, ecc.

        Avendo creato noi la codifica/formattazione del file, sappiamo che ogni esame è composto da 5 righe
        e quindi possiamo leggere i dati in modo sequenziale.

    */
    while(fscanf(f, "Exam code: %d\n", &exams[index].exam_code) != EOF){
        fscanf(f, "Exam name: %s\n", exams[index].exam_name);
        fscanf(f, "Exam credits: %d\n", &exams[index].exam_credits);
        fscanf(f, "Exam grade: %d\n", &exams[index].grade);
        fscanf(f, "Exam date: %s\n", exams[index].date);
        index++;
    }
    fclose(f);
    
    for(int i = 0; i < index; i++){
        printf("Exam code: %d\n", exams[i].exam_code);
        printf("Exam name: %s\n", exams[i].exam_name);
        printf("Exam credits: %d\n", exams[i].exam_credits);
        printf("Exam grade: %d\n", exams[i].grade);
        printf("Exam date: %s\n", exams[i].date);
    }
    
    double media_norm = media(exams, index);
    printf("La media delle valutazioni e': %.2g\n", media_norm);

    double media_pond = media_ponderata(exams, index);
    printf("La media delle valutazioni e': %.2g\n", media_pond);
    
    return 0;
}
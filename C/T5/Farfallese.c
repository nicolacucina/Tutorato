/*
Scrivere una funzione con il seguente prototipo:
void farfallese(char *s1, char *s2, int length_s1);
La funzione riceve in ingresso due stringhe s1 e s2 e la lunghezza della stringa s1; modifica s2 nel
seguente modo:
- inserisce una f dopo ogni vocale minuscola
- inserisce una F dopo ogni vocale maiuscola.
Se la frase fosse, per esempio, "NoN mi pIAcciONo gLi AqUilONi" la funzione dovrebbe
modificare s2 in modo da ottenere "NofN mif pIFAFccifOFNof gLiF AFqUFiflOFNif". Scrivere
un programma che utilizza la funzione scritta
*/

#include <stdio.h>
#include <string.h>

void inserisci_stringa(char *s1, int n){
    printf("Inserisci la stringa: \n");

    fgets(s1, n, stdin);
    int len = strlen(s1);
    if(s1[len-1] == '\n'){
        s1[len-1] = '\0';
    }
}

int is_vocale(char c){
    char vocali[] = "aeiou";
    char vocali_maiuscole[] = "AEIOU";
    int risultato = 0;
    for(int i = 0; vocali[i] != '\0'; i++){
        if(c == vocali[i]){
            risultato = 1;
        }
    }
    for(int i = 0; vocali_maiuscole[i] != '\0'; i++){
        if(c == vocali_maiuscole[i]){
            risultato = 2;
        }
    }
    return risultato;
}

char* farfallese(char *s1, char *s2, int length_s1){
    int index = 0;
    for(int i = 0; i < length_s1; i++){
        int vocali = is_vocale(s1[i]);
        s2[index] = s1[i];
        index++;
        if(vocali == 1){
            s2[index] = 'f';
            index++;
        } else if(vocali == 2){
            s2[index] = 'F';
            index++;
        }
    }
    s2[index] = '\0';
    return s2;
}

int main(){
    int n = 100;
    char s1[n], s2[n];
    
    inserisci_stringa(s1, n);
    
    char *risultato;
    risultato = farfallese(s1, s2, strlen(s1));
    printf("Risultato: %s\n", risultato);
}
import fond.io.InputWindow;
import fond.io.OutputWindow;

public class Spazi {

    public static boolean isVocale(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    public static void main(String[] args) {
        /*
         * Esercizio 1.  
         * Scrivere un programma Java chiamato Spazi che chiede all’utente di inserire una stringa e 
         * stampa il numero di spazi che sono seguiti da una vocale. Per esempio, se si immette 
         * “Ciao, imparo a programmare in Java!” il programma deve stampa 3
         */
        InputWindow in = new InputWindow();
        OutputWindow out = new OutputWindow();

        String frase = in.readString("Inserisci una frase");
        int count = 0;
        for(int i = 0; i < frase.length(); i++) {
            if(frase.charAt(i) == ' ' && isVocale(frase.charAt(i+1))) {
            /* if(frase.charAt(i) == ' ' && 
                (frase.charAt(i+1) == 'a' || frase.charAt(i+1) == 'e' || 
                frase.charAt(i+1) == 'i' || frase.charAt(i+1) == 'o' || 
                frase.charAt(i+1) == 'u' || frase.charAt(i+1) == 'A' || 
                frase.charAt(i+1) == 'E' || frase.charAt(i+1) == 'I' || 
                frase.charAt(i+1) == 'O' || frase.charAt(i+1) == 'U')) {*/
                count += 1;
            }
        }

        out.writeln(count);
    }
}
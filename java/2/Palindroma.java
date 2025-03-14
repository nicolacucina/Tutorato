import fond.io.InputWindow;
import fond.io.OutputWindow;

public class Palindroma {
    public static void main(String[] args) {
        /*
         * Scrivere un programma Java chiamato Palindroma che fa inserire all’utente una stringa 
         * priva di spazi e stampa true se la stringa inserita è palindroma, false altrimenti. Esempi di 
         * alcune stringhe palindrome sono "anna", “ottetto”, "itopinonavevanonipoti"
         */
        InputWindow in = new InputWindow();
        OutputWindow out = new OutputWindow();

        String frase = in.readString("Inserisci una frase");
        boolean palindroma = true;
        for(int i=0; i<frase.length(); i++){
            if(frase.charAt(i) != frase.charAt(frase.length()-1-i)){
                palindroma = false;
                break;
            }
        }

        out.writeln(palindroma);
    }
}

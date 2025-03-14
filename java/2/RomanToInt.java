import fond.io.InputWindow;
import fond.io.OutputWindow;

public class RomanToInt {
    public static int convertiCifra(char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
    public static void main(String[] args) {
        /*
         * Scrivere un programma Java chiamato romanToInt che esegue la traduzione da numeri romani a numeri interi.
         * Nello specifico i numeri romani possono essere trasformati secondo la seguente tabella: 
         * Simbolo Valore 
         * I 1 
         * V 5 
         * X 10 
         * L 50 
         * C 100 
         * D 500 
         * M 1000
         * 
         * Per esempio: il numero II indica il numero 2, il numero XV indica il numero 15 e così via. 
         * Le cose si fanno leggermente più complicate per numeri come il IV = 4, il CL = 40 e simili. 
         * Per la traduzione, leggiamo il numero romano da destra verso sinistra e ci salviamo la cifra appena letta
         * secondo questo criterio: 
         * - Se tale cifra è almeno 4 volte più piccola della somma delle cifre già lette, 
         * allora la sottraiamo a tale somma; 
         * - Altrimenti la sommiamo alle altre. 
         * 
         * Esempio dell’algoritmo: consideriamo XIV = 14. Iniziamo dall’ultima cifra V = 5. 
         * Non potendo confrontarla con altre, farà somma a sé stante. 
         * La cifra seguente è I=1. Questa cifra moltiplicata per 4 è inferiore a 5 
         * (ovvero 4*1 < 5): siamo nel primo caso e sottraiamo quindi 1 a 5 ottenendo 4. Infine abbiamo X = 10. 
         * Questa cifra moltiplicata per 4 è maggiore della somma delle precedenti ( 10*4 > 4). 
         * Quindi la sommiamo ottenendo 14. 
         * 
         * Provare ora il codice scritto per i seguenti valori di Input, 
         * in modo da ottenere i relativi valori di Output: 
         * Input: III    Input: XLII  
         * Output: 3     Output: 42 
         * 
         * Input: CXLIV    Input: MCMXCIX 
         * Output: 144    Output: 1999 
         */
        InputWindow in = new InputWindow();
        OutputWindow out = new OutputWindow();

        String numeroRomano = in.readString("Inserisci un numero romano");
        int somma = 0;
        for(int i = numeroRomano.length()-1; i >= 0; i--){
            int cifra = convertiCifra(numeroRomano.charAt(i));
            /* 
            if (numeroRomano.charAt(i) == 'I') {
                cifra = 1;
            } else if (numeroRomano.charAt(i) == 'V') {
                cifra = 5;
            } else if (numeroRomano.charAt(i) == 'X') {
                cifra = 10;
            } else if (numeroRomano.charAt(i) == 'L') {
                cifra = 50;
            } else if (numeroRomano.charAt(i) == 'C') {
                cifra = 100;
            } else if (numeroRomano.charAt(i) == 'D') {
                cifra = 500;
            } else if (numeroRomano.charAt(i) == 'M') {
                cifra = 1000;
            }
            */
            if(4*cifra < somma){
                somma -= cifra;
            } else {
                somma += cifra;
            }
        }

        out.writeln(somma);
    }
}

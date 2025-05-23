package esami.B;

import java.util.ArrayList;

public class InsiemeDiParole {
    private String[] parole;  
 
    /* Crea un oggetto InsiemeDiParole il cui contenuto è rappresentato dall’array parole  */ 
    public InsiemeDiParole (String[] parole){
        this.parole = new String[parole.length];
        for(int i = 0; i< parole.length; i++){
            this.parole[i] = parole[i];
        }
    }

    /* Restituisce un array di interi di dimensione pari a this.parole.length. L’elemento i-esimo della 
    array risultato è pari al numero di lettere doppie presenti nella parola parola[i]. Per lettera doppia si 
    intende una coppia di lettere consecutive uguali. Una coppia di lettere uguali di cui una maiuscola e 
    una minuscola costituiscono una doppia. Si assuma che i caratteri che costituiscono le stringhe 
    dell’array parole siano soltanto lettere (maiuscole o minuscole).  */ 
    public int[] contaDoppiePerParola(){
        int[] result = new int[this.parole.length];

        for(int i = 0; i < this.parole.length; i++){
            char a = this.parole[i].charAt(0);
            for(int j = 1; j < this.parole[i].length(); j++){
                char b = this.parole[i].charAt(j);
                if(Character.isUpperCase(a)){
                    if(Character.isUpperCase(b)){
                        if (a == b){
                            result[i] ++;
                        }
                    }else{
                        if(a == (b -32)){
                            result[i] ++;
                        }
                    }
                }else{
                    if(Character.isLowerCase(b)){
                        if (a == b){
                            result[i] ++;
                        }
                    }else{
                        if(a == (b + 32)){
                            result[i] ++;
                        }
                    }
                }
                a = b;
            }
        }
        return result;
    }

    /* Restituisce un oggetto di tipo InsiemeDiParole il cui insieme di parole è ottenuto da quello 
    dell’oggetto ricevente (this) eliminando le parole con meno di k caratteri.*/ 
    public InsiemeDiParole rimuoviParoleCorte(int k){
        ArrayList<String> temp = new ArrayList<String>();
        for(int i = 0; i < this.parole.length; i++){
            if(this.parole[i].length() >= k){
                temp.add(this.parole[i]);
            }
        }

        String[] result = new String[temp.size()];
        int counter = 0;
        for(String s: temp){
            result[counter] = s;
            counter++;
        }
        return new InsiemeDiParole(result);
    }

    public String toString(){
        String s = "";
        for(int i = 0; i<this.parole.length; i++){
            s += this.parole[i] + "\n";
        }
        return s;
    }
}

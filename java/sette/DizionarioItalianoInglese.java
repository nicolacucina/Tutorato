package sette;
import java.util.HashMap;

public class DizionarioItalianoInglese implements Dizionario{

    private HashMap<String, String[]> dizionario;

    public DizionarioItalianoInglese(){
        this.dizionario = new HashMap<String, String[]>();
    }

    public void aggiungiParola(String parolaItaliana, String[] paroleInglesi){
        dizionario.put(parolaItaliana, paroleInglesi); // sovrascrive
    }

    public String[] traduciParola(String s){
        return dizionario.get(s);
    }

    public void rimuoviParola(String s){
        dizionario.remove(s); 
    }

}

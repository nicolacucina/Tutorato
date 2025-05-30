package esami.g;

import java.util.List;
import java.util.Map;
import java.util.HashMap;
import java.util.ArrayList;

public class PrenotazionePosti {
    /* mappa che memorizza i posti disponibili. La chiave è la lettera 
    che identifica la fila, il valore è una lista che contiene tutti i 
    posti di una fila; il Posto in posizione i-esima nella lista 
    corrisponde al posto in posizione i-esima nella fila. */      
    
    private Map<Character,List<Posto>> platea;  
    
    /* Costruisce una un oggetto i cui posti occupano file dalla A alla 
    M e numeri da 0 a 20. I posti sono inizialmente tutti liberi e il 
    prezzo è pari a 200 per la prima fila e diminuisce di 10 ad ogni 
    fila successiva. */  
    public PrenotazionePosti(){
        int costo = 200;
        this.platea = new HashMap<Character, List<Posto>>();
        for(int i = 'A';  i <= 'M'; i++){
            System.out.println(i);
            List<Posto> l = new ArrayList<Posto>();
            for(int j = 0; j <= 20; j++){
                l.add(new Posto((char)i, j, costo, true));
            }
            costo -= 10;
        }
    } 
        
    /* Cerca num posti consecutivi nella fila fila e li prenota, 
    restituendo una lista contenente i posti prenotati. Se non ci sono 
    num posti consecutivi nella fila fila, viene restituito null.  */ 
    public List<Posto> prenotaPostiInFila(char fila, int num){
        int counter = 0;
        int start_index = -1;
        List<Posto> filaScelta = this.platea.get(fila);
        for(Posto pp: filaScelta){
            System.out.println(pp);
        }
        System.out.println("null");

        for(int i = 0;  i < filaScelta.size(); i++){
            Posto q = filaScelta.get(i);
            if(q.isLibero()){
                counter++;
                start_index = i;
            }else{
                counter = 0;
                start_index = -1;
            }
        }
        if(counter >= num){
            List<Posto> result = new ArrayList<Posto>();
            for(int i = start_index; i <= i + num; i++){
                Posto q = filaScelta.get(i);
                q.setLibero(false);
                result.add(q);
            }
            return result;
        }
        return null;
    } 
    
    /* Cerca num posti consecutivi in una fila qualsiasi e li prenota, 
    restituendo una lista contenente i posti prenotati. Se non ci sono 
    num posti consecutivi, viene restituito null. */ 
    public List<Posto> prenotaPostiInFila(int num){
        return null;
    } 
    
    /* Restituisce una descrizione testuale dei posti. I posti vengono 
    mostrati organizzati per file e per ogni posto viene mostrata la 
    lettera e il numero che lo identifica, il costo e lo stato (libero 
    o occupato); per visualizzare le informazioni di un posto è 
    sufficiente utilizzare il metodo toString della classe Posto */ 
    public String toString(){
        return null;
    }
}

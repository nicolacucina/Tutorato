package esami.d;

import java.util.ArrayList;
import java.util.List;

public class ContoCorrente {
    /* Nome e cognome dell’intestatario del conto. */      
    private String nome, cognome; 
    /* Lista delle operazioni registrate sul conto corrente. */      
    private List<Operazione> operazioni;  
    
    /* Costruisce un oggetto ContoCorrente intestato alla persona il 
    cui nome e cognome sono (nome,cognome) e la cui lista di operazioni 
    è vuota. */  
    public ContoCorrente(String nome, String cognome){
        this.nome = nome;
        this.cognome = cognome;
        this.operazioni = new ArrayList<Operazione>();
    } 
        
    /* Aggiunge l’operazione op alla lista delle operazioni.  */ 
    private void aggiungiOperazione(Operazione op){
        this.operazioni.add(op);
    } 
    
    /* restituisce la lista di tutte le operazioni registrate sul conto 
    che sono di tipo tipo. */ 
    private List<Operazione> filtraPerTipo(String tipo){
        List<Operazione> result = new ArrayList<Operazione>();
        for(Operazione op : this.operazioni){
            if(op.getTipo().equals(tipo)){
                result.add(op);
            }
        }

        return result;
    } 
    
    /* Calcola il saldo del conto */ 
    public double calcolaSaldo(){
        double result = 0.0;
        for(Operazione op: this.operazioni){
            result += op.getAmmontare();
        }

        return result;
    }
    
}

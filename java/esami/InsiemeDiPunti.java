package esami.f;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class InsiemeDiPunti {
    private Set<Punto> punti;

    /* Costruisce un insieme di punti vuoto */
    public InsiemeDiPunti (){
        this.punti = new HashSet<Punto>();
    }

    /* Aggiunge il punto p all’insieme rappresentato dall’oggetto ricevente */
    public void aggiungi(Punto p){
        this.punti.add(p);
    }
    
    /* Restituisce l’insieme delle rette passanti per ogni coppia di punti che appartengono all’insieme
    rappresentato dall’oggetto ricevente. */
    public Set<Retta> rettePassanti(){
        Set<Retta> result = new HashSet<Retta>();
        for(Punto p: this.punti){
            for(Punto q: this.punti){
                if (p == q) {
                    continue;
                }

                result.add(new Retta(p, q));
            }
        }
        return result;
    }

    /* Restituisce un array di rette di dimensione 4 che restituisce le quattro rette parallele agli assi x e y
    che formano il rettangolo più piccolo che racchiude tutti i punti dell’insieme. Se l’insieme è vuoto e
    quindi non ci sono punti, il metodo restituisce null */
    public Retta[] rettangoloIncludente(){
        Punto[] puntiEstremi = new Punto[4];        
        Iterator<Punto> e = punti.iterator();
        if(punti.size() == 0){
            return null;
        }

        if(e.hasNext()){
            Punto p = e.next();
            puntiEstremi[0] = puntiEstremi[1] = p;
            puntiEstremi[2] = puntiEstremi[3] = p;
        }
        
        while (e.hasNext()) {
            Punto p = e.next();
            if(p.coordX() < puntiEstremi[0].coordX()){
                puntiEstremi[0] = p;
            }
            if(p.coordX() > puntiEstremi[1].coordX()){
                puntiEstremi[1] = p;
            }
            if(p.coordY() < puntiEstremi[2].coordX()){
                puntiEstremi[2] = p;
            }
            if(p.coordY() < puntiEstremi[3].coordX()){
                puntiEstremi[3] = p;
            }
        }
    
        Retta[] result = new Retta[4];
        result[0] = new Retta(puntiEstremi[0], puntiEstremi[2]);
        result[1] = new Retta(puntiEstremi[0], puntiEstremi[3]);
        result[2] = new Retta(puntiEstremi[1], puntiEstremi[2]);
        result[3] = new Retta(puntiEstremi[1], puntiEstremi[3]);
        return result;
        
    }
    /* Restituisce una rappresentazione testuale dell’insieme di punti rappresentato dall’oggetto
    ricevente*/
    public String toString(){
        String s = "";
        int counter = 0;
        for(Punto p : punti){
            s += "Punto "+ counter + " x: " + p.coordX() + ", y: " + p.coordY();
        }
        return s;
    }
}

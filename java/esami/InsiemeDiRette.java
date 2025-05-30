package esami.f;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class InsiemeDiRette {

    private Set<Retta> rette;
    
    /* Costruisce un insieme di rette vuoto */
    public InsiemeDiRette (){
        this.rette = new HashSet<Retta>();
    }

    /* Aggiunge la retta r all’insieme rappresentato dall’oggetto ricevente */
    public void aggiungi(Retta r){
        this.rette.add(r);
    }
    
    /* Restituisce l’insieme dei punti di intersezione delle rette che appartengono all’insieme
    rappresentato dall’oggetto ricevente. */
    public Set<Punto> puntiDiIntersezione(){
        Set<Punto> result = new HashSet<Punto>();
        for(Retta r : rette){
            // System.out.println(r);
            for(Retta s: rette){
                // System.out.println(s);
                if(r == s){
                    // System.out.println("skip");
                    continue;
                }

                result.add(r.intersezione(s));
            }
        }
        // for(Punto p : result){
        //     System.out.println(p);
        // }
        return result;
    }

    /* Restituisce un array di punti di dimensione 4 che restituisce i punti estremi dell’insieme di punti di
    intersezione delle rette che appartengono all’insieme rappresentato dall’oggetto ricevente. Più
    precisamente, gli elementi di indice 0 e 1 rappresentano i punti con coordinata x minima e massima,
    rispettivamente; gli elementi di indice 2 e 3 rappresentano i punti con coordinata y minima e
    massima, rispettivamente. Se l’insieme è vuoto e quindi non ci sono punti di intersezione, il metodo
    restituisce null */
    public Punto[] puntiEstremi(){
        Punto[] result = new Punto[4];
        Set<Punto> punti = this.puntiDiIntersezione();
        Iterator<Punto> e = punti.iterator();
        if(punti.size() == 0){
            return null;
        }

        if(e.hasNext()){
            Punto p = e.next();
            result[0] = result[1] = p;
            result[2] = result[3] = p;
        }
        
        while (e.hasNext()) {
            Punto p = e.next();
            if(p.coordX() < result[0].coordX()){
                result[0] = p;
            }
            if(p.coordX() > result[1].coordX()){
                result[1] = p;
            }
            if(p.coordY() < result[2].coordX()){
                result[2] = p;
            }
            if(p.coordY() < result[3].coordX()){
                result[3] = p;
            }
        }

        return result;
    }

    public String toString(){
        String s = "";
        int counter = 0;
        for(Retta r : this.rette){
            s += "Retta " + counter + " m: " + r.getM() + ", q: " + r.getQ();
            counter++;
        }
        return s;
    }
}
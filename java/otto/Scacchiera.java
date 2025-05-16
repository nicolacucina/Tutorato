package otto;

import java.util.ArrayList;
import java.util.Iterator;

public class Scacchiera {

    public final static int DIM_SCACCHIERA = 8; 
    private Pezzo[][] scacchiera; 
 
    /* crea una scacchiera vuota, cioè senza pezzi. */ 
    public Scacchiera(){
        this.scacchiera = new Pezzo[Scacchiera.DIM_SCACCHIERA][Scacchiera.DIM_SCACCHIERA];
    } 
 
    /* Posiziona il pezzo p in posizione (i,j). 
    Se i e j non sono indici validi la scacchiera non viene modificata. 
    Se la posizione (i,j) è già occupata da un altro pezzo la scacchiera non viene modificata. 
    Se p è nullo la scacchiera non  viene  modificata. 
    Il  metodo  restituisce  true  se  il  posizionamento  è avvenuto con successo, false altrimenti */ 
    public boolean posizionaPezzo(int i, int j, Pezzo p){
        if(i < 0 || i>= Scacchiera.DIM_SCACCHIERA || j < 0 || j>= Scacchiera.DIM_SCACCHIERA){
            return false;
        }
        
        if(this.scacchiera[i][j] != null){
            return false;
        }
        
        return true;
    } 
 
    /* Restituisce true se il pezzo in posizione (i,j) è minacciato da un cavallo 
    di colore c, false altrimenti. 
    Un pezzo è minacciato da un cavallo se è di colore opposto a quello del cavallo 
    e si trova in una delle celle su cui il cavallo può portarsi con una mossa. 
    Se in posizione (i,j) non c'è un pezzo viene restituito false */ 
    public boolean minacciatoDaCavallo(int i, int j, char c){
        if(this.scacchiera[i][j] == null){
            return false;
        }

        int[][] posizioniCavalli = new int[8][2];
        int counter = 0;
        
        if(i - 2 > 0){
            if(j - 1 > 0){
                posizioniCavalli[counter][0] = i-2;
                posizioniCavalli[counter][1] = j-1;
                counter++;
            }
            if(j + 1 < Scacchiera.DIM_SCACCHIERA){
                posizioniCavalli[counter][0] = i-2;
                posizioniCavalli[counter][1] = j+1;
                counter++;
            }
        }

        if(i + 2 < Scacchiera.DIM_SCACCHIERA){
            if(j - 1 > 0){
                posizioniCavalli[counter][0] = i+2;
                posizioniCavalli[counter][1] = j-1;
                counter++;
            }
            if(j + 1 < Scacchiera.DIM_SCACCHIERA){
                posizioniCavalli[counter][0] = i-2;
                posizioniCavalli[counter][1] = j-1;
                counter++;
            }
        }
        
        if(j - 2 > 0){
            if(i - 1 > 0){
                posizioniCavalli[counter][0] = i-1;
                posizioniCavalli[counter][1] = j-2;
                counter++;
            }
            if(i + 1 < Scacchiera.DIM_SCACCHIERA){
                posizioniCavalli[counter][0] = i+1;
                posizioniCavalli[counter][1] = j-2;
                counter++;
            }
        }

        if(j + 2 < Scacchiera.DIM_SCACCHIERA){
            if(i - 1 > 0){
                posizioniCavalli[counter][0] = i-1;
                posizioniCavalli[counter][1] = j+2;
                counter++;
            }
            if(i + 1 < Scacchiera.DIM_SCACCHIERA){
                posizioniCavalli[counter][0] = i+1;
                posizioniCavalli[counter][1] = j+2;
                counter++;
            }
        }
        
        while(counter > 0){
            int x = posizioniCavalli[counter][0];
            int y = posizioniCavalli[counter][1];
            if(this.scacchiera[x][y].getTipo() == Pezzo.CAVALLO){
                if(this.scacchiera[x][y].getColore() != c){
                    return true;
                }    
            }
            counter--;
        }

        return false;
    } 
 
    /* Restituisce un array di pezzi che sono minacciati da almeno un cavallo 
    di colore c. Se nessun pezzo è minacciato da un cavallo di colore c viene 
    restituito un array di dimensione 0. */ 
    public Pezzo[] minacciatiDaCavalli(char c){
        ArrayList<Pezzo> temp = new ArrayList<Pezzo>();

        for(int i = 0; i < Scacchiera.DIM_SCACCHIERA; i++){
            for(int j = 0; j < Scacchiera.DIM_SCACCHIERA; j++){
                if(this.scacchiera[i][j] != null){
                    if(this.minacciatoDaCavallo(i, j, c)){
                        temp.add(this.scacchiera[i][j]);
                    }
                }
            }
        }
        if (temp.size() == 0){
            return new Pezzo[0];
        }
        
        Pezzo[] result = new Pezzo[temp.size()];
        Iterator<Pezzo> e = temp.listIterator();
        int counter = 0;

        while (e.hasNext()) {
            result[counter] = e.next();    
        }

        return result;
    } 
 
    /*  Restituisce  una  rappresentazione  testuale  della  scacchiera.  Per  ogni 
    cella occupata va indicato il tipo e il colore del pezzo che la occupa. */ 
    public String toString(){
        int counter = 0;

        String s = " a   b   c   d   e   f   g   h\n";
        for(int i = 0; i < Scacchiera.DIM_SCACCHIERA; i++){
            s += counter;
            for(int j = 0; j < Scacchiera.DIM_SCACCHIERA; j++){
                if (this.scacchiera[i][j] != null){
                    s += this.scacchiera[i][j].getTipo() + "-" + this.scacchiera[i][j].getColore() + " ";
                }else{
                    s += "    ";
                }
            }
            s += counter + "\n";
        }
        s += " a   b   c   d   e   f   g   h";
        return s;
    }
}

package esami.a;

public class Risultato{ 
    int golCasa, golFuori; 
  
    public Risultato(int golCasa, int golFuori){ 
        this.golCasa=golCasa; 
        this.golFuori=golFuori; 
    } 
 
public int getGolCasa(){ return golCasa;} 
 
public int getGolFuori(){ return golFuori;} 
 
public String toString(){ return golCasa+"-"+golFuori;}
 
}

package esami.C;

public class Punto {
    
    private double x = 0.0;
    private double y = 0.0;

    /*costruttore: crea un punto date le sue coordinate */
    public Punto (double x, double y){
        this.x = x;
        this.y = y;
    } 
    
    /*restituisce la coordinata x del punto  */
    public double coordX(){
        return this.x;
    } 
    
    /*restituisce la coordinata y del punto  */
    public double coordY(){
        return this.y;
    }
    
    /* restituisce una descrizione testuale del punto*/
    public String toString(){
        return "X: " + x + ", Y: " + y;
    }
}

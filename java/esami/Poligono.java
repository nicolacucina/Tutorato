package esami.C;
import java.lang.Math;
import java.util.ArrayList;

public class Poligono {
    private Punto[] vertici; // array dei vertici del poligono 
  
    /* Costruisce un poligono i cui vertici sono passati come 
    parametro. L’ordine del vertici nel contorno del poligono è dato 
    dall’ordine dei vertici nell’array. */  
    public Poligono(Punto[] vertici){
        this.vertici = new Punto[vertici.length];

        for(int i= 0; i<vertici.length; i++){
            this.vertici[i] = vertici[i];
        }
    } 
      
    /* Restituisce il valore della perimetro del poligono, cioè la 
    somma delle lunghezze dei suoi lati*/ 
    public double perimetro(){
        double result = 0.0;
        for(int i = 0; i < this.vertici.length - 1; i++){
            result += Math.sqrt(
                Math.pow(
                    (this.vertici[i].coordX() - this.vertici[i+1].coordX()), 2) + 
                Math.pow(
                    (this.vertici[i].coordY() - this.vertici[i+1].coordY()), 2)
                );
        }
        result += Math.sqrt(
                Math.pow(
                    (this.vertici[this.vertici.length - 1].coordX() - this.vertici[0].coordX()), 2) + 
                Math.pow(
                    (this.vertici[this.vertici.length - 1].coordY() - this.vertici[0].coordY()), 2)
                );
        return result;
    } 
  
    /* Restituisce il poligono costituito dai vertici del poligono 
    rappresentato dall’oggetto ricevente (this) che hanno coordinate 
    (x,y) tali che x>=x0 e y>=y0. Se nessuno dei vertici del’oggetto 
    ricevente soddisfa il criterio precedente, viene restituito null.*/ 
    public Poligono sottoPoligono(double x0, double y0){
        ArrayList<Punto> temp = new ArrayList<Punto>();
        for(int i=0; i< this.vertici.length; i++){
            if(this.vertici[i].coordX() >= x0 &&
            this.vertici[i].coordY() >= y0){
                temp.add(this.vertici[i]);
            }
        }

        System.out.println(temp);
        if(temp.size() == 0){
            return null;
        }

        Punto[] ciccio = new Punto[temp.size()];
        int counter = 0;
        for(Punto p: temp){
            ciccio[counter] = p;
            counter++;
        }
        return new Poligono(ciccio);
    } 
  
    /* Restituisce una descrizione testuale del poligono */ 
    public String toString(){
        String s = "";
        int counter = 0;
        for(int i = 0; i < this.vertici.length; i++){
            s += "Punto "+ counter +"- X: "+this.vertici[i].coordX() + ", Y: "+this.vertici[i].coordY()+"\n";
            counter++;
        }
        return s;
    }
}

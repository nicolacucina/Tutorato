package esami.f;

public class Punto {
    private double x, y;

    public Punto (double x, double y){
        this.x = x;
        this.y = y;
    }
    
    public double coordX (){return this.x;}
    public double coordY (){return this.y;}
    public String toString (){return "X: " + this.x + ", Y: "+ this.y;}

    @Override
    public int hashCode(){
        return (int)x * 31 + (int)y * 31;
    }

    @Override
    public boolean equals(Object obj){
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Punto other = (Punto) obj;
        if (this.x != other.coordX())
            return false;
        if (this.y != other.coordY())
            return false;
        return true;
    }
}

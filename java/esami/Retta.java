package esami.f;

public class Retta {
    private double m, q;

    public Retta (double m, double q){
        this.m = m;
        this.q = q;
    }

    public Retta (Punto p1, Punto p2){
        this.m = (p2.coordY() - p1.coordY())/(p2.coordX() - p1.coordX());
        this.q = (p2.coordX()*p1.coordY() - p1.coordX()*p2.coordY())/(p2.coordX() - p1.coordX());
    }

    public double getM(){return this.m;}
    public double getQ(){return this.q;}

    public Punto intersezione (Retta r){
        double x = (this.q - r.getQ())/(r.getM() - this.m);
        double y = this.m * x + this.q;
        return new Punto(x, y);
    }

    public String toString (){ return "y = " + this.m + "x + " + this.q;}

    @Override
    public int hashCode(){
        return (int)m * 31 + (int)q * 31;
    }

    @Override
    public boolean equals(Object obj){
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Retta other = (Retta) obj;
        if (this.m != other.getM())
            return false;
        if (this.q != other.getQ())
            return false;
        return true;
    }
}

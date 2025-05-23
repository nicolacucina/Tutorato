package esami.C;
import fond.io.InputWindow;

public class ProvaPoligono {
    public static void testMetodi(){
        Punto[] p = {
            new Punto(1.0, 3.0),
            new Punto(3.0, 5.0),
            new Punto(6.0, 4.0),
            new Punto(7.0, 2.0),
            new Punto(3.0, 1.0),
        };
        Poligono pp = new Poligono(p);
        
        System.out.println(pp);
        System.out.println(pp.perimetro());

        Poligono ppp = pp.sottoPoligono(1.0, 2.0);

        System.out.println(ppp.perimetro());
        System.out.println(ppp);
   
    }

    public static void main(String[] args) {
        testMetodi();

        InputWindow in = new InputWindow();
        int dim = in.readInt("inserire lunghezza array");
        Punto[] punti = new Punto[dim];
        double x = 0.0;
        double y = 0.0;
        for(int i=0; i< dim; i++){
            x = in.readDouble("inserire x");
            y = in.readDouble("inserire y");

            punti[i] = new Punto(x, y);
        }

        Poligono p = new Poligono(punti);
        System.out.println(p);

        boolean voglioContinuare = true;
        while (voglioContinuare) {
            double x0 = in.readDouble("inserire x0");
            double y0 = in.readDouble("inserire y0");
            
            System.out.println(p.sottoPoligono(x0, y0));
            
            boolean scelta = in.readBoolean("continuare?");
            if(!scelta){
                voglioContinuare = false;
            }
        }
    }
}

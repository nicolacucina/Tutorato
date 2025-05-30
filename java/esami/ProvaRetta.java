package esami.f;

import java.util.Set;

public class ProvaRetta {
    public static void main(String[] args) {
        Retta r1 = new Retta(2.0, 3.0);
        Retta r2 = new Retta(-1.0, 6.0);
        Retta r3 = new Retta(1.0, 7.0);
        Retta r4 = new Retta(-4.0, 2.0);
        Retta r5 = new Retta(-3.0, -4.0);
        Retta r6 = new Retta(12.1, 5.0);
        Retta r7 = new Retta(6.6, 5.0);
        Retta r8 = new Retta(1.0, 0.0);

        System.out.println(r1.intersezione(r2));
        InsiemeDiRette r = new InsiemeDiRette();
        r.aggiungi(r1);
        r.aggiungi(r2);
        r.aggiungi(r3);
        r.aggiungi(r4);
        r.aggiungi(r5);
        r.aggiungi(r6);
        r.aggiungi(r7);
        r.aggiungi(r8);

        Set<Punto> h = r.puntiDiIntersezione();
        for(Punto p: h){
            System.out.println(p);
        }

        Punto[] p = r.puntiEstremi();
        System.out.println("X min: " + p[0].coordX());
        System.out.println("X max: " + p[1].coordX());
        System.out.println("Y min: " + p[2].coordY());
        System.out.println("Y max: " + p[3].coordY());

    }
}

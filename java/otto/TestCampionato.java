package esami.a;

public class TestCampionato {
    public static void main(String[] args) {
        String[] s = {"Juventus", "Milan", "Inter"};
        Campionato c = new Campionato(s);
        c.memorizzaRisultato("Juventus", "Milan", new Risultato(2, 0));
        c.memorizzaRisultato("Juventus", "Inter", new Risultato(3, 1));
        c.memorizzaRisultato("Milan", "Juventus", new Risultato(1, 2));
        c.memorizzaRisultato("Milan", "Inter", new Risultato(0, 0));
        c.memorizzaRisultato("Inter", "Juventus", new Risultato(0, 3));
        c.memorizzaRisultato("Inter", "Milan", new Risultato(0, 2));

        System.out.println(c.toString());

        int[] result = c.calcolaPunti();
        int counter = 0;
        for(int i : result){
            System.out.println(s[counter] + "-" + i);
            counter++;
        }
    }
}

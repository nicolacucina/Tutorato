package esami.a;
import fond.io.InputWindow;

public class TestCampionato {

    public static void testMetodi(){
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
    public static void main(String[] args) {
        TestCampionato.testMetodi();

        InputWindow in = new InputWindow();
        int numeroSquadre = in.readInt("Inserire numero squadre");
        String[] squadre = new String[numeroSquadre];
        for(int i = 0; i < numeroSquadre; i++){
            squadre[i] = in.readString("Inserire una squadra");
        }

        Campionato c = new Campionato(squadre);

        String messaggio = "1- Inserisci risultato\n2- Mostra tabella\n3- Mostra punti in classifica\n4- Esci";
        boolean continua = true;
        int scelta;
        while(continua){
            scelta = in.readInt(messaggio);

            if(scelta == 1){
                int goalCasa = in.readInt("Inserire goal in casa");
                int goalFuori = in.readInt("Inserire goal fuori casa");

                String s1 = in.readString("Inserire squadra in casa");
                String s2 = in.readString("Inserire squadra fuori casa");
                c.memorizzaRisultato(s1, s2, new Risultato(goalCasa, goalFuori));
            }else if(scelta == 2){
                c.toString();
            }else if(scelta == 3){
                int[] result = c.calcolaPunti();
                for(int i = 0; i<result.length; i++){
                    System.out.println(squadre[i] + "-" + result[i]);
                }
            }else if(scelta == 4){
                continua = false;
            }
        }
    }
}

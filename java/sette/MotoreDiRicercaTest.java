package sette;

public class MotoreDiRicercaTest {
    public static void main(String[] args) {
        MotoreDiRicerca test = new MotoreDiRicerca();
        System.out.println(test.toString());
        System.out.println(test.toStringer());

        System.out.println(test.aggiungiParolaChiave("test"));
        System.out.println(test.toString());
        System.out.println(test.toStringer());

        System.out.println(test.aggiungiParolaChiave("ciao"));
        System.out.println(test.toString());
        System.out.println(test.toStringer());

        System.out.println(test.isParolaChiaveUtilizzata("ciao"));
        System.out.println(test.numeroParoleChiave());
        System.out.println(test.rimuoviParolaChiave("test"));
        System.out.println(test.toString());
}
}

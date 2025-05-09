package sette;

public class TestRicerca {
    public static void main(String[] args) {
        Ricerca r = new Ricerca(10000);
        System.out.println(r.ricercaSequenziale(32));
        System.out.println(r.ricercaBinaria(32));
        System.out.println(r.altraRicercaBinaria(32));
    }
}

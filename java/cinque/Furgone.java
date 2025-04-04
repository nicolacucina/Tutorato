package cinque;

public class Furgone extends Veicolo {
    private int capacitaMassima;

    public Furgone(String targa, String modello, int numeroPosti, int capacitaMassima) {
        super(targa, modello, numeroPosti);
        this.capacitaMassima = capacitaMassima;
    }

    public String toString() {
        return super.toString() + ", capacitaMassima=" + capacitaMassima;
    }
}

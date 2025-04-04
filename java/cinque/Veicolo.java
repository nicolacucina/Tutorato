package cinque;

public class Veicolo {
    private String targa;
    private String modello;
    private int numeroPosti;

    public Veicolo(String targa, String modello, int numeroPosti) {
        this.targa = targa;
        this.modello = modello;
        this.numeroPosti = numeroPosti;
    }

    public String getTarga() {
        return targa;
    }

    public String getModello() {
        return modello;
    }

    public int getNumeroPosti() {
        return numeroPosti;
    }

    public String toString() {
        return "Veicolo:" + "targa=" + targa + ", modello=" + modello + ", numeroPosti=" + numeroPosti;
    }
}

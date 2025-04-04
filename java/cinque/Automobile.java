package cinque;

public class Automobile extends Veicolo {
    private int numeroPorte;

    public Automobile(String targa, String modello, int numeroPosti, int numeroPorte) {
        super(targa, modello, numeroPosti);
        this.numeroPorte = numeroPorte;
    }

    public String toString() {
        return super.toString() + ", numeroPorte=" + numeroPorte;
    }
}

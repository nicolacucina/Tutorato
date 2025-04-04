package cinque.razze;

public class Elfo extends Razza {
    private String[] tratti;

    public Elfo() {
        super(0, 2, 5, 0, 1); // Forza, Intelligenza, Destrezza, Saggezza, Fortuna
        this.tratti = new String[3];
        setNome("Elfo");
        tratti[0] = "Visione Oscura";
        tratti[1] = "Sensi Acuti";
        tratti[2] = "Ascendente Fatato";
    }

    public String[] getTratti() {
        return tratti;
    }

    public String toString() {
        return super.toString() + ", Tratti: " + String.join(", ", tratti) + ", Descrizione: Gli elfi sono un popolo magico di grazia ultraterrena, che vive nel mondo ma non ne fa interamente parte";
    }
}

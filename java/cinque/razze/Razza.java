package cinque.razze;

public class Razza {
    private String nome;
    private int forza,  intelligenza,  destrezza, saggezza, fortuna;

    public Razza(int forza, int intelligenza, int destrezza, int saggezza, int fortuna) {
        this.nome = null;
        this.forza = forza;
        this.intelligenza = intelligenza;
        this.destrezza = destrezza;
        this.saggezza = saggezza;
        this.fortuna = fortuna;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getForza() {
        return forza;
    }

    public int getIntelligenza() {
        return intelligenza;
    }

    public int getDestrezza() {
        return destrezza;
    }

    public int getSaggezza() {
        return saggezza;
    }

    public int getFortuna() {
        return fortuna;
    }

    public String toString() {
        return "Razza di Default";
    }
}

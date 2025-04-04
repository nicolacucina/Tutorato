package cinque.classi;

import cinque.personaggi.Personaggio;

public class Classe {
    private String nome, specializzazione;
    private int forza,  intelligenza,  destrezza, saggezza, fortuna;

    public Classe(int forza, int intelligenza, int destrezza, int saggezza, int fortuna) {
        this.nome = null;
        this.specializzazione = null;
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

    public String getSpecializzazione() {
        return specializzazione;
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
        return "Razza: " + nome + ", Forza: " + forza + ", Intelligenza: " + intelligenza +
               ", Destrezza: " + destrezza + ", Saggezza: " + saggezza + ", Fortuna: " + fortuna;
    }
    
    public void aumentaLivello(Personaggio personaggio){
        personaggio.setLivello(personaggio.getLivello() + 1);
    }

    public void aumentaLivello(Personaggio personaggio, int livello){
        personaggio.setLivello(livello);
    }
}
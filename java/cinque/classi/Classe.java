package cinque.classi;

import cinque.personaggi.Personaggio;

public class Classe {
    /*
     * Qua vengono creati tutti i paramentri e i metodi di appoggio(get, set, toString) che verranno utilizzati
     * e specializzati nelle classi estese
     */
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

    public void setSpecializzazione(String s){
        this.specializzazione = s;
    }

    public int getForza() {
        return forza;
    }

    public void setForza(int forza) {
        this.forza = forza;
    }

    public int getIntelligenza() {
        return intelligenza;
    }

    public void setIntelligenza(int intelligenza) {
        this.intelligenza = intelligenza;
    }

    public int getDestrezza() {
        return destrezza;
    }

    public void setDestrezza(int destrezza) {
        this.destrezza = destrezza;
    }

    public int getSaggezza() {
        return saggezza;
    }

    public void setSaggezza(int saggezza) {
        this.saggezza = saggezza;
    }

    public int getFortuna() {
        return fortuna;
    }

    public void setFortuna(int fortuna) {
        this.fortuna = fortuna;
    }

    public String toString() {
        return "Classe di Default";
    }
    
    /*
     * Dato che questa è la Classe senza alcun dettaglio relativo, l'unica cosa che possiamo fare
     * è aumentare il livello del personaggio, sarà poi la classe specifica a definire come aumentare le statistiche
     */
    public void aumentaLivello(Personaggio personaggio){
        personaggio.setLivello(personaggio.getLivello() + 1);
    }

    public void aumentaLivello(Personaggio personaggio, int livello){
        personaggio.setLivello(personaggio.getLivello() + livello);
    }
}
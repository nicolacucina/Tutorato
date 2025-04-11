package cinque.personaggi;
import cinque.razze.Razza;
import cinque.classi.Classe;

public class Personaggio {
    private String nome;
    private Razza razza;
    private Classe classe;
    private int livello;
    private int forza;
    private int intelligenza;
    private int destrezza;
    private int saggezza;
    private int fortuna;

    public Personaggio(String nome, Razza razza, Classe classe) {
        this.nome = nome;
        this.razza = razza;
        this.classe = classe;
        this.livello = 1; // Livello iniziale
        this.forza = razza.getForza() + classe.getForza();
        this.destrezza = razza.getDestrezza() + classe.getDestrezza();
        System.out.println(razza.getDestrezza() + " " + classe.getDestrezza());
        this.intelligenza = razza.getIntelligenza() + classe.getIntelligenza();
        this.saggezza = razza.getSaggezza() + classe.getSaggezza();
        this.fortuna = razza.getFortuna() + classe.getFortuna();
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Razza getRazza() {
        return razza;
    }

    public void setRazza(Razza razza) {
        this.razza = razza;
    }

    public Classe getClasse() {
        return classe;
    }

    public void setClasse(Classe classe) {
        this.classe = classe;
    }

    public int getLivello() {
        return livello;
    }

    public void setLivello(int livello) {
        this.livello = livello;
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
        return "Personaggio: " + nome + ", Razza: " + razza.getNome() + ", Classe: " + classe.getNome() +
               ", Livello: " + livello + ", Forza: " + forza + ", Intelligenza: " + intelligenza +
                ", Destrezza: " + destrezza + ", Saggezza: " + saggezza + ", Fortuna: " + fortuna;
    }

    public void aumentaLivello() {
        this.classe.aumentaLivello(this);
    }

    public void aumentaLivello(int i){
        this.classe.aumentaLivello(this, i);
    }

}

package cinque.classi;

import cinque.personaggi.Personaggio;

public class Ferale extends Druido{
    private String abilita;

    public Ferale(){
        super();
        /*
         * Ferale è una specializzazione di Druido, è necessario modificare le statistiche della classe Druido
         * Gli incrementi sono relativi alla classe Druido e i suoi valori base:
         * Forza -1, Intelligenza 2, Destrezza 0, Saggezza 2, Fortuna 0
         * Perciò Ferale avrà:
         * Forza 1, Intelligenza 0, Destrezza 2, Saggezza 1, Fortuna 1
        */ 
        this.setForza(getForza() + 2);
        this.setIntelligenza(getIntelligenza() -2);
        this.setDestrezza(getDestrezza() +2);
        this.setSaggezza(getSaggezza() - 1);
        this.setFortuna(getFortuna() + 1);
        setSpecializzazione("Ferale");
        this.abilita = "Puoi usare la tua azione per assumere magicamente la forma di una bestia che hai già visto";
    }

    public String getAbilita() {
        return abilita;
    }

    /*
     * Nell'esempio è mostrato come variano le statistiche per la specializzazione Ferale, quindi possiamo scrivere gli incrementi
     */
    public void aumentaLivello(Personaggio personaggio){
        super.aumentaLivello(personaggio);
        personaggio.setForza(personaggio.getForza() + 2);
        personaggio.setDestrezza(personaggio.getDestrezza() + 2);
    }

    public void aumentaLivello(Personaggio personaggio, int livello){
        super.aumentaLivello(personaggio, livello);
        personaggio.setForza(personaggio.getForza() + 2 * livello);
        personaggio.setDestrezza(personaggio.getDestrezza() + 2 * livello);
    }

    public String toString() {
        return super.toString() + "Ferale: " + "abilita=" + abilita;
    }
    
}

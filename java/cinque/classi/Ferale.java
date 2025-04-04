package cinque.classi;

public class Ferale extends Druido{
    private String abilita;

    public Ferale(String abilita){
        super();
        setNome("Ferale");
        this.abilita = abilita;
    }

    public String getAbilita() {
        return abilita;
    }

    public String toString() {
        return super.toString() + "Ferale: " + "abilita=" + abilita;
    }
    
}

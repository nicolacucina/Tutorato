package cinque.classi;

import cinque.personaggi.Personaggio;

public class Druido extends Classe{

    public Druido(){
        super(-1, 2, 0, 2, 0); // settiamo le statistiche come nell'esempio
        setNome("Druido"); // erediamo il metodo dalla classe genitore Classe
    }
    
    /* 
     * Nell'esempio non è specificato come fare l'aumento di livello per la sola classe Druido, 
     * quindi non vengono incrementate le statistiche
    */ 
    public void aumentaLivello(Personaggio personaggio){
        super.aumentaLivello(personaggio);
    }

    public void aumentaLivello(Personaggio personaggio, int livello){
        super.aumentaLivello(personaggio, livello);
    }
    
    public String toString() {
        return "I druidi venerano soprattutto la natura, ottenendo i loro incantesimi e altri poteri magici dalla forza della natura.";
    }
}

package cinque.classi;

import cinque.personaggi.Personaggio;

public class Druido extends Classe{

    public Druido(){
        super(-1, 2, 0, 2, 0);

    }

    public void aumentaLivello(Personaggio personaggio){
        personaggio.setLivello(personaggio.getLivello() + 1);
        personaggio.setForza(personaggio.getForza() + 2);
        personaggio.setDestrezza(personaggio.getDestrezza() + 2);
    }

    public void aumentaLivello(Personaggio personaggio, int livello){
        personaggio.setLivello(personaggio.getLivello() + livello);
        personaggio.setForza(personaggio.getForza() + 2 * livello);
        personaggio.setDestrezza(personaggio.getDestrezza() + 2 * livello);
    }
    
}

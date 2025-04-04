package cinque;
import cinque.classi.Classe;
import cinque.classi.Druido;
import cinque.classi.Ferale;
import cinque.razze.Razza;
import cinque.razze.Elfo;
import cinque.personaggi.Personaggio;


public class CreazionePersonaggio {
    public static void main(String[] args) {
        Razza razza = new Razza(1, 2, 3, 4, 5);
        Classe classe = new Classe(1, 2, 3, 4, 5);
        Personaggio personaggio = new Personaggio("giocatore", razza, classe);

        System.out.println("Personaggio creato: " + personaggio.toString());

        Razza elfo = new Elfo();
        System.out.println("Razza elfo: " + elfo.toString());

        Classe druidoFerale = new Ferale("Puoi usare la tua azione per assumere magicamente la forma di una bestia che hai già visto");
        System.out.println("Classe druido ferale: " + druidoFerale.toString());
        Personaggio personaggio2 = new Personaggio("giocatore2", elfo, druidoFerale);
        System.out.println("Personaggio creato: " + personaggio2.toString());
    }
}

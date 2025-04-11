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

        System.out.println("Personaggio base: " + personaggio.toString());

        Razza elfo = new Elfo();
        System.out.println("Razza elfo: " + elfo.toString());

        Classe druido = new Druido();

        Classe druidoFerale = new Ferale();
        System.out.println("Classe druido ferale: " + druidoFerale.toString());

        Personaggio elfo_druido = new Personaggio("giocatore", elfo, druido);
        System.out.println("Elfo Druido creato: " + elfo_druido.toString());

        Personaggio elfo_druifo_ferale = new Personaggio("giocatore2", elfo, druidoFerale);
        System.out.println("Elfo Druido Ferale creato: " + elfo_druifo_ferale.toString());

        elfo_druifo_ferale.getClasse().aumentaLivello(elfo_druifo_ferale);
        System.out.println("Personaggio dopo aumento di livello: " + elfo_druifo_ferale.toString());

        elfo_druifo_ferale.getClasse().aumentaLivello(elfo_druifo_ferale, 3);
        System.out.println("Personaggio dopo aumento di 3 livelli: " + elfo_druifo_ferale.toString());
    }
}

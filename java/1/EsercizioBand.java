import classi.Band;
import classi.Musicista;
import fond.io.InputWindow;
import fond.io.OutputWindow;

public class EsercizioBand {
    public static void main(String[] args) {
        InputWindow in = new InputWindow();
        OutputWindow out = new OutputWindow();

        // Chiede 5 volte all’utente di inserire il nome e lo strumento di un musicista
        /*
            voce
            batteria
            tastiera
            chitarra
            basso
        */
        Musicista m1 = new Musicista(in.readString("Inserire nome musicista 1"), in.readString("Inserire strumento musicista 1"));
        Musicista m2 = new Musicista(in.readString("Inserire nome musicista 2"), in.readString("Inserire strumento musicista 2"));
        Musicista m3 = new Musicista(in.readString("Inserire nome musicista 3"), in.readString("Inserire strumento musicista 3"));
        Musicista m4 = new Musicista(in.readString("Inserire nome musicista 4"), in.readString("Inserire strumento musicista 4"));
        Musicista m5 = new Musicista(in.readString("Inserire nome musicista 5"), in.readString("Inserire strumento musicista 5"));

        // Crea una band i cui componenti sono i 5 musicisti inseriti
        // Chiede all’utente il nome della band e lo imposta
        Band band = new Band(in.readString("Inserire nome band"), m1, m2, m3, m4, m5);

        // Stampa la descrizione della band
        out.writeln(band.toString());

        // Chiede all’utente il nome di un nuovo musicista e il suo strumento
        Musicista m6 = new Musicista(in.readString("Inserire nome musicista 6"), in.readString("Inserire strumento musicista 6"));
        
        // Modifica la band inserendo il nuovo musicista
        band.setMusicista(m6);
        
        // Stampa la descrizione della band
        out.writeln(band.toString());
    }
}

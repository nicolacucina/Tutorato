import fond.io.InputWindow;
import fond.io.OutputWindow;
import classi.Rettangolo;

public class EsercizioRettangolo {
    public static void main(String[] args) {
        InputWindow in = new InputWindow();
        OutputWindow out = new OutputWindow();

        // Fa inserire all'utente la base, l'altezza, l'ascissa e l'ordinata di un rettangolo
        int base = in.readInt("Inserire la base del rettangolo");
        int altezza = in.readInt("Inserire l'altezza del rettangolo");
        int ascissa = in.readInt("Inserire l'ascissa del rettangolo");
        int ordinata = in.readInt("Inserire l'ordinata del rettangolo");

        // Crea un rettangolo con i valori inseriti
        Rettangolo rettangolo = new Rettangolo(base, altezza, ascissa, ordinata);

        // Visualizza il rettangolo
        out.writeln(rettangolo.toString());

        // Calcola perimetro ed area del rettangolo e li visualizza
        out.writeln("Perimetro: " + rettangolo.getPerimetro());
        out.writeln("Area: " + rettangolo.getArea());

        
        // Chiede all'utente di quanto vuole traslare l'ascissa e l'ordinata del rettangolo
        int trX = in.readInt("Di quanto vuoi traslare l'ascissa?");
        int trY = in.readInt("Di quanto vuoi traslare l'ordinata?");

        // Trasla il rettangolo
        rettangolo.traslazione(trX, trY);
        
        // Visualizza il rettangolo 
        rettangolo.toString();
    }
}

import classi.ContoCorrente;
import fond.io.InputWindow;
import fond.io.OutputWindow;

public class EsercizioContoCorrente {

    public static void main(String[] args){
        InputWindow in = new InputWindow();
        OutputWindow out = new OutputWindow();

        // - Fa inserire all’utente una password per il suo conto corrente
        String password = in.readString("Inserire Password");

        // - Crea un conto corrente con saldo iniziale pari a zero e visualizza il messaggio "Conto corrente creato con successo"
        ContoCorrente mioContoCorrente = new ContoCorrente(password);
        out.writeln("Conto corrente creato");

        // - Chiede all’utente quanto vuole versare e la password
        double versamento = in.readDouble("Quanto vuoi versare?");
        String passwordVersamento = in.readString("Inserire Password");

        // - Effettua un versamento
        String risultato = mioContoCorrente.deposita(versamento, passwordVersamento);
        out.writeln(risultato);

        // - Visualizza il saldo con un opportuno messaggio
        out.writeln("Saldo: " + mioContoCorrente.leggiSaldo());

        // - Chiede all’utente quanto vuole prelevare e la password
        double prelievo = in.readDouble("Quanto vuoi prelevare?");
        String passwordPrelievo = in.readString("Inserire Password");

        // - Effettua un prelievo
        risultato = mioContoCorrente.preleva(prelievo, passwordPrelievo);
        out.writeln(risultato);

        // - Visualizza il saldo con un opportuno messaggio
        out.writeln("Saldo: " + mioContoCorrente.leggiSaldo());

        // - Chiede all’utente quanto è il tasso di interesse
        double interesse = in.readDouble("Quanto è il tasso di interesse?");

        // - Aggiunge l’interesse
        mioContoCorrente.aggiungiInteresse(interesse);

        // - Visualizza il saldo con un opportuno messaggio
        out.writeln("Saldo: " + mioContoCorrente.leggiSaldo());
    }
}

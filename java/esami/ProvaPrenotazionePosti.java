package esami.g;
import java.util.List;


public class ProvaPrenotazionePosti {
    public static void main(String[] args) {
        PrenotazionePosti p = new PrenotazionePosti();
        List<Posto> result = p.prenotaPostiInFila('A', 5);
        for(Posto pp: result){
            System.out.println(pp);
        }
    }
}

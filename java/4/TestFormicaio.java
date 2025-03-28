package quattro;
import fond.io.InputWindow;
import fond.io.OutputWindow;

public class TestFormicaio {
    public static void main(String[] args) { 
        InputWindow in = new InputWindow(); 
        OutputWindow out = new OutputWindow();
         
        int dim = in.readInt("Inserisci la dimensione del formicaio"); 
        Formicaio formicaio = new Formicaio(dim); 
        out.writeln(formicaio); 
        
        char scelta = in.readChar("Vuoi aggiungere una formica al formicaio? (s=si')"); 
        while (scelta=='s'){ 
            int i = in.readInt("Inserisci l'indice di riga della posizione della formica"); 
            int j = in.readInt("Inserisci l'indice di colonna della posizione della formica"); 
            if (formicaio.aggiungiFormica(i,j)) 
                out.writeln("La formica e' stata inserita"); 
            else 
                out.writeln("La formica NON e' stata inserita"); 
            out.writeln(formicaio); 
            if (Formica.getLastId()==10) 
                scelta = 'n'; 
            else 
                scelta = in.readChar("Vuoi aggiungere una formica al formicaio? (s=si')"); 
        } 
        char muovi = in.readChar("Vuoi far muovere una formica? (s=si')"); 

        while (muovi=='s'){ 
            int id = in.readInt("Inserisci l'id della formica che vuoi muovere"); 
            int direzione = in.readInt("Inserisci la direzione in cui si deve muovere la formica (1=NORD, 2=OVEST, 3=SUD, 4=EST)"); 
            while (direzione<1 || direzione>4){ 
                direzione = in.readInt("Direzione sbagliata. Riprova. (1=NORD, 2=OVEST, 3=SUD, 4=EST)"); 
            } 
            if (formicaio.muoviFormica(direzione,id)) 
                out.writeln("Mossa effettuata"); 
            else out.writeln("Mossa non valida"); 
            out.writeln(formicaio); 
            muovi = in.readChar("Vuoi far muovere una formica? (s=si')"); 
        } 
    }
}

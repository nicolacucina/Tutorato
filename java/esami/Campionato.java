package esami.a;

public class Campionato { 
  
    private String[] squadre; // Elenco delle squadre 
    private Risultato[][] risultati; // Tabella dei risultati 
 
    /*  Crea  un  oggetto  Campionato  per l’elenco di squadre  passato  come  parametro.  I  risultati  sono 
    inizializzati con il valore null. */ 
    public Campionato (String[] squadre){
        this.squadre = new String[squadre.length];
        
        for(int i = 0; i < squadre.length; i++){
            this.squadre[i] = squadre[i];
        }

        this.risultati = new Risultato[squadre.length][squadre.length];
    }

    /* restituisce l’array delle squadre. */ 
    public String[] getSquadre(){
        return this.squadre;
    } 
 
    /* Registra il risultato ris dell’incontro tra la squadra sq1 e la squadra sq2 (con la sq1 che giocava in 
    casa). Se sq1 oppure sq2 non compaiono nell’elenco delle squadre, la tabella non viene modificata. 
    */ 
    public void memorizzaRisultato (String sq1, String sq2, Risultato ris){
        int a = -1;
        int b = -1;

        for(int i = 0; i < this.squadre.length; i++){
            if (this.squadre[i].equals(sq1)) {
                a = i;
            }
            if (this.squadre[i].equals(sq2)) {
                b = i;
            }
        }
        if (a >= 0 && b >= 0){
            this.risultati[a][b] = ris;
        }
    } 
 
    /* Restituisce i punti in classifica delle diverse squadre. Più precisamente, l’elemento i-esimo 
    dell’array risultato memorizza il numero di punti in classifica delle squadra i-esima come si ottiene 
    dai risultati memorizzati nella tabella dei risultati. A tal fine si ricorda che per ogni pareggio si 
    ottiene un punto e per ogni vittoria si ottengono tre punti. */ 
    public int[] calcolaPunti(){
        int[] result = new int[this.squadre.length];
        for(int i = 0; i < this.risultati.length; i++){
            result[i] = 0;
        }

        for(int i = 0; i < this.risultati.length; i++){
            for(int j = 0; j < this.risultati[i].length; j++){
                if(this.risultati[i][j] == null){
                    continue;
                }

                if(this.risultati[i][j].getGolCasa() > this.risultati[i][j].getGolFuori()){
                    result[i] += 3;
                }else if(this.risultati[i][j].getGolCasa() < this.risultati[i][j].getGolFuori()){
                    result[j] += 3;
                }else{
                    result[i] += 1;
                    result[j] += 1;
                }
            }
        }
        return result;
    } 
 
    /* Restituisce una rappresentazione testuale della tabella. Tale rappresentazione deve mostrare i 
    risultati e i nomi delle squadre alle intestazioni di riga e colonna (si veda l’esempio più avanti) */ 
    public String toString(){
        String s = "\t";
        for(int i = 0; i < this.squadre.length; i++){
            s += this.squadre[i] + "\t";
        }

        s += "\n";
        
        for(int i = 0; i < this.risultati.length; i++){
            s += this.squadre[i] + "\t";
            for(int j = 0; j < this.risultati[i].length; j++){
                if(this.risultati[i][j] == null){
                    s += "\t";
                }else{
                    s += this.risultati[i][j].toString() + "\t";
                }
            }
            s += "\n";
        }
        return s;
    } 
} 
